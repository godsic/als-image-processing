



#ifndef _N_SPE_H
#define _N_SPE_H
//#include <msclr/marshal.h>

#pragma unmanaged
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define _USE_MATH_DEFINES
#include <math.h>
#include <omp.h>
#include <acml.h>

#define SPEHEADER 4100
#define INTERVALS 16384

typedef __int16 WORDS;
typedef unsigned __int16 UWORDS;


struct SPE{
	char blank1[42];			//+0
	UWORDS sizex;				//+42
	char blank2[64];			//+44
	WORDS  dtype;				//+108
	char blank3[546];			//+110
	UWORDS sizey;			    //+656
	char blank4[3442];			//+658
	char data;					//+4100
};

typedef SPE sspe;

class cspe{

public: 
	static const char* bpe_filename_left;
	static const char* bpe_filename_right;

	static long offset_x;
	static long offset_y;

	static long step_x;
	static long step_y;

	static sspe* left_image;
	static sspe* right_image;
	static long sizex;
	static long sizey;

	static float* left_image_ups;
	static float* right_image_ups;

	static long sizex_ups;
	static long sizey_ups;

	static float* image;

	static float dr_low;
	static float dr_high;
	static float dr_step;

	static float dr_low_AdB;
	static float dr_high_AdB;

	static float dr_low_AmBdApB;
	static float dr_high_AmBdApB;

	static float rrmn;
	static float llmn;

	static float llsd;
	static float rrsd;

	static double S;

	static int cur_pair;

	static int mode;
	static int op;
	static int ups;
	static int scale;
public: 
	static int file_loader(const char* name, char** file);
	static int spe_save(const char* name);
    static int process(const char* namel, const char* namer);
    static int upsample();
    static int supsample(sspe* in, float** out);
    static int overlap();
    static int map_to_bitmap(unsigned char* imdata, int stride);
	static float vmaximum(float* buffer, long size);
	static int tofloat(sspe* in, float** out);
	static int getEntropy();
	static int doAutoOverlap();
	static int doAutoOverlapCC();
	static int doAutoOverlapCCA();
	static int doAutoOverlapCCAx8();
	static int getCC();
	static int getMeanSTD(float* buffer, long size, float** mean, float** stddiv);
};

inline void p_shifted(long x, long y, long sizex, long sizey, long** shx, long** shy)
{
	long hx = sizex / 2;
	long hy = sizey / 2;

	long tsx = 0;
	long tsy = 0;

	if (x < hx && y < hy)
	{
		tsx = hx + x;
		tsy = hy + y;
	}

	if (x > hx && y < hy)
	{
		tsx = x - hx;
		tsy = hy;
	}

	if (x < hx && y > hy)
	{
		tsx = x;
		tsy = y - hy;
	}

	if (x > hx && y > hy)
	{
		tsx = x - hx;
		tsy = y - hy;
	}

	*shx = &tsx;
	*shy = &tsy;
}

inline long p_xy_v1(long x, long y, long sizex, long sizey)
{
	return y * sizex + x;
}

inline long p_xy_v1_s(long x, long y, long sizex, long sizey)
{
	if (x >= sizex) return -1;
	if (x < 0) return -1;
	if (y >= sizey) return -1;
	if (y < 0) return -1;

	return y * sizex + x;
}

inline float round(float x)
{
	float xx = x;
	float rx = fmodf(x,1.0f);
	if (rx >= 0.5) xx++;
	return xx;
}

inline float clamp(float val, float min, float max)
{
	val = (val>max)?max:val;
	val = (val<min)?min:val;
	return (val-min)/(max-min);
}

inline float highpass_fd_2d(float x, float y)
{
	float A = cosf(M_PI * x)*cosf(M_PI * y);
	return (1.0f - A) * (2.0f - A);
}

inline float blackman_2d(int x, int y, int sx, int sy)
{
	float wx = 0.42f - 0.5f * cosf(2.0f*M_PI*(float)x/(float)(sx-1)) + 0.08f * cosf(4.0f*M_PI*(float)x/(float)(sx-1));
	float wy = 0.42f - 0.5f * cosf(2.0f*M_PI*(float)y/(float)(sy-1)) + 0.08f * cosf(4.0f*M_PI*(float)y/(float)(sy-1));

	return wx * wy;
}

inline float hamming_2d(int x, int y, int sx, int sy)
{
	float wx = 0.54f - 0.46f * cosf(2.0f*M_PI*(float)x/(float)(sx-1));
	float wy = 0.54f - 0.46f * cosf(2.0f*M_PI*(float)y/(float)(sy-1));

	return wx * wy;
}

inline float hanning_2d(int x, int y, int sx, int sy)
{
	float wx = 0.5f - 0.5f * cosf(2.0f*M_PI*(float)x/(float)(sx-1));
	float wy = 0.5f - 0.5f * cosf(2.0f*M_PI*(float)y/(float)(sy-1));

	return wx * wy;
}

inline void clampU(float val, float min, float max, float mx, float zero, float** res)
{
	*(*res + 0) = 0;
	*(*res + 1) = 0;

	val = (val>max)?max:val;
	val = (val<min)?min:val;
	
	val = val - zero;
	if (val > 0.0) *(*res + 0) = abs(val/mx);
	else *(*res + 1) = abs(val/mx);
}

#pragma managed

#endif