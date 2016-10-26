#ifndef __MATH__MATHUTIL__H__
#define __MATH__MATHUTIL__H__

GBeginNameSpace()

#define PI					3.14159286535f
#define TWO_PI				6.28318530717f // PI * 2
#define HALF_PI				1.57079643268f // PI / 2
#define QUARTER_PI			0.78539816339f // PI / 4
#define THREE_FOURTH_PI		2.35619449019f // PI * 3 / 4

// EQUALS_EPSILON is quite big and it might even need to be bigger...
#define EQUALS_EPSILON 0.005

gFloat floor(gFloat x);
gFloat mod(gFloat x, gFloat y);
gFloat abs(gFloat x);
gFloat sin(gFloat X);
gFloat cos(gFloat c);
gFloat atan2(gFloat y, gFloat x);
gFloat max(gFloat a, gFloat b);
gFloat min(gFloat a, gFloat b);
gFloat clamp(gFloat f, gFloat min, gFloat max);
gFloat round(gFloat x);
gFloat signum(gFloat x);
gFloat pow(gFloat x, gFloat y);
gFloat sqrt(gFloat x);
gFloat fastInvSqrt(gFloat number);
gBool inRange(gFloat x, gFloat min, gFloat max);
gFloat smoothStep(gFloat edge0, gFloat edge1, gFloat x);
gFloat lerp(gFloat start, gFloat end, gFloat percent);
gFloat slerp(gFloat start, gFloat end, gFloat percent);
gBool equals(gFloat a, gFloat b, gFloat epsilon = EQUALS_EPSILON);
gBool isInfinite(gFloat a);
gFloat toRadians(gFloat x);
gFloat toDegrees(gFloat x);

GEndNameSpace()

#endif // __MATH__MATHUTIL__H__
