
#include "n_spe.h"

#pragma unmanaged
const char* cspe::bpe_filename_left;
const char* cspe::bpe_filename_right;

long cspe::offset_x = 0;
long cspe::offset_y = 0;

long cspe::step_x = 1;
long cspe::step_y = 1;

double cspe::S = 0.0;

sspe* cspe::left_image;
sspe* cspe::right_image;
long cspe::sizex = 0;
long cspe::sizey = 0;

float* cspe::left_image_ups;
float* cspe::right_image_ups;
long cspe::sizex_ups = 0;
long cspe::sizey_ups = 0;

float* cspe::image;

float cspe::dr_low = 0.83f;
float cspe::dr_high = 1.3f;
float cspe::dr_step = 0.01f;

int cspe::cur_pair;

int cspe::mode = 0;
int cspe::op = 0;
int cspe::ups = 1;
int cspe::scale = 1;
float cspe::dr_low_AdB = 0.83f;
float cspe::dr_high_AdB = 1.3f;

float cspe::dr_low_AmBdApB = -0.1f;
float cspe::dr_high_AmBdApB = 0.1f;

float cspe::llmn = 0.0f;
float cspe::rrmn = 0.0f;
float cspe::llsd = 0.0f;
float cspe::rrsd = 0.0f;

int cspe::file_loader(const char* name, char** file)
{
	FILE* fl;
	fl = fopen(name, "rb");

	fseek(fl, 0L , SEEK_END);
	long len = ftell(fl);
	rewind(fl);
	char *buff = (char*)malloc(len);
	long success = fread(buff, 1, len, fl);
	if (success != len) return 1;
	*file = buff;
	fclose(fl);
	return 0;
}

int cspe::process(const char* namel, const char* namer)
{
	free(left_image);
	free(right_image);
	free(image);
	free(left_image_ups);
	free(right_image_ups);

	// Load left image
	if (file_loader(namel, (char**)&left_image) != 0) return 1;
	// Load right image
	if (file_loader(namer, (char**)&right_image) != 0) return 1;

	if (left_image->sizex == right_image->sizex) sizex = right_image->sizex;
	else return 1;

	if (left_image->sizey == right_image->sizey) sizey = right_image->sizey;
	else return 1;

	if (ups == 1)
	{
		supsample(left_image, (float**)&left_image_ups);
		supsample(right_image, (float**)&right_image_ups);
	}
	else
	{
		tofloat(left_image, (float**)&left_image_ups);
		tofloat(right_image, (float**)&right_image_ups);
	}
	long size_b = sizex_ups * sizey_ups * sizeof(float);
	image = (float*)malloc(size_b);
	overlap();

	return 0;
}

int cspe::upsample()
{
	return 0;
}

int cspe::supsample(sspe* in, float** out)
{
	long size;
	long size_ups;
	//processing images based on the data format
	//Left
	size = in->sizex * in->sizey;
	size_ups = size * 4;

	long tsizex = in->sizex;
	long tsizey = in->sizey;

	long tsizex_ups = 2 * tsizex;
	long tsizey_ups = 2 * tsizey;

	sizex_ups = tsizex_ups;
	sizey_ups = tsizey_ups;

	long size_ups_b = 0;
	size_ups_b = size_ups * sizeof(float); // x4 upsamplig
	float *buff = (float*)malloc(size_ups_b);

	if(in->dtype == 0)
	{
		 // float 4 bytes	
		float *sped = (float*)&in->data;
		for (long j = 0; j < tsizey; j++)
		{
			for (long i = 0; i < tsizex; i++)
			{
				long si = j * tsizey + i;
				long li = 2 * j * tsizey_ups + 2 * i;
				long lin = li + tsizey_ups;

				float val = sped[si];
				buff[li] = val;
				buff[li+1] = val;
				buff[lin] = val;
				buff[lin+1] = val;
			}
		}
	}
	if(in->dtype == 1)
	{
		// long 4 bytes
		long *sped = (long*)&in->data;
		for (long j = 0; j < tsizey; j++)
		{
			for (long i = 0; i < tsizex; i++)
			{
				long si = j * tsizey + i;
				long li = 2 * j * tsizey_ups + 2 * i;
				long lin = li + tsizey_ups;

				float val = (float)sped[si];
				buff[li] = val;
				buff[li+1] = val;
				buff[lin] = val;
				buff[lin+1] = val;
			}
		}
	}
	if(in->dtype == 2)
	{
		// short 2 bytes
		WORDS *sped = (WORDS*)&in->data;
		for (long j = 0; j < tsizey; j++)
		{
			for (long i = 0; i < tsizex; i++)
			{
				long si = j * tsizey + i;
				long li = 2 * j * tsizey_ups + 2 * i;
				long lin = li + tsizey_ups;

				float val = (float)sped[si];
				buff[li] = val;
				buff[li+1] = val;
				buff[lin] = val;
				buff[lin+1] = val;
			}
		}
	}
	if(in->dtype == 3)
	{
		//unsigned short
		UWORDS *sped = (UWORDS*)&in->data;
		for (long j = 0; j < tsizey; j++)
		{
			for (long i = 0; i < tsizex; i++)
			{
				long si = j * tsizey + i;
				long li = 2 * j * tsizey_ups + 2 * i;
				long lin = li + tsizey_ups;

				float val = (float)sped[si];
				buff[li] = val;
				buff[li+1] = val;
				buff[lin] = val;
				buff[lin+1] = val;
			}
		}
	}
	*out = buff;

	return 0;
}

