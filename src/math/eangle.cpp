#include "precomp.h"

#include "math/eangle.h"
#include "math/mathutil.h"

GBeginNameSpace()

EAngle::EAngle()
{
	pitch = yaw = roll = 0.0f;
}

EAngle::EAngle(const EAngle &other)
{
	pitch = other.pitch;
	yaw = other.yaw;
	roll = other.roll;
}

EAngle::EAngle(const Vector4f &v)
{
	LookAt(v);
	roll = 0.0f;
}

EAngle::EAngle(const gFloat p, const gFloat y, const gFloat r)
{
	pitch = p;
	yaw = y;
	roll = r;
}

EAngle::~EAngle()
{
}

void EAngle::Normalize()
{
	if (pitch > 89.f)
		pitch = 89.f;

	if (pitch < -89.f)
		pitch = -89.f;

	while (yaw < -180.f)
		yaw += 360.f;

	while (yaw > 180.f)
		yaw -= 360.f;
}

void EAngle::LookAt(const Vector4f &direction)
{
	gFloat x = direction[0];
	gFloat y = direction[1];
	gFloat z = direction[2];

	float r = sqrt(x * x + z * z);
	float yaw = atan2(z, x);
	float pitch = atan2(-y, r);

	this->yaw = toDegrees(yaw) + 90.f;
	this->pitch = toDegrees(pitch);
}

Vector4f EAngle::ToVector()
{
	Vector4f result;

	gFloat y = toRadians(yaw);
	gFloat p = toRadians(pitch);

	gFloat cosP = cos(p);
	gFloat X = cos(y) * cosP;
	gFloat Y = sin(p);
	gFloat Z = sin(y) * cosP;

	result.Set(X, Y, Z, 0.f);

	return result;
}

gStringStream& operator << (gStringStream& stream, const EAngle &m)
{
	stream << "EAngle [p:" << m.GetPitch() << ", y:" << m.GetYaw() << ", r:" << m.GetRoll() << "]";
	return stream;
}

GEndNameSpace()
