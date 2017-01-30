#ifndef __MATH__MATHUTIL__H__
#define __MATH__MATHUTIL__H__

GBeginNameSpace()

#define _PI					3.14159286535f
#define _2PI					6.28318530717f // PI * 2
#define _PI2					1.57079643268f // PI / 2
#define _PI4					0.78539816339f // PI / 4
#define _3PI4				2.35619449019f // PI * 3 / 4

// EQUALS_EPSILON is quite big and it might even need to be bigger...
#define EQUALS_EPSILON 0.005

float floor(float x);
float mod(float x, float y);
float abs(float x);
float sin(float X);
float cos(float c);
float atan2(float y, float x);
float max(float a, float b);
float min(float a, float b);
float clamp(float f, float min, float max);
float round(float x);
float signum(float x);
float pow(float x, float y);
float sqrt(float x);
float fastInvSqrt(float number);
bool inRange(float x, float min, float max);
float smoothStep(float edge0, float edge1, float x);
float lerp(float start, float end, float percent);
float slerp(float start, float end, float percent);
bool equals(float a, float b, float epsilon = EQUALS_EPSILON);
bool isInfinite(float a);
float toRadians(float x);
float toDegrees(float x);

GEndNameSpace()

#endif // __MATH__MATHUTIL__H__