int cspe::overlap()
{
	if (mode != 0) return 0;
	
#pragma omp parallel for
	for (long j = 0; j < sizey_ups; j++)
	{
		for (long i = 0; i < sizex_ups; i++)
		{
			long sxl = p_xy_v1(i, j, sizex_ups, sizey_ups);
			long sxr = p_xy_v1_s(i + offset_x, j + offset_y, sizex_ups, sizey_ups);

			if (sxr == -1)
			{
				image[sxl] = 0.0f;
				continue;
			}

			float vl = left_image_ups[sxl];
			float vr = right_image_ups[sxr];
			switch(op)
			{
			case 0:
				vl /= vr;
				break;
			case 1:
				vl -= vr;
				break;
			case 2:
				vl *= vr;
				break;
			case 3:
				vl += vr;
				break;
			case 4:
				vl = (vl-vr)/(vl+vr);
				break;
			}
			image[sxl] = vl;
		}
	}
	return 0;
}

int cspe::map_to_bitmap(unsigned char* imdata, int stride)
{
	float* buffer;
	float norma = 1.0;
	switch (mode)
	{
	case 0:
		buffer = image;
		break;
	case 1:
		buffer = left_image_ups;
		norma = 1.0f / vmaximum(buffer, sizex_ups * sizey_ups);
		break;
	case 2:
		buffer = right_image_ups;
		norma = 1.0f / vmaximum(buffer, sizex_ups * sizey_ups);
		break;
	}
	//float spow = (float)scale;
	//float spown = 1.0f/(spow-1.0);

	

	if (mode == 0)
	{
		int threads = 0;
#pragma omp parallel
	{
#pragma omp sections
		{
#pragma omp section
			{
				threads = omp_get_num_threads();
			}
		}
	}

		float *rs = new float[2*threads];

		float zero = 1.0;
		if (op == 4) zero = 0.0;
		float mxv = abs(dr_high - zero);
		float mnv = abs(dr_low - zero);
		float mx = (mxv>mnv)?mxv:mnv;
#pragma omp parallel for
		for (long j = 0; j < sizey_ups; j++)
		{
			int thread = omp_get_thread_num();
			float *rst = &rs[2*thread];
			for (long i=0; i < sizex_ups; i++)
			{
				long ii = p_xy_v1(i,j,sizex_ups, sizey_ups);
				long jj = 3 * p_xy_v1(i,j,stride/3, sizey_ups);
				float val = buffer[ii];
				unsigned char cval;
				unsigned char rval;
				unsigned char bval;

				switch(scale)
				{
				case 1:
					val = clamp(val, dr_low, dr_high);
					cval = (unsigned char)255.0 * val;//(powf(spow,val)-1.0)*spown;
					imdata[jj] = cval;
					imdata[jj+1] = cval;
					imdata[jj+2] = cval;
					break;
				case 2:
					clampU(val, dr_low, dr_high, mx, zero, &rst);
					rval = (unsigned char)255.0 * rst[0];
					bval = (unsigned char)255.0 * rst[1];
					imdata[jj] = rval;
					imdata[jj+1] = 0;
					imdata[jj+2] = bval;
				break;
				}
			}
		}
	}
	else
	{
		for (long j = 0; j < sizey_ups; j++)
		{
			for (long i=0; i < sizex_ups; i++)
			{
				long ii = p_xy_v1(i,j,sizex_ups, sizey_ups);
				long jj = 3 * p_xy_v1(i,j,stride/3, sizey_ups);
				float val = buffer[ii] * norma;	
				unsigned char cval = (unsigned char)255.0 * val; 
				imdata[jj] = cval;
				imdata[jj+1] = cval;
				imdata[jj+2] = cval;
			}
		}
	}
	return 0;
}

float cspe::vmaximum(float* buffer, long size)
{
	float vl = buffer[0];

	for (long i = 1; i < size; i++)
	{
		float tvl = buffer[i];
		if (tvl > vl) vl = tvl;
	}
	return vl;
}

