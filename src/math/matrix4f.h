#ifndef __MATH__MATRIX4F__H__
#define __MATH__MATRIX4F__H__

#include <array>

#define MAT_ARRAY_2D 		gArray<std::array<gFloat, 4>, 4>
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

	gBool Equals(const MAT_ARRAY_2D &a, const gFloat epsilon = 0.001f) const;
	gBool Equals(const MAT_ARRAY &a, const gFloat epsilon = 0.001f) const;
	gBool Equals(const Matrix4f &mat, const gFloat epsilon = 0.001f) const;

	Matrix4f Mul(const MAT_ARRAY_2D &a) const;
	Matrix4f Mul(const MAT_ARRAY &a) const;
	Matrix4f Mul(const Matrix4f &mat) const;

	gBool operator == (const MAT_ARRAY_2D &a) const;
	gBool operator == (const MAT_ARRAY &a) const;
	gBool operator == (const Matrix4f &mat) const;

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

ostream& operator << (ostream& os, const Matrix4f &m);

GEndNameSpace()

#endif // __MATH__MATRIX4F__H__
