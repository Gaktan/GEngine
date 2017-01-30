#include "precomp.h"

#include "math/mathutil.h"

#include <math.h>
#include <cmath>

GBeginNameSpace()

float floor(float x)
{
	return ::floor(x);
}

// x mod y is x-y*floor(x/y)
float mod(float x, float y)
{
	return x - y * floor(x / y);
}

float abs(float x)
{
	return fabs(x);
}

float sin(float x)
{
	// Clamp x between -PI and PI
	x = mod(x + _PI, _2PI) - _PI;

	float xx = x * x;
	float result = x + (x * xx) *
				   (-0.16612511580269618f +
					xx * (8.0394356072977748e-3f +
					xx * -1.49414020045938777495e-4f));

	return result;
}

// Credits:
float atan2(float y, float x)
{
	float r, angle;
	float abs_y = abs(y) + 1e-10f; // kludge to prevent 0/0 condition
	if (x < 0.f)
	{
		r = (x + abs_y) / (abs_y - x);
		angle = _3PI4;
	}
	else
	{
		r = (x - abs_y) / (x + abs_y);
		angle = _PI4;
	}
	angle += (0.1963f * r * r - 0.9817f) * r;

	return (y < 0.f) ? -angle : angle;
}

float cos(float x)
{
	return sin(x + _PI2);
}

float max(float a, float b)
{
	return (a > b) ? a : b;
}

float min(float a, float b)
{
	return (a < b) ? a : b;
}

float clamp(float f, float _min, float _max)
{
	return max(_min, min(_max, f));
}

float round(float x)
{
	return floor(x + 0.5f);
}

float signum(float x)
{
	return (x < 0.f) ? -1.f : 1.f;
}

float pow(float x, float y)
{
	return ::pow(x, y);
}

float sqrt(float x)
{
	return ::sqrt(x);
}

float fastInvSqrt(float number)
{
	long i;
	float x2, y;
	const float threehalfs = 1.5f;

	x2 = number * 0.5f;
	y  = number;
	i  = *(long *) &y;						// evil floating point bit level hacking
	i  = 0x5f3759df - (i >> 1);				// what the fuck?
	y  = *(float *) &i;
	y  = y * (threehalfs - (x2 * y * y));	// 1st iteration
	//y  = y * (hreehalfs - (x2 * y * y));	// 2nd iteration, this can be removed

	return y;
}

bool inRange(float x, float min, float max)
{
	return (x >= min) ? (x < max) : false;
}

float smoothStep(float edge0, float edge1, float x)
{
	x = clamp((x - edge0) / (edge1 - edge0), 0, 1);
	// Evaluate polynomial
	return x * x * (3 - 2 * x);
}

float lerp(float start, float end, float percent)
{
	return (start + percent * (end - start));
}

float slerp(float start, float end, float percent)
{
	return lerp(start, end, smoothStep(0, 1, percent));
}

bool equals(float a, float b, float epsilon)
{
	return abs(a - b) < epsilon;
}

bool isInfinite(float a)
{
	return !std::isfinite(a);
}

float toRadians(float x)
{
	return x * 0.01745329251f; // PI / 180
}

float toDegrees(float x)
{
	return x * 57.2957795131f; // 180 / PI
}

GEndNameSpace()
