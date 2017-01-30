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

EAngle::EAngle(const Vec4f &v)
{
	LookAt(v);
	roll = 0.0f;
}

EAngle::EAngle(const float p, const float y, const float r)
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

void EAngle::LookAt(const Vec4f &direction)
{
	float x = direction[0];
	float y = direction[1];
	float z = direction[2];

	float r = sqrt(x * x + z * z);
	float yaw = atan2(z, x);
	float pitch = atan2(-y, r);

	this->yaw = toDegrees(yaw) + 90.f;
	this->pitch = toDegrees(pitch);
}

Vec4f EAngle::ToVector()
{
	Vec4f result;

	float y = toRadians(yaw);
	float p = toRadians(pitch);

	float cosP = cos(p);
	float X = cos(y) * cosP;
	float Y = sin(p);
	float Z = sin(y) * cosP;

	result.Set(X, Y, Z, 0.f);

	return result;
}

stringStream& operator << (stringStream& stream, const EAngle &m)
{
	stream << "EAngle [p:" << m.GetPitch() << ", y:" << m.GetYaw() << ", r:" << m.GetRoll() << "]";
	return stream;
}

GEndNameSpace()
