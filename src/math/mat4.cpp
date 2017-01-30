#include "precomp.h"

#include "math/mat4.h"
#include "math/mathutil.h"

#include <iomanip>

#define FOR_EACH_START(name, array) auto name##__it = array.begin(); \
	auto name##__end = array.end(); \
	for (; name##__it < name##__end; name##__it++) \
	{ \
		auto& name = *name##__it;

#define FOR_EACH_END }

GBeginNameSpace()

Mat4::~Mat4()
{
}

Mat4::Mat4(bool identity /*= true*/)
{
	if (identity)
	{
		SetIdentity();
	}
	else
	{
		FOR_EACH_START(f, M)
		{
			f = 0.f;
		}
		FOR_EACH_END
	}
}

Mat4::Mat4(const MAT_ARRAY &a)
{
	Set(a);
}

Mat4::Mat4(const MAT_ARRAY_2D &a)
{
	Set(a);
}

Mat4::Mat4(const Mat4 &mat)
{
	Set(mat);
}

void Mat4::Set(const MAT_ARRAY_2D &a)
{
	m = a;
}

void Mat4::Set(const MAT_ARRAY &a)
{
	M = a;
}

void Mat4::Set(const Mat4 &mat)
{
	M = mat.M;
}

void Mat4::SetIdentity()
{
	m00 = 1.0f;
	m01 = 0.0f;
	m02 = 0.0f;
	m03 = 0.0f;
	m10 = 0.0f;
	m11 = 1.0f;
	m12 = 0.0f;
	m13 = 0.0f;
	m20 = 0.0f;
	m21 = 0.0f;
	m22 = 1.0f;
	m23 = 0.0f;
	m30 = 0.0f;
	m31 = 0.0f;
	m32 = 0.0f;
	m33 = 1.0f;
}

bool Mat4::Equals(const MAT_ARRAY_2D &a, const float epsilon) const
{
	ui8 i = 0;
	FOR_EACH_START(m0, m)
	{
		ui8 j = 0;

		FOR_EACH_START(f, m0)
		{
			bool b = equals(f, a[i][j], epsilon);
			if (!b)
			{
				return false;
			}

			j++;
		}
		FOR_EACH_END

		i++;
	}
	FOR_EACH_END

	return true;
}

bool Mat4::Equals(const MAT_ARRAY &a, const float epsilon) const
{
	ui8 i = 0;
	FOR_EACH_START(f, M)
	{
		bool b = equals(f, a[i], epsilon);
		if (!b)
			return false;
		i++;
	}
	FOR_EACH_END

	return true;
}

bool Mat4::Equals(const Mat4 &mat, const float epsilon) const
{
	return Equals(mat.M, epsilon);
}

void Mat4::Mul(const MAT_ARRAY_2D &a)
{
	float _m00 = m00 * a[0][0] + m10 * a[0][1] + m20 * a[0][2] + m30 * a[0][3];
	float _m01 = m01 * a[0][0] + m11 * a[0][1] + m21 * a[0][2] + m31 * a[0][3];
	float _m02 = m02 * a[0][0] + m12 * a[0][1] + m22 * a[0][2] + m32 * a[0][3];
	float _m03 = m03 * a[0][0] + m13 * a[0][1] + m23 * a[0][2] + m33 * a[0][3];
	float _m10 = m00 * a[1][0] + m10 * a[1][1] + m20 * a[1][2] + m30 * a[1][3];
	float _m11 = m01 * a[1][0] + m11 * a[1][1] + m21 * a[1][2] + m31 * a[1][3];
	float _m12 = m02 * a[1][0] + m12 * a[1][1] + m22 * a[1][2] + m32 * a[1][3];
	float _m13 = m03 * a[1][0] + m13 * a[1][1] + m23 * a[1][2] + m33 * a[1][3];
	float _m20 = m00 * a[2][0] + m10 * a[2][1] + m20 * a[2][2] + m30 * a[2][3];
	float _m21 = m01 * a[2][0] + m11 * a[2][1] + m21 * a[2][2] + m31 * a[2][3];
	float _m22 = m02 * a[2][0] + m12 * a[2][1] + m22 * a[2][2] + m32 * a[2][3];
	float _m23 = m03 * a[2][0] + m13 * a[2][1] + m23 * a[2][2] + m33 * a[2][3];
	float _m30 = m00 * a[3][0] + m10 * a[3][1] + m20 * a[3][2] + m30 * a[3][3];
	float _m31 = m01 * a[3][0] + m11 * a[3][1] + m21 * a[3][2] + m31 * a[3][3];
	float _m32 = m02 * a[3][0] + m12 * a[3][1] + m22 * a[3][2] + m32 * a[3][3];
	float _m33 = m03 * a[3][0] + m13 * a[3][1] + m23 * a[3][2] + m33 * a[3][3];

	m00 = _m00;
	m01 = _m01;
	m02 = _m02;
	m03 = _m03;
	m10 = _m10;
	m11 = _m11;
	m12 = _m12;
	m13 = _m13;
	m20 = _m20;
	m21 = _m21;
	m22 = _m22;
	m23 = _m23;
	m30 = _m30;
	m31 = _m31;
	m32 = _m32;
	m33 = _m33;
}

void Mat4::Mul(const MAT_ARRAY &a)
{

	float _m00 = m00 * a[0] + m10 * a[1] + m20 * a[2] + m30 * a[3];
	float _m01 = m01 * a[0] + m11 * a[1] + m21 * a[2] + m31 * a[3];
	float _m02 = m02 * a[0] + m12 * a[1] + m22 * a[2] + m32 * a[3];
	float _m03 = m03 * a[0] + m13 * a[1] + m23 * a[2] + m33 * a[3];
	float _m10 = m00 * a[4] + m10 * a[5] + m20 * a[6] + m30 * a[7];
	float _m11 = m01 * a[4] + m11 * a[5] + m21 * a[6] + m31 * a[7];
	float _m12 = m02 * a[4] + m12 * a[5] + m22 * a[6] + m32 * a[7];
	float _m13 = m03 * a[4] + m13 * a[5] + m23 * a[6] + m33 * a[7];
	float _m20 = m00 * a[8] + m10 * a[9] + m20 * a[10] + m30 * a[11];
	float _m21 = m01 * a[8] + m11 * a[9] + m21 * a[10] + m31 * a[11];
	float _m22 = m02 * a[8] + m12 * a[9] + m22 * a[10] + m32 * a[11];
	float _m23 = m03 * a[8] + m13 * a[9] + m23 * a[10] + m33 * a[11];
	float _m30 = m00 * a[12] + m10 * a[13] + m20 * a[14] + m30 * a[15];
	float _m31 = m01 * a[12] + m11 * a[13] + m21 * a[14] + m31 * a[15];
	float _m32 = m02 * a[12] + m12 * a[13] + m22 * a[14] + m32 * a[15];
	float _m33 = m03 * a[12] + m13 * a[13] + m23 * a[14] + m33 * a[15];

	m00 = _m00;
	m01 = _m01;
	m02 = _m02;
	m03 = _m03;
	m10 = _m10;
	m11 = _m11;
	m12 = _m12;
	m13 = _m13;
	m20 = _m20;
	m21 = _m21;
	m22 = _m22;
	m23 = _m23;
	m30 = _m30;
	m31 = _m31;
	m32 = _m32;
	m33 = _m33;
}

void Mat4::Mul(const Mat4 &mat)
{
	Mul(mat.M);
}

Vec4f Mat4::Mul(const Vec4f &v) const
{
	Vec4f ret(v);

	for (ui8 i = 0; i < 4; ++i)
	{
		float res = 0.f;
		res += m[i][0] * v[0];
		res += m[i][1] * v[1];
		res += m[i][2] * v[2];
		res += m[i][3] * v[3];

		ret[i] = res;
	}

	return ret;
}

void Mat4::Rotate(const float angleInRadian, Vec4f &axis)
{
	float c = cos(angleInRadian);
	float s = sin(angleInRadian);
	float oneminusc = 1.0f - c;

	float x = axis[0];
	float y = axis[1];
	float z = axis[2];

	float xy = x * y;
	float yz = y * z;
	float xz = x * z;
	float xs = x * s;
	float ys = y * s;
	float zs = z * s;

	float f00 = x * x * oneminusc + c;
	float f01 = xy * oneminusc + zs;
	float f02 = xz * oneminusc - ys;
	// n[3] not used
	float f10 = xy * oneminusc - zs;
	float f11 = y * y * oneminusc + c;
	float f12 = yz * oneminusc + xs;
	// n[7] not used
	float f20 = xz * oneminusc + ys;
	float f21 = yz * oneminusc - xs;
	float f22 = z * z * oneminusc + c;

	float t00 = m00 * f00 + m10 * f01 + m20 * f02;
	float t01 = m01 * f00 + m11 * f01 + m21 * f02;
	float t02 = m02 * f00 + m12 * f01 + m22 * f02;
	float t03 = m03 * f00 + m13 * f01 + m23 * f02;
	float t10 = m00 * f10 + m10 * f11 + m20 * f12;
	float t11 = m01 * f10 + m11 * f11 + m21 * f12;
	float t12 = m02 * f10 + m12 * f11 + m22 * f12;
	float t13 = m03 * f10 + m13 * f11 + m23 * f12;

	m20 = m00 * f20 + m10 * f21 + m20 * f22;
	m21 = m01 * f20 + m11 * f21 + m21 * f22;
	m22 = m02 * f20 + m12 * f21 + m22 * f22;
	m23 = m03 * f20 + m13 * f21 + m23 * f22;
	m00 = t00;
	m01 = t01;
	m02 = t02;
	m03 = t03;
	m10 = t10;
	m11 = t11;
	m12 = t12;
	m13 = t13;
}

void Mat4::Translate(const Vec4f &pos)
{
	float x = pos[0];
	float y = pos[1];
	float z = pos[2];

	m30 += m00 * x + m10 * y + m20 * z;
	m31 += m01 * x + m11 * y + m21 * z;
	m32 += m02 * x + m12 * y + m22 * z;
	m33 += m03 * x + m13 * y + m23 * z;
}

float Mat4::Get(const ui8 x) const
{
	assert(x >= 0 && x < 16);
	return M[x];
}

float Mat4::Get(const ui8 x, const ui8 y) const
{
	assert(x >= 0 && x < 4);
	assert(y >= 0 && y < 4);
	return m[x][y];
}

const MAT_ARRAY_2D_X& Mat4::GetLine(const ui8 x) const
{
	assert(x >= 0 && x < 4);
	return m[x];
}

MAT_ARRAY_2D_X& Mat4::GetLine(const ui8 x)
{
	assert(x >= 0 && x < 4);
	return m[x];
}

MAT_ARRAY_2D_X& Mat4::operator [] (const ui8 x)
{
	return GetLine(x);
}

const MAT_ARRAY_2D_X& Mat4::operator [] (const ui8 x) const
{
	return GetLine(x);
}

MAT_ARRAY_2D_X& Mat4::operator () (const ui8 x)
{
	return GetLine(x);
}

const MAT_ARRAY_2D_X& Mat4::operator () (const ui8 x) const
{
	return GetLine(x);
}

bool Mat4::operator == (const MAT_ARRAY_2D &a) const
{
	return m == a;
}

bool Mat4::operator == (const MAT_ARRAY &a) const
{
	return M == a;
}

bool Mat4::operator == (const Mat4 &mat) const
{
	return Equals(mat);
}

Mat4& Mat4::operator = (const MAT_ARRAY_2D &a)
{
	Set(a);

	return *this;
}

Mat4& Mat4::operator = (const MAT_ARRAY &a)
{
	Set(a);

	return *this;
}

Mat4& Mat4::operator = (const Mat4 &mat)
{
	Set(mat);

	return *this;
}

stringStream& operator << (stringStream& stream, const Mat4 &m)
{
	stream << "{" << endl;
	for (ui8 i = 0; i < 4; ++i)
	{
		for (ui8 j = 0; j < 4; ++j)
		{
			stream << std::setw(16) << m.m[i][j];
		}
		stream << endl;
	}
	stream << std::setw(0) << "}" << endl;
	return stream;
}

Mat4 Mat4::operator * (const Mat4 &mat)
{
	Mat4 ret(*this);
	ret.Mul(mat);
	return ret;
}

Vec4f Mat4::operator * (const Vec4f &vec)
{
	Mat4 ret(*this);
	return ret.Mul(vec);
}

GEndNameSpace()
