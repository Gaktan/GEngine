#include "precomp.h"

#include "math/mathutil.h"

#include <math.h>
#include <cmath>

GBeginNameSpace()

gFloat floor(gFloat x)
{
	return ::floor(x);
}

// x mod y is x-y*floor(x/y)
gFloat mod(gFloat x, gFloat y)
{
	return x - y * floor(x / y);
}

gFloat abs(gFloat x)
{
	return fabs(x);
}

gFloat sin(gFloat x)
{
	// Clamp x between -PI and PI
	x = mod(x + PI, TWO_PI) - PI;

	gFloat xx = x * x;
	gFloat result = x + (x * xx) * (-0.16612511580269618f + xx * (8.0394356072977748e-3f + xx * -1.49414020045938777495e-4f));

	return result;
}

// Credits:
gFloat atan2(gFloat y, gFloat x)
{
	gFloat r, angle;
	gFloat abs_y = abs(y) + 1e-10f; // kludge to prevent 0/0 condition
	if (x < 0.f)
	{
		r = (x + abs_y) / (abs_y - x);
		angle = THREE_FOURTH_PI;
	}
	else
	{
		r = (x - abs_y) / (x + abs_y);
		angle = QUARTER_PI;
	}
	angle += (0.1963f * r * r - 0.9817f) * r;

	return (y < 0.f) ? -angle : angle;
}

gFloat cos(gFloat x)
{
	return sin(x + HALF_PI);
}

gFloat max(gFloat a, gFloat b)
{
	return (a > b) ? a : b;
}

gFloat min(gFloat a, gFloat b)
{
	return (a < b) ? a : b;
}

gFloat clamp(gFloat f, gFloat _min, gFloat _max)
{
	return max(_min, min(_max, f));
}

gFloat round(gFloat x)
{
	return floor(x + 0.5f);
}

gFloat signum(gFloat x)
{
	return (x < 0.f) ? -1.f : 1.f;
}

gFloat pow(gFloat x, gFloat y)
{
	return ::pow(x, y);
}

float sqrt(gFloat x)
{
	return ::sqrt(x);
}

gFloat fastInvSqrt(gFloat number)
{
	gLong i;
	gFloat x2, y;
	const gFloat threehalfs = 1.5f;

	x2 = number * 0.5f;
	y  = number;
	i  = *(gLong *) &y;                       // evil floating point bit level hacking
	i  = 0x5f3759df - (i >> 1);               // what the fuck?
	y  = *(float *) &i;
	y  = y * (threehalfs - (x2 * y * y));   // 1st iteration
	//y  = y * (hreehalfs - (x2 * y * y));   // 2nd iteration, this can be removed

	return y;
}

gBool inRange(gFloat x, gFloat min, gFloat max)
{
	return (x >= min) ? (x < max) : false;
}

gFloat smoothStep(gFloat edge0, gFloat edge1, gFloat x)
{
	x = clamp((x - edge0) / (edge1 - edge0), 0, 1);
	// Evaluate polynomial
	return x * x * (3 - 2 * x);
}

gFloat lerp(gFloat start, gFloat end, gFloat percent)
{
	return (start + percent * (end - start));
}

gFloat slerp(gFloat start, gFloat end, gFloat percent)
{
	return lerp(start, end, smoothStep(0, 1, percent));
}

gBool equals(gFloat a, gFloat b, gFloat epsilon)
{
	return abs(a - b) < epsilon;
}

gBool isInfinite(gFloat a)
{
	return !std::isfinite(a);
}


GEndNameSpace()
