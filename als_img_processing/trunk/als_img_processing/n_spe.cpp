
#include "n_spe.h"

#pragma unmanaged
const char* cspe::bpe_filename_left;
const char* cspe::bpe_filename_right;

long cspe::offset_x = 0;
long cspe::offset_y = 0;

long cspe::step_x = 1;
long cspe::step_y = 1;


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

	if (mode == 0 || mode == 4)
	{
		for (long j = 0; j < sizey_ups; j++)
		{
			for (long i=0; i < sizex_ups; i++)
			{
				long ii = p_xy_v1(i,j,sizex_ups, sizey_ups);
				long jj = 3 * p_xy_v1(i,j,stride/3, sizey_ups);
				float val = buffer[ii];
				val = clamp(val, dr_low, dr_high);
				unsigned char cval = (unsigned char)255.0 * val;//(powf(spow,val)-1.0)*spown; 
				imdata[jj] = cval;
				imdata[jj+1] = cval;
				imdata[jj+2] = cval;
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
#pragma managed