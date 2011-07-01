



#ifndef _N_SPE_H
#define _N_SPE_H
//#include <msclr/marshal.h>

#pragma unmanaged
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <omp.h>

#define SPEHEADER 4100
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
};



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

inline float clamp(float val, float min, float max)
{
	val = (val>max)?max:val;
	val = (val<min)?min:val;
	return (val-min)/(max-min);
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