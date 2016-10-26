#ifndef __MATH__EANGLE__H__
#define __MATH__EANGLE__H__

#include "vector4.h"

GBeginNameSpace()

class EAngle
{
public:
	EAngle();
	EAngle(const EAngle &other);
	EAngle(const Vector4f &v);
	EAngle(const gFloat p, const gFloat y, const gFloat r);
	virtual ~EAngle();

	void Normalize();
	void LookAt(const Vector4f &direction);

	Vector4f ToVector();

	inline gFloat GetPitch() const { return pitch; }
	inline void SetPitch(const gFloat value) { pitch = value; }

	inline gFloat GetYaw() const { return yaw; }
	inline void SetYaw(const gFloat value) { yaw = value; }

	inline gFloat GetRoll() const { return roll; }
	inline void SetRoll(const gFloat value) { roll = value; }

protected:
	gFloat pitch;
	gFloat yaw;
	gFloat roll;
};

gStringStream& operator << (gStringStream& stream, const EAngle &m);

GEndNameSpace()

#endif // __MATH__EANGLE__H__
