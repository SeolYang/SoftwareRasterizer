#pragma once

#include <cmath>

#define D_EPSILON FLT_EPSILON

#define D_PI 3.1415926f

#define D_RADTODEG 57.29577951f	/* (180 / pi) */
#define D_DEGTORAD 0.017453293f		/* (pi / 180) */

#define COLOR_XRGB(r,g,b) (D3DCOLOR_ARGB(0xff, r,g,b))
#define COLOR_RGBA(r,g,b,a) D3DCOLOR_ARGB(a,r,g,b)
#define COLOR_RGBAVALUE(r,g,b,a) \
	D3DCOLOR_RGBA((DWORD)((r)*255.f),(DWORD)((g)*255.f),(DWORD)((b)*255.f),(DWORD)((a)*255.f))

#define DEGREE_SIN(Angle) (sin(Angle * D_DEGTORAD))
#define DEGREE_COS(Angle) (cos(Angle * D_DEGTORAD))
#define DEGREE_TAN(Angle) (tan(Angle * D_DEGTORAD))

#define DEGREE_ASIN(VALUE) (asin(Value) * D_RADTODEG)
#define DEGREE_ACOS(Value) (acos(Value) * D_RADTODEG)
#define DEGREE_ATAN(Value) (atan(Value) * D_RADTODEG)
#define DEGREE_ATAN2(Value1, Value2) (atan2(Value1, Value2) * D_RADTODEG)

namespace SRMath
{
	template <typename _Ty>
	inline static _Ty Clamp(_Ty Value, _Ty Min, _Ty Max)
	{
		if (Value < Min)
		{
			return Min;
		}
		else if (Value > Max)
		{
			return Max;
		}
		else
		{
			return Value;
		}
	}

	inline static float Clamp01(float Value)
	{
		if (Value > 1.0f)
		{
			return 1.0f;
		}
		else if (Value < 0.0f)
		{
			return 0.0f;
		}
		else
		{
			return Value;
		}
	}

	template <typename _Ty>
	inline static _Ty Max(_Ty Value, _Ty Max)
	{
		if (Value > Max)
		{
			return Max;
		}
		else
		{
			return Value;
		}
	}

	template <typename _Ty>
	inline static _Ty Min(_Ty Value, _Ty Min)
	{
		if (Value < Min)
		{
			return Min;
		}
		else
		{
			return Value;
		}
	}

	template <typename _Ty
		, _Ty _IsPod = std::is_pod<_Ty>::value
		, _Ty _IsSigned = std::is_signed<_Ty>::value>
		inline static _Ty Abs(_Ty Value)
	{
		if (Value < static_cast<_Ty>(0))
		{
			return (Value) * static_cast<_Ty>(-1);
		}
		else
		{
			return Value;
		}
	}

	inline static int Random()
	{
		static std::random_device Rd;
		static std::mt19937 REngine(Rd());
		static std::uniform_int_distribution<> Dist(0, INT_MAX);

		return Dist(REngine);
	}

	inline static double Random01()
	{
		return Random() / static_cast<double>(INT_MAX);
	}
}