int cspe::spe_save(const char* name)
{
	// Allocate memory for the new SPE
	// 4100 bytes for header and sizex_ups * sizey_ups * sizeof(float) for data

	size_t datasize = sizex_ups * sizey_ups * sizeof(float);
	size_t allocs = SPEHEADER + datasize;
	unsigned char* tspe = (unsigned char*)malloc(allocs);
	// Copy header from the loaded images
	memcpy((void *)tspe, (void *)left_image, SPEHEADER);
	// Copy the data
	memcpy(&tspe[SPEHEADER], (void*)image, datasize);
	// change the size
	sspe* tsspe = (sspe*)tspe;
	tsspe->sizex = sizex_ups;
	tsspe->sizey = sizey_ups;
	tsspe->dtype = 0; //float data type
	FILE* sf;
	sf = fopen(name, "wb");
	rewind(sf);
	fwrite(tspe, 1, allocs, sf);
	fclose(sf);
	return 0;
}

int cspe::tofloat(sspe* in, float** out)
{
	long size;
	long size_ups;
	//processing images based on the data format
	//Left
	size = in->sizex * in->sizey;


	long tsizex = in->sizex;
	long tsizey = in->sizey;

	long tsizex_ups = tsizex;
	long tsizey_ups = tsizey;

	sizex_ups = tsizex_ups;
	sizey_ups = tsizey_ups;

	size_ups = sizex_ups * sizey_ups;

	long size_ups_b = 0;
	size_ups_b = size_ups * sizeof(float); // x4 upsamplig
	float *buff = (float*)malloc(size_ups_b);

	if(in->dtype == 0)
	{
		 // float 4 bytes	
		float *sped = (float*)&in->data;
		for (long j = 0; j < tsizey; j++)
		{
			for (long i = 0; i < tsizex; i++)
			{
				long si = j * tsizey + i;
				float val = sped[si];
				buff[si] = val;
			}
		}
	}
	if(in->dtype == 1)
	{
		// long 4 bytes
		long *sped = (long*)&in->data;
		for (long j = 0; j < tsizey; j++)
		{
			for (long i = 0; i < tsizex; i++)
			{
				long si = j * tsizey + i;
				long li = 2 * j * tsizey_ups + 2 * i;
				long lin = li + tsizey_ups;

				float val = (float)sped[si];
				buff[si] = val;
			}
		}
	}
	if(in->dtype == 2)
	{
		// short 2 bytes
		WORDS *sped = (WORDS*)&in->data;
		for (long j = 0; j < tsizey; j++)
		{
			for (long i = 0; i < tsizex; i++)
			{
				long si = j * tsizey + i;
				long li = 2 * j * tsizey_ups + 2 * i;
				long lin = li + tsizey_ups;

				float val = (float)sped[si];
				buff[si] = val;
			}
		}
	}
	if(in->dtype == 3)
	{
		//unsigned short
		UWORDS *sped = (UWORDS*)&in->data;
		for (long j = 0; j < tsizey; j++)
		{
			for (long i = 0; i < tsizex; i++)
			{
				long si = j * tsizey + i;
				long li = 2 * j * tsizey_ups + 2 * i;
				long lin = li + tsizey_ups;

				float val = (float)sped[si];
				buff[si] = val;
			}
		}
	}
	*out = buff;

	return 0;
}

int cspe::getEntropy()
{
	long* hystogram = new long[INTERVALS];
	for (int i = 0; i < INTERVALS; i++) hystogram[i] = 0L;

	long size = sizex_ups * sizey_ups;
	double isize = 1.0/(double)size;
	for (int i = 0; i < size; i++)
	{
		int val = (INTERVALS - 1) * clamp(image[i], dr_low, dr_high);
		hystogram[val]++;
	}

	double _S = 0;
	for (int i = 0; i < INTERVALS; i++)
	{
		double p = (double)hystogram[i]*isize;
		if (p != 0.0f) _S += p * log(p);
	}

	S = -_S;

	delete[] hystogram;

	return 0;
}

