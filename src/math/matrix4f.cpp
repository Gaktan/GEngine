#include "precomp.h"

#include "math/matrix4f.h"
#include "math/mathutil.h"

#include <iomanip>

#define FOR_EACH_START(name, array) auto name##__it = array.begin(); \
	auto name##__end = array.end(); \
	for (; name##__it < name##__end; name##__it++) \
	{ \
		auto& name = *name##__it;

#define FOR_EACH_END }

GBeginNameSpace()

Matrix4f::~Matrix4f()
{
}

Matrix4f::Matrix4f(gBool identity /*= true*/)
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

Matrix4f::Matrix4f(const MAT_ARRAY &a)
{
	Set(a);
}

Matrix4f::Matrix4f(const MAT_ARRAY_2D &a)
{
	Set(a);
}

Matrix4f::Matrix4f(const Matrix4f &mat)
{
	Set(mat);
}

void Matrix4f::Set(const MAT_ARRAY_2D &a)
{
	m = a;
}

void Matrix4f::Set(const MAT_ARRAY &a)
{
	M = a;
}

void Matrix4f::Set(const Matrix4f &mat)
{
	M = mat.M;
}

void Matrix4f::SetIdentity()
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

gBool Matrix4f::Equals(const MAT_ARRAY_2D &a, const gFloat epsilon) const
{
	gIndex i = 0;
	FOR_EACH_START(m0, m)
	{
		gIndex j = 0;

		FOR_EACH_START(f, m0)
		{
			gBool b = equals(f, a[i][j], epsilon);
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

gBool Matrix4f::Equals(const MAT_ARRAY &a, const gFloat epsilon) const
{
	gIndex i = 0;
	FOR_EACH_START(f, M)
	{
		gBool b = equals(f, a[i], epsilon);
		if (!b)
			return false;
		i++;
	}
	FOR_EACH_END

	return true;
}

gBool Matrix4f::Equals(const Matrix4f &mat, const gFloat epsilon) const
{
	return Equals(mat.M, epsilon);
}

void Matrix4f::Mul(const MAT_ARRAY_2D &a)
{
	gFloat _m00 = m00 * a[0][0] + m10 * a[0][1] + m20 * a[0][2] + m30 * a[0][3];
	gFloat _m01 = m01 * a[0][0] + m11 * a[0][1] + m21 * a[0][2] + m31 * a[0][3];
	gFloat _m02 = m02 * a[0][0] + m12 * a[0][1] + m22 * a[0][2] + m32 * a[0][3];
	gFloat _m03 = m03 * a[0][0] + m13 * a[0][1] + m23 * a[0][2] + m33 * a[0][3];
	gFloat _m10 = m00 * a[1][0] + m10 * a[1][1] + m20 * a[1][2] + m30 * a[1][3];
	gFloat _m11 = m01 * a[1][0] + m11 * a[1][1] + m21 * a[1][2] + m31 * a[1][3];
	gFloat _m12 = m02 * a[1][0] + m12 * a[1][1] + m22 * a[1][2] + m32 * a[1][3];
	gFloat _m13 = m03 * a[1][0] + m13 * a[1][1] + m23 * a[1][2] + m33 * a[1][3];
	gFloat _m20 = m00 * a[2][0] + m10 * a[2][1] + m20 * a[2][2] + m30 * a[2][3];
	gFloat _m21 = m01 * a[2][0] + m11 * a[2][1] + m21 * a[2][2] + m31 * a[2][3];
	gFloat _m22 = m02 * a[2][0] + m12 * a[2][1] + m22 * a[2][2] + m32 * a[2][3];
	gFloat _m23 = m03 * a[2][0] + m13 * a[2][1] + m23 * a[2][2] + m33 * a[2][3];
	gFloat _m30 = m00 * a[3][0] + m10 * a[3][1] + m20 * a[3][2] + m30 * a[3][3];
	gFloat _m31 = m01 * a[3][0] + m11 * a[3][1] + m21 * a[3][2] + m31 * a[3][3];
	gFloat _m32 = m02 * a[3][0] + m12 * a[3][1] + m22 * a[3][2] + m32 * a[3][3];
	gFloat _m33 = m03 * a[3][0] + m13 * a[3][1] + m23 * a[3][2] + m33 * a[3][3];

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

void Matrix4f::Mul(const MAT_ARRAY &a)
{

	gFloat _m00 = m00 * a[0] + m10 * a[1] + m20 * a[2] + m30 * a[3];
	gFloat _m01 = m01 * a[0] + m11 * a[1] + m21 * a[2] + m31 * a[3];
	gFloat _m02 = m02 * a[0] + m12 * a[1] + m22 * a[2] + m32 * a[3];
	gFloat _m03 = m03 * a[0] + m13 * a[1] + m23 * a[2] + m33 * a[3];
	gFloat _m10 = m00 * a[4] + m10 * a[5] + m20 * a[6] + m30 * a[7];
	gFloat _m11 = m01 * a[4] + m11 * a[5] + m21 * a[6] + m31 * a[7];
	gFloat _m12 = m02 * a[4] + m12 * a[5] + m22 * a[6] + m32 * a[7];
	gFloat _m13 = m03 * a[4] + m13 * a[5] + m23 * a[6] + m33 * a[7];
	gFloat _m20 = m00 * a[8] + m10 * a[9] + m20 * a[10] + m30 * a[11];
	gFloat _m21 = m01 * a[8] + m11 * a[9] + m21 * a[10] + m31 * a[11];
	gFloat _m22 = m02 * a[8] + m12 * a[9] + m22 * a[10] + m32 * a[11];
	gFloat _m23 = m03 * a[8] + m13 * a[9] + m23 * a[10] + m33 * a[11];
	gFloat _m30 = m00 * a[12] + m10 * a[13] + m20 * a[14] + m30 * a[15];
	gFloat _m31 = m01 * a[12] + m11 * a[13] + m21 * a[14] + m31 * a[15];
	gFloat _m32 = m02 * a[12] + m12 * a[13] + m22 * a[14] + m32 * a[15];
	gFloat _m33 = m03 * a[12] + m13 * a[13] + m23 * a[14] + m33 * a[15];

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

void Matrix4f::Mul(const Matrix4f &mat)
{
	Mul(mat.M);
}

Vector4f Matrix4f::Mul(const Vector4f &v) const
{
	Vector4f ret(v);

	for (gIndex i = 0; i < 4; ++i)
	{
		gFloat res = 0.f;
		res += m[i][0] * v[0];
		res += m[i][1] * v[1];
		res += m[i][2] * v[2];
		res += m[i][3] * v[3];

		ret[i] = res;
	}

	return ret;
}

void Matrix4f::Rotate(const gFloat angleInRadian, Vector4f &axis)
{
	gFloat c = cos(angleInRadian);
	gFloat s = sin(angleInRadian);
	gFloat oneminusc = 1.0f - c;

	gFloat x = axis[0];
	gFloat y = axis[1];
	gFloat z = axis[2];

	gFloat xy = x * y;
	gFloat yz = y * z;
	gFloat xz = x * z;
	gFloat xs = x * s;
	gFloat ys = y * s;
	gFloat zs = z * s;

	gFloat f00 = x * x * oneminusc + c;
	gFloat f01 = xy * oneminusc + zs;
	gFloat f02 = xz * oneminusc - ys;
	// n[3] not used
	gFloat f10 = xy * oneminusc - zs;
	gFloat f11 = y * y * oneminusc + c;
	gFloat f12 = yz * oneminusc + xs;
	// n[7] not used
	gFloat f20 = xz * oneminusc + ys;
	gFloat f21 = yz * oneminusc - xs;
	gFloat f22 = z * z * oneminusc + c;

	gFloat t00 = m00 * f00 + m10 * f01 + m20 * f02;
	gFloat t01 = m01 * f00 + m11 * f01 + m21 * f02;
	gFloat t02 = m02 * f00 + m12 * f01 + m22 * f02;
	gFloat t03 = m03 * f00 + m13 * f01 + m23 * f02;
	gFloat t10 = m00 * f10 + m10 * f11 + m20 * f12;
	gFloat t11 = m01 * f10 + m11 * f11 + m21 * f12;
	gFloat t12 = m02 * f10 + m12 * f11 + m22 * f12;
	gFloat t13 = m03 * f10 + m13 * f11 + m23 * f12;

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

void Matrix4f::Translate(const Vector4f &pos)
{
	gFloat x = pos[0];
	gFloat y = pos[1];
	gFloat z = pos[2];

	m30 += m00 * x + m10 * y + m20 * z;
	m31 += m01 * x + m11 * y + m21 * z;
	m32 += m02 * x + m12 * y + m22 * z;
	m33 += m03 * x + m13 * y + m23 * z;
}

gFloat Matrix4f::Get(const gIndex x) const
{
	assert(x >= 0 && x < 16);
	return M[x];
}

gFloat Matrix4f::Get(const gIndex x, const gIndex y) const
{
	assert(x >= 0 && x < 4);
	assert(y >= 0 && y < 4);
	return m[x][y];
}

const MAT_ARRAY_2D_X& Matrix4f::GetLine(const gIndex x) const
{
	assert(x >= 0 && x < 4);
	return m[x];
}

MAT_ARRAY_2D_X& Matrix4f::GetLine(const gIndex x)
{
	assert(x >= 0 && x < 4);
	return m[x];
}

MAT_ARRAY_2D_X& Matrix4f::operator [] (const gIndex x)
{
	return GetLine(x);
}

const MAT_ARRAY_2D_X& Matrix4f::operator [] (const gIndex x) const
{
	return GetLine(x);
}

MAT_ARRAY_2D_X& Matrix4f::operator () (const gIndex x)
{
	return GetLine(x);
}

const MAT_ARRAY_2D_X& Matrix4f::operator () (const gIndex x) const
{
	return GetLine(x);
}

gBool Matrix4f::operator == (const MAT_ARRAY_2D &a) const
{
	return m == a;
}

gBool Matrix4f::operator == (const MAT_ARRAY &a) const
{
	return M == a;
}

gBool Matrix4f::operator == (const Matrix4f &mat) const
{
	return Equals(mat);
}

Matrix4f& Matrix4f::operator = (const MAT_ARRAY_2D &a)
{
	Set(a);

	return *this;
}

Matrix4f& Matrix4f::operator = (const MAT_ARRAY &a)
{
	Set(a);

	return *this;
}

Matrix4f& Matrix4f::operator = (const Matrix4f &mat)
{
	Set(mat);

	return *this;
}

gStringStream& operator << (gStringStream& stream, const Matrix4f &m)
{
	stream << "{" << endl;
	for (gIndex i = 0; i < 4; ++i)
	{
		for (gIndex j = 0; j < 4; ++j)
		{
			stream << std::setw(16) << m.m[i][j];
		}
		stream << endl;
	}
	stream << std::setw(0) << "}" << endl;
	return stream;
}

Matrix4f Matrix4f::operator * (const Matrix4f &mat)
{
	Matrix4f ret(*this);
	ret.Mul(mat);
	return ret;
}

Vector4f Matrix4f::operator * (const Vector4f &vec)
{
	Matrix4f ret(*this);
	return ret.Mul(vec);
}

GEndNameSpace()
