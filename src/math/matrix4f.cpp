#include "matrix4f.h"

#include "math/mathutil.h"

#include <iomanip>

#define FOR_EACH_START(array, name) auto *name##__it = array.begin(); \
	auto *name##__end = array.end(); \
	for (; name##__it < name##__end; name##__it++) \
	{ \
		auto& name = *name##__it;

#define FOR_EACH_END }

GBeginNameSpace()

Matrix4f::Matrix4f(gBool identity /*= true*/)
{
	if (identity)
	{
		SetIdentity();
	}
	else
	{
		FOR_EACH_START(M, f)
		{
			f = 0.f;
		}
		FOR_EACH_END
	}
}

Matrix4f::Matrix4f(const MAT_ARRAY &a)
{
	M = a;
}

Matrix4f::Matrix4f(const MAT_ARRAY_2D &a)
{
	m = a;
}

Matrix4f::Matrix4f(const Matrix4f &mat)
{
	M = mat.M;
}

Matrix4f::~Matrix4f()
{
	//dtor
}

ostream& operator << (ostream& os, const Matrix4f &m)
{
	os << "{" << std::endl;
	for (gIndex i = 0; i < 4; ++i)
	{
		for (gIndex j = 0; j < 4; ++j)
		{
			os << std::setw(16) << m.m[i][j];
		}
		os << std::endl;
	}
	os << std::setw(0) << "}" << std::endl;
	return os;
}

gBool Matrix4f::Equals(const MAT_ARRAY_2D &a, const gFloat epsilon) const
{
	gIndex i = 0;
	FOR_EACH_START(m, m0)
	{
		gIndex j = 0;

		FOR_EACH_START(m0, f)
		{
			gBool b = equals(f, a[i][j], epsilon);
			if (!b)
			{
				std::cout << "(" << i << ", " << j << "), " << f << ", " << a[i][j] << ", " << std::endl;
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
	FOR_EACH_START(M, f)
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

Matrix4f Matrix4f::Mul(const MAT_ARRAY_2D &a) const
{
	Matrix4f m(*this);
	return m;
}

Matrix4f Matrix4f::Mul(const MAT_ARRAY &a) const
{
	Matrix4f m(*this);
	return m;
}

Matrix4f Matrix4f::Mul(const Matrix4f &mat) const
{
	Matrix4f ret(*this);

	gFloat _m00 = m00 * mat.m00 + m10 * mat.m01 + m20 * mat.m02 + m30 * mat.m03;
	gFloat _m01 = m01 * mat.m00 + m11 * mat.m01 + m21 * mat.m02 + m31 * mat.m03;
	gFloat _m02 = m02 * mat.m00 + m12 * mat.m01 + m22 * mat.m02 + m32 * mat.m03;
	gFloat _m03 = m03 * mat.m00 + m13 * mat.m01 + m23 * mat.m02 + m33 * mat.m03;
	gFloat _m10 = m00 * mat.m10 + m10 * mat.m11 + m20 * mat.m12 + m30 * mat.m13;
	gFloat _m11 = m01 * mat.m10 + m11 * mat.m11 + m21 * mat.m12 + m31 * mat.m13;
	gFloat _m12 = m02 * mat.m10 + m12 * mat.m11 + m22 * mat.m12 + m32 * mat.m13;
	gFloat _m13 = m03 * mat.m10 + m13 * mat.m11 + m23 * mat.m12 + m33 * mat.m13;
	gFloat _m20 = m00 * mat.m20 + m10 * mat.m21 + m20 * mat.m22 + m30 * mat.m23;
	gFloat _m21 = m01 * mat.m20 + m11 * mat.m21 + m21 * mat.m22 + m31 * mat.m23;
	gFloat _m22 = m02 * mat.m20 + m12 * mat.m21 + m22 * mat.m22 + m32 * mat.m23;
	gFloat _m23 = m03 * mat.m20 + m13 * mat.m21 + m23 * mat.m22 + m33 * mat.m23;
	gFloat _m30 = m00 * mat.m30 + m10 * mat.m31 + m20 * mat.m32 + m30 * mat.m33;
	gFloat _m31 = m01 * mat.m30 + m11 * mat.m31 + m21 * mat.m32 + m31 * mat.m33;
	gFloat _m32 = m02 * mat.m30 + m12 * mat.m31 + m22 * mat.m32 + m32 * mat.m33;
	gFloat _m33 = m03 * mat.m30 + m13 * mat.m31 + m23 * mat.m32 + m33 * mat.m33;

	ret.m00 = _m00;
	ret.m01 = _m01;
	ret.m02 = _m02;
	ret.m03 = _m03;
	ret.m10 = _m10;
	ret.m11 = _m11;
	ret.m12 = _m12;
	ret.m13 = _m13;
	ret.m20 = _m20;
	ret.m21 = _m21;
	ret.m22 = _m22;
	ret.m23 = _m23;
	ret.m30 = _m30;
	ret.m31 = _m31;
	ret.m32 = _m32;
	ret.m33 = _m33;

	return ret;
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


GEndNameSpace()
