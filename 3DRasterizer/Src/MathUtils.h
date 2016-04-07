#pragma once

#include <cmath>

#define D_EPSILON FLT_EPSILON

#define D_PI 3.1415926f

#define D_RADTWODEG 57.29577951f	/* (180 / pi) */
#define D_DEGTORAD 0.017453293f		/* (pi / 180) */

#define COLOR_XRGB(r,g,b) D3DCOLOR_ARGB(0xff, r,g,b)
#define COLOR_RGBA(r,g,b,a) D3DCOLOR_ARGB(a,r,g,b)
#define COLOR_RGBAVALUE(r,g,b,a) \
	D3DCOLOR_RGBA((DWORD)((r)*255.f),(DWORD)((g)*255.f),(DWORD)((b)*255.f),(DWORD)((a)*255.f))