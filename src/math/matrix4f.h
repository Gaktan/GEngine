#ifndef __MATH__MATRIX4F__H__
#define __MATH__MATRIX4F__H__

#include "math/vector4.h"

#define MAT_ARRAY_2D_X		gArray<gFloat, 4>
#define MAT_ARRAY_2D 		gArray<MAT_ARRAY_2D_X, 4>
#define MAT_ARRAY 			gArray<gFloat, 16>

GBeginNameSpace()

class Matrix4f
{
public:
	Matrix4f(gBool identity = true);
	Matrix4f(const MAT_ARRAY_2D &a);
	Matrix4f(const MAT_ARRAY &a);
	Matrix4f(const Matrix4f &mat);
	virtual ~Matrix4f();

	void SetIdentity();
	void Set(const MAT_ARRAY_2D &a);
	void Set(const MAT_ARRAY &a);
	void Set(const Matrix4f &mat);

	gBool Equals(const MAT_ARRAY_2D &a, const gFloat epsilon = 0.001f) const;
	gBool Equals(const MAT_ARRAY &a, const gFloat epsilon = 0.001f) const;
	gBool Equals(const Matrix4f &mat, const gFloat epsilon = 0.001f) const;

	void Rotate(const gFloat angleInRadian, Vector4f &axis);
	void Translate(const Vector4f &pos);

	void Mul(const MAT_ARRAY_2D &a);
	void Mul(const MAT_ARRAY &a);
	void Mul(const Matrix4f &mat);
	Vector4f Mul(const Vector4f &v) const;

	gFloat Get(const gIndex x) const;
	gFloat Get(const gIndex x, const gIndex y) const;
	const MAT_ARRAY_2D_X& GetLine(const gIndex x) const;
	MAT_ARRAY_2D_X& GetLine(const gIndex x);

	MAT_ARRAY_2D_X& operator [] (const gIndex x);
	const MAT_ARRAY_2D_X& operator [] (const gIndex x) const;
	MAT_ARRAY_2D_X& operator () (const gIndex x);
	const MAT_ARRAY_2D_X& operator () (const gIndex x) const;

	gBool operator == (const MAT_ARRAY_2D &a) const;
	gBool operator == (const MAT_ARRAY &a) const;
	gBool operator == (const Matrix4f &mat) const;

	Matrix4f& operator = (const MAT_ARRAY_2D &a);
	Matrix4f& operator = (const MAT_ARRAY &a);
	Matrix4f& operator = (const Matrix4f &mat);

	union
	{
		MAT_ARRAY_2D m;
		MAT_ARRAY M;

		struct
		{
			gFloat m00, m10, m20, m30;
			gFloat m01, m11, m21, m31;
			gFloat m02, m12, m22, m32;
			gFloat m03, m13, m23, m33;
		};
	};
};

gStringStream& operator << (gStringStream& stream, const Matrix4f &m);

inline const Matrix4f operator * (const Matrix4f &a, const Matrix4f &b)
{
	Matrix4f ret(a);
	ret.Mul(b);
	return ret;
}

inline const Vector4f operator * (const Matrix4f &a, const Vector4f &b)
{
	return a.Mul(b);
}

GEndNameSpace()

#endif // __MATH__MATRIX4F__H__
