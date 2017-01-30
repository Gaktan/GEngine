#ifndef __MATH__EANGLE__H__
#define __MATH__EANGLE__H__

#include "vector4.h"

GBeginNameSpace()

class EAngle
{
public:
	EAngle();
	EAngle(const EAngle &other);
	EAngle(const Vec4f &v);
	EAngle(const float p, const float y, const float r);
	virtual ~EAngle();

	void Normalize();
	void LookAt(const Vec4f &direction);

	Vec4f ToVector();

	inline float GetPitch() const { return pitch; }
	inline void SetPitch(const float value) { pitch = value; }

	inline float GetYaw() const { return yaw; }
	inline void SetYaw(const float value) { yaw = value; }

	inline float GetRoll() const { return roll; }
	inline void SetRoll(const float value) { roll = value; }

protected:
	float pitch;
	float yaw;
	float roll;
};

stringStream& operator << (stringStream& stream, const EAngle &m);

GEndNameSpace()

#endif // __MATH__EANGLE__H__