int cspe::doAutoOverlap()
{
	int found = 1;
	double _S = 0;

	int X[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
	int Y[8] = {-1, -1, -1, 0, 0, 1, 1, 1};

	double aS[8];

	while(found)
	{
		overlap();
		getEntropy();
		_S = S;

		for (int i = 0; i < 8; i++)
		{
			int _offset_x = offset_x;
			int _offset_y = offset_y;

			offset_x = offset_x + X[i];
			offset_y = offset_y + Y[i];
			overlap();

			getEntropy();
			aS[i] = S - _S;

			offset_x = _offset_x;
			offset_y = _offset_y;
		}

		//test local minima
		double sign = 0.125f * (aS[0]/abs(aS[0]) + aS[1]/abs(aS[1]) + aS[2]/abs(aS[2]) + aS[3]/abs(aS[3]) +
			aS[4]/abs(aS[4]) + aS[5]/abs(aS[5]) + aS[6]/abs(aS[6]) + aS[7]/abs(aS[7]));

		if (sign >= 0.95) 
		{
			found = 0;
			break;
		}

		int pos = 0;
		double Smin = aS[pos];
		
		for (int i = 1; i < 8; i++)
		{
			double tSmin = aS[i];

			if (tSmin < Smin)
			{
				Smin = tSmin;
				pos = i;
			}
		}

		offset_x = offset_x + X[pos];
		offset_y = offset_y + Y[pos];

		/*getEntropy();
		_S = S;
		
		for (int i = 0; i < 8; i++)
		{
			int _offset_x = offset_x;
			int _offset_y = offset_y;

			offset_x = offset_x + X[i];
			offset_y = offset_y + Y[i];
			overlap();
			getEntropy();
			aS[i] = S - _S;

			offset_x = _offset_x;
			offset_y = _offset_y;
		}*/

		
	}

	return 0;
}

int cspe::doAutoOverlapCC()
{
	//create temp storage

	long size = sizex_ups * sizey_ups;

	long stepx = sizex_ups / sizex;
	long stepy = sizey_ups / sizey;

	long comm_size = size + 5 * (sizex_ups + sizey_ups) + 200;

	complex* fft_left = new complex[size * sizeof(complex)];
	complex* fft_right = new complex[size * sizeof(complex)];
	complex* cc = new complex[size * sizeof(complex)];
	complex* comm = new complex[comm_size * sizeof(complex)];
	int error;

	/*float* lmn = new float(0);
	float* rmn = new float(0);
	float* lsd = new float(0);
	float* rsd = new float(0);


	getMeanSTD(left_image_ups, size, (&lmn), (&lsd));
	float llmn = lmn[0];
	float llsd = lsd[0];
	getMeanSTD(right_image_ups, size, (&rmn), (&rsd));
	float rrmn = rmn[0];
	float rrsd = rsd[0];

	if (llsd == 0.0f) llsd = 1.0f;
	if (rrsd == 0.0f) rrsd = 1.0f;*/

	//populate
#pragma omp parallel for
	for (int i = 0; i < size; i++)
	{
		fft_left[i].real = left_image_ups[i];//(left_image_ups[i] - llmn) / llsd;
		fft_left[i].imag = 0.0f;

		fft_right[i].real = right_image_ups[i];//(right_image_ups[i] - rrmn) / rrsd;
		fft_right[i].imag = 0.0f;

		cc[i].real = 0.0f;
		cc[i].imag = 0.0f;
	}

	cfft2d(-1, sizex_ups, sizey_ups, fft_left, comm, &error);
	cfft2d(-1, sizex_ups, sizey_ups, fft_right, comm, &error);

	// Cross-correlation
#pragma omp parallel for
	for (int i = 0; i < size; i++)
	{
		float lRe = fft_left[i].real;
		float lImg = fft_left[i].imag;

		float rRe = fft_right[i].real;
		float rImg = -fft_right[i].imag;

		float Re = lRe * rRe - lImg * rImg;
		float Img = lImg * rRe + lRe * rImg;

		float A = sqrtf(Re * Re + Img * Img);
		if (A == 0.0f) A = 1.0f;

		A = 1.0f / A;

		cc[i].real = Re * A;
		cc[i].imag = Img * A;
	}

	// ifft
	cfft2d(1, sizex_ups, sizey_ups, cc, comm, &error);

	long hx = sizex_ups / 2;
	long hy = sizey_ups / 2;
#pragma omp parallel for
	for (int j = 0; j < hy; j++)
	{	
		for (int i = 0; i < hx; i++)
		{
			int a = p_xy_v1(i, j, sizex_ups, sizey_ups);
			int aa = p_xy_v1(i + hx, j + hy, sizex_ups, sizey_ups);
			int b = p_xy_v1(i + hx, j, sizex_ups, sizey_ups);
			int bb = p_xy_v1(i, j + hy, sizex_ups, sizey_ups);

			float aRe = cc[a].real;
			float aImg = cc[a].imag;
			float aaRe = cc[aa].real;
			float aaImg = cc[aa].imag;

			float bRe = cc[b].real;
			float bImg = cc[b].imag;
			float bbRe = cc[bb].real;
			float bbImg = cc[bb].imag;

			cc[a].real = aaRe;
			cc[a].imag = aaImg;
			cc[aa].real = aRe;
			cc[aa].imag = aImg;

			cc[b].real = bbRe;
			cc[b].imag = bbImg;
			cc[bb].real = bRe;
			cc[bb].imag = bImg;
		}
	}

	// naive maxima seeker
	float amax[5] = {-1.0e20f};
	int xaddr[5] = {0};
	int yaddr[5] = {0};

	for (int j = stepy; j < sizey_ups - stepy; j+=stepy)
	{
		for (int i = stepx; i < sizex_ups - stepx; i+=stepx)
		{
			int t = p_xy_v1(i, j, sizex_ups, sizey_ups);
			int xt = p_xy_v1(i-stepx, j, sizex_ups, sizey_ups);
			int tx = p_xy_v1(i+stepx, j, sizex_ups, sizey_ups);
			int yt = p_xy_v1(i, j-stepy, sizex_ups, sizey_ups);
			int ty = p_xy_v1(i, j+stepy, sizex_ups, sizey_ups);

			float R = cc[t].real * cc[t].real + cc[t].imag * cc[t].imag;
			float xR = cc[xt].real * cc[xt].real + cc[xt].imag * cc[xt].imag;
			float Rx = cc[tx].real * cc[tx].real + cc[tx].imag * cc[tx].imag;
			float yR = cc[yt].real * cc[yt].real + cc[yt].imag * cc[yt].imag;
			float Ry = cc[ty].real * cc[ty].real + cc[ty].imag * cc[ty].imag;

			if (R > xR && R > Rx && R > yR && R > Ry)
			{		
				int mm = -1;

				for (int k = 0; k < 5; k++)
				{
					if (R > amax[k]) 
					{
						mm = k;
						break;
					}
				}

				if (mm == -1) continue;

				if (mm != 4)
				{
					for (int k = 0; k < 5 - mm - 1; k++)
					{
						amax[4 - k] = amax[4 - k - 1];
						xaddr[4 - k] = xaddr[4 - k - 1]; 
						yaddr[4 - k] = yaddr[4 - k - 1];
					}
					amax[mm] = R;
					xaddr[mm] = i;
					yaddr[mm] = j;	
				}
				else 
				{
					amax[4] = R;
					xaddr[4] = i;
					yaddr[4] = j;	
				}
			}

		}
	}

	if (amax[1] > 0.05 * amax[0])
	{
		offset_y =  hy - yaddr[1];
		offset_x =  hx - xaddr[1];
	}
	else
	{
		/*int xc[9] = {-1, 0, 1, -1, 0, 1, -1, 0, 1};
		int yc[9] = {-1, -1, -1, 0, 0, 0, 1, 1, 1};
		double acc[9] = {0.0};
		int cm = 0;
		double max = -1e20;

		for (int i = 0; i < 9; i++)
		{
			double icc = getCC(xc[i], yc[i]);
			acc[i] = icc;
			if (icc > max)
			{
				cm = i;
				max = icc;
			}
		}
		offset_y = yc[cm];
		offset_x = xc[cm];*/
	}


	overlap();

	delete[] fft_left;
	delete[] fft_right;
	delete[] comm;
	delete[] cc;
	return 0;
}

int cspe::doAutoOverlapCCA()
{
	//create temp storage

	long sx = sizex_ups / 2;
	long sy = sizey_ups / 2;

	long hx = sx / 2;
	long hy = sy / 2;

	long size = sx * sy;

	long stepx = sizex_ups / sizex;
	long stepy = sizey_ups / sizey;

	long comm_size = size + 5 * (sx + sy) + 200;

	complex* fft_left = new complex[size * sizeof(complex)];
	complex* fft_right = new complex[size * sizeof(complex)];
	complex* cc = new complex[size * sizeof(complex)];
	complex* comm = new complex[comm_size * sizeof(complex)];
	int error;

	//populate
#pragma omp parallel for
	for (long j = 0; j < sy; j++)
	{	
		long jj = hy + j;
		for (long i = 0; i < sx; i++)
		{
			long ii = hx + i;
			long aa = p_xy_v1(ii, jj, sizex_ups, sizey_ups);
			long a = p_xy_v1(i, j, sx, sy);

			float w = hanning_2d(i, j, sx, sy);

			fft_left[a].real = left_image_ups[aa] * w;
			fft_left[a].imag = 0.0f;

			fft_right[a].real = right_image_ups[aa] * w;
			fft_right[a].imag = 0.0f;

			cc[a].real = 0.0f;
			cc[a].imag = 0.0f;
		}
	}

	cfft2d(-1, sx, sy, fft_left, comm, &error);
	cfft2d(-1, sx, sy, fft_right, comm, &error);

	// Cross-correlation
#pragma omp parallel for
	for (int i = 0; i < size; i++)
	{
		int ii = i % sx;
		int jj = i / sx;

		ii = (ii < hx) ? ii + hx : ii;
		jj = (jj < hy) ? jj + hy : jj;

		float xx = (float)ii/(float)sx - 0.5f;
		float yy = (float)jj/(float)sy - 0.5f;

		float w = highpass_fd_2d(xx, yy);
		w *= w;

		float lRe = fft_left[i].real;
		float lImg = fft_left[i].imag;

		float rRe = fft_right[i].real;
		float rImg = -fft_right[i].imag;

		float Re = lRe * rRe - lImg * rImg;
		float Img = lImg * rRe + lRe * rImg;

		float A = sqrtf(Re * Re + Img * Img);
		if (A == 0.0f) A = 1.0f;

		A = w / A;

		cc[i].real = Re * A;
		cc[i].imag = Img * A;
	}

	// ifft
	cfft2d(1, sx, sy, cc, comm, &error);

#pragma omp parallel for
	for (long j = 0; j < hy; j++)
	{	
		for (long i = 0; i < hx; i++)
		{
			int a = p_xy_v1(i, j, sx, sy);
			int aa = p_xy_v1(i + hx, j + hy, sx, sy);
			int b = p_xy_v1(i + hx, j, sx, sy);
			int bb = p_xy_v1(i, j + hy, sx, sy);

			float aRe = cc[a].real;
			float aImg = cc[a].imag;
			float aaRe = cc[aa].real;
			float aaImg = cc[aa].imag;

			float bRe = cc[b].real;
			float bImg = cc[b].imag;
			float bbRe = cc[bb].real;
			float bbImg = cc[bb].imag;

			cc[a].real = aaRe;
			cc[a].imag = aaImg;
			cc[aa].real = aRe;
			cc[aa].imag = aImg;

			cc[b].real = bbRe;
			cc[b].imag = bbImg;
			cc[bb].real = bRe;
			cc[bb].imag = bImg;
		}
	}

	// naive maxima seeker
	float amax[5] = {-1.0e20f};
	int xaddr[5] = {0};
	int yaddr[5] = {0};


	for (long j = stepy; j < sy - stepy; j+=stepy)
	{
		for (long i = stepx; i < sx - stepx; i+=stepx)
		{
			long t = p_xy_v1(i, j, sx, sy);
			float R = cc[t].real * cc[t].real + cc[t].imag * cc[t].imag;

#ifdef _DEBUG
			int xt = p_xy_v1(i-stepx, j, sx, sy);
			int tx = p_xy_v1(i+stepx, j, sx, sy);
			int yt = p_xy_v1(i, j-stepy, sx, sy);
			int ty = p_xy_v1(i, j+stepy, sx, sy);
			
			float xR = cc[xt].real * cc[xt].real + cc[xt].imag * cc[xt].imag;
			float Rx = cc[tx].real * cc[tx].real + cc[tx].imag * cc[tx].imag;
			float yR = cc[yt].real * cc[yt].real + cc[yt].imag * cc[yt].imag;
			float Ry = cc[ty].real * cc[ty].real + cc[ty].imag * cc[ty].imag;

			if (R > xR && R > Rx && R > yR && R > Ry & R > amax[0])
#endif

#ifndef _DEBUG
			if (R > amax[0])
#endif
			{		

#ifndef _DEBUG
				amax[0] = R;
				xaddr[0] = i;
				yaddr[0] = j;
#endif

#ifdef _DEBUG
				int mm = -1;

				for (int k = 0; k < 5; k++)
				{
					if (R > amax[k]) 
					{
						mm = k;
						break;
					}
				}

				if (mm == -1) continue;

				if (mm != 4)
				{
					for (int k = 0; k < 5 - mm - 1; k++)
					{
						amax[4 - k] = amax[4 - k - 1];
						xaddr[4 - k] = xaddr[4 - k - 1]; 
						yaddr[4 - k] = yaddr[4 - k - 1];
					}
					amax[mm] = R;
					xaddr[mm] = i;
					yaddr[mm] = j;	
				}
				else 
				{
					amax[4] = R;
					xaddr[4] = i;
					yaddr[4] = j;	
				}
#endif
			}

		}
	}

	offset_y =  hy - yaddr[0];
	offset_x =  hx - xaddr[0];

	if (offset_y > -10 && offset_y < 10 && offset_x > -10 && offset_x < 10)
	{
		/*float* lmn = new float(0);
		float* rmn = new float(0);
		float* lsd = new float(0);
		float* rsd = new float(0);

		long ss = sizex_ups * sizey_ups;

		getMeanSTD(left_image_ups, ss, (&lmn), (&lsd));
		float llmn = lmn[0];
		float llsd = lsd[0];
		getMeanSTD(right_image_ups, ss, (&rmn), (&rsd));
		float rrmn = rmn[0];
		float rrsd = rsd[0];

		if (llsd == 0.0f) llsd = 1.0f;
		if (rrsd == 0.0f) rrsd = 1.0f;

		llsd = 1.0f / llsd;
		rrsd = 1.0f / rrsd;

		getCC();*/
	}

	overlap();

	delete[] fft_left;
	delete[] fft_right;
	delete[] comm;
	delete[] cc;
	return 0;
}

int cspe::doAutoOverlapCCAx8()
{
	//create temp storage

	long ssx = sizex_ups / 2;
	long ssy = sizey_ups / 2;

	long hhx = ssx / 2;
	long hhy = ssy / 2;

	long sx = 4 * ssx;
	long sy = 4 * ssy;

	long hx = sx / 2;
	long hy = sy / 2;

	long ox = hx - hhx;
	long oy = hy - hhy;


	long size = sx * sy;

	long stepx = sizex_ups / sizex;
	long stepy = sizey_ups / sizey;

	long comm_size = size + 5 * (sx + sy) + 200;

	complex* fft_left = new complex[size * sizeof(complex)];
	complex* fft_right = new complex[size * sizeof(complex)];
	complex* cc = new complex[size * sizeof(complex)];
	complex* comm = new complex[comm_size * sizeof(complex)];
	int error;
#pragma omp parallel for
	for (int i = 0; i < size; i++)
	{
		fft_left[i].real = 0.0f;
		fft_left[i].imag = 0.0f;
		fft_right[i].real = 0.0f;
		fft_right[i].imag = 0.0f;
		cc[i].imag = 0.0f;
		cc[i].real = 0.0f;
	}

	//populate
#pragma omp parallel for
	for (int j = 0; j < ssy; j++)
	{	
		int jj = hhy + j;
		for (int i = 0; i < ssx; i++)
		{
			int ii = hhx + i;
			int aa = p_xy_v1(ii, jj, sizex_ups, sizey_ups);
			int a = p_xy_v1(i, j, sx, sy);

			float w = hanning_2d(i, j, ssx, ssy);

			fft_left[a].real = left_image_ups[aa] * w;
			fft_left[a].imag = 0.0f;

			fft_right[a].real = right_image_ups[aa] * w;
			fft_right[a].imag = 0.0f;

			//cc[a].real = 0.0f;
			//cc[a].imag = 0.0f;
		}
	}

	cfft2d(-1, sx, sy, fft_left, comm, &error);
	cfft2d(-1, sx, sy, fft_right, comm, &error);

	// Cross-correlation
#pragma omp parallel for
	for (int i = 0; i < size; i++)
	{
		int ii = i % sx;
		int jj = i / sx;

		ii = (ii < hx) ? ii + hx : ii;
		jj = (jj < hy) ? jj + hy : jj;

		float xx = (float)ii/(float)sx - 0.5f;
		float yy = (float)jj/(float)sy - 0.5f;

		float w = highpass_fd_2d(xx, yy);
		w *= w;

		float lRe = fft_left[i].real;
		float lImg = fft_left[i].imag;

		float rRe = fft_right[i].real;
		float rImg = -fft_right[i].imag;

		float Re = lRe * rRe - lImg * rImg;
		float Img = lImg * rRe + lRe * rImg;

		float A = sqrtf(Re * Re + Img * Img);
		if (A == 0.0f) A = 1.0f;

		A = w / A;

		cc[i].real = Re * A;
		cc[i].imag = Img * A;
	}

	// ifft
	cfft2d(1, sx, sy, cc, comm, &error);

#pragma omp parallel for
	for (int j = 0; j < hy; j++)
	{	
		for (int i = 0; i < hx; i++)
		{
			int a = p_xy_v1(i, j, sx, sy);
			int aa = p_xy_v1(i + hx, j + hy, sx, sy);
			int b = p_xy_v1(i + hx, j, sx, sy);
			int bb = p_xy_v1(i, j + hy, sx, sy);

			float aRe = cc[a].real;
			float aImg = cc[a].imag;
			float aaRe = cc[aa].real;
			float aaImg = cc[aa].imag;

			float bRe = cc[b].real;
			float bImg = cc[b].imag;
			float bbRe = cc[bb].real;
			float bbImg = cc[bb].imag;

			cc[a].real = aaRe;
			cc[a].imag = aaImg;
			cc[aa].real = aRe;
			cc[aa].imag = aImg;

			cc[b].real = bbRe;
			cc[b].imag = bbImg;
			cc[bb].real = bRe;
			cc[bb].imag = bImg;
		}
	}

	// naive maxima seeker
	float amax[5] = {-1.0e20f};
	int xaddr[5] = {0};
	int yaddr[5] = {0};

	for (int j = stepy; j < sy - stepy; j+=stepy)
	{
		for (int i = stepx; i < sx - stepx; i+=stepx)
		{
			int t = p_xy_v1(i, j, sx, sy);
			int xt = p_xy_v1(i-stepx, j, sx, sy);
			int tx = p_xy_v1(i+stepx, j, sx, sy);
			int yt = p_xy_v1(i, j-stepy, sx, sy);
			int ty = p_xy_v1(i, j+stepy, sx, sy);

			float R = cc[t].real * cc[t].real + cc[t].imag * cc[t].imag;
			float xR = cc[xt].real * cc[xt].real + cc[xt].imag * cc[xt].imag;
			float Rx = cc[tx].real * cc[tx].real + cc[tx].imag * cc[tx].imag;
			float yR = cc[yt].real * cc[yt].real + cc[yt].imag * cc[yt].imag;
			float Ry = cc[ty].real * cc[ty].real + cc[ty].imag * cc[ty].imag;

			if (R > xR && R > Rx && R > yR && R > Ry)
			{		
				int mm = -1;

				for (int k = 0; k < 5; k++)
				{
					if (R > amax[k]) 
					{
						mm = k;
						break;
					}
				}

				if (mm == -1) continue;

				if (mm != 4)
				{
					for (int k = 0; k < 5 - mm - 1; k++)
					{
						amax[4 - k] = amax[4 - k - 1];
						xaddr[4 - k] = xaddr[4 - k - 1]; 
						yaddr[4 - k] = yaddr[4 - k - 1];
					}
					amax[mm] = R;
					xaddr[mm] = i;
					yaddr[mm] = j;	
				}
				else 
				{
					amax[4] = R;
					xaddr[4] = i;
					yaddr[4] = j;	
				}
			}

		}
	}

	offset_y =  round(((float)(hy - yaddr[1]) / 4.0f));
	offset_x =  round(((float)(hx - xaddr[1]) / 4.0f));

	overlap();

	delete[] fft_left;
	delete[] fft_right;
	delete[] comm;
	delete[] cc;
	return 0;
}


int cspe::getCC()
{
	long minx = -10;
	long maxx = +10;

	long miny = -10;
	long maxy = +10;

	long ssx = maxx - minx;
	long ssy = maxy - miny;

	long size = ssx * ssy;
	double *cca = new double[size];

	double cc = 0.0f;

#pragma omp parallel for
	for (long jj = 0; jj < ssy; jj++)
	{
		long oy = jj + miny;
		for (long ii = 0; ii < ssx; ii++)
		{
			long ccc = p_xy_v1(ii, jj, ssx, ssy);
			long ox = ii + minx;

			double vcc = 0.0f;
			double vl = 0.0f;
			double vr = 0.0f;

			for (long j = 0; j < sizey_ups; j++)
			{
				long jjj = j + oy;
				for (long i = 0; i < sizex_ups; i++)
				{
					long iii = i + ox;
					long tt = p_xy_v1_s(iii , jjj, sizex_ups, sizey_ups);
					
					if (tt == -1) continue;

					long t = p_xy_v1(i , j, sizex_ups, sizey_ups);
					double l = (left_image_ups[t] - llmn);// * llsd;
					double r = (right_image_ups[tt] - rrmn);// * rrsd;

					vcc += l * r;
					vl += l * l;
					vr += r * r;
				}
			}

			
			//vcc = (vl != 0.0f && vr != 0.0f)?vcc / sqrtf(vl*vr):0.0f; in question
			vcc = vcc / sqrt(vl*vr);
			cca[ccc] = vcc;
		}
	}

	cc = cca[0];

	for (int i = 1; i < size; i++)
	{
		double vcc = cca[i];
		if (vcc > cc)
		{
			cc = vcc;
			offset_x = i;
		}
	}

	offset_y = offset_x / ssx;
	offset_x = offset_x % ssx;

	offset_x = offset_x - ssx / 2;
	offset_y = offset_y - ssy / 2;

#ifdef _DEBUG
	FILE* f;
	f = fopen("naive-1422.dat", "w");
	for (int j = 0; j < ssy; j++)
	{
		int i = 0;
		for (i = 0; i < ssx - 1; i++)
		{
			int addr = p_xy_v1(i, j, ssx, ssy);
			fprintf(f, "%.8f\t", cca[addr]);
		}
		i++;
		int addr = p_xy_v1(i, j, ssx, ssy);
		fprintf(f, "%.8f\n", cca[addr]);
	}
	fclose(f);
	delete[] cca;
#endif

	return 0;
}

int cspe::getMeanSTD(float* buffer, long size, float** mean, float** stddiv)
{
	// get mean
	double dmn = 0.0;
#pragma omp parallel for reduction(+:dmn)
	for (int i = 0; i < size; i++)
	{
		dmn += buffer[i];
	}
	dmn /= size;
	float mn = (float)dmn;
	*mean = &mn;

	// get stddiv
	double std = 0.0;
#pragma omp parallel for reduction(+:std)
	for (int i = 0; i < size; i++)
	{
		std += (buffer[i]-dmn)*(buffer[i]-dmn);
	}
	std = sqrt(std/size);

	float sd = (float)std;

	*stddiv = &sd;

	return 0;
}

	//FILE* f;
	//f = fopen("cc.dat", "w");
	//for (int j = 0; j < sizey_ups; j++)
	//{
	//	int i = 0;
	//	for (i = 0; i < sizex_ups - 1; i++)
	//	{
	//		int addr = p_xy_v1(i, j, sizex_ups, sizey_ups);
	//		fprintf(f, "%.8f\t", cc[addr].real * cc[addr].real + cc[addr].imag * cc[addr].imag);
	//	}
	//	i++;
	//	int addr = p_xy_v1(i, j, sizex_ups, sizey_ups);
	//	fprintf(f, "%.8f\n", cc[addr].real * cc[addr].real + cc[addr].imag * cc[addr].imag);
	//}
	//fclose(f);

	/*for (int i = 0; i < size; i++)
	{
		float R = cc[i].real * cc[i].real + cc[i].imag * cc[i].imag;

		for (int j = 0; j < 5; j++)
		{
			if (R > amax[j])
			{
				amax[j] = R;
				aaddr[j] = i;
				break;
			}
		}	
	}

	 get 2D coords;

	offset_y = aaddr[0] / sizex_ups;
	offset_x = aaddr[0] - offset_y * sizex_ups;*/
#pragma managed