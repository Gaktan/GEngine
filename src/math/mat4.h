#ifndef __MATH__Mat4__H__
#define __MATH__Mat4__H__

#include "math/vector4.h"

#define MAT_ARRAY_2D_X		array<float, 4>
#define MAT_ARRAY_2D 		array<MAT_ARRAY_2D_X, 4>
#define MAT_ARRAY 			array<float, 16>

GBeginNameSpace()

class Mat4
{
public:
	Mat4(bool identity = true);
	Mat4(const MAT_ARRAY_2D &a);
	Mat4(const MAT_ARRAY &a);
	Mat4(const Mat4 &mat);
	virtual ~Mat4();

	void SetIdentity();
	void Set(const MAT_ARRAY_2D &a);
	void Set(const MAT_ARRAY &a);
	void Set(const Mat4 &mat);

	bool Equals(const MAT_ARRAY_2D &a, const float epsilon = 0.001f) const;
	bool Equals(const MAT_ARRAY &a, const float epsilon = 0.001f) const;
	bool Equals(const Mat4 &mat, const float epsilon = 0.001f) const;

	void Rotate(const float angleInRadian, Vec4f &axis);
	void Translate(const Vec4f &pos);

	void Mul(const MAT_ARRAY_2D &a);
	void Mul(const MAT_ARRAY &a);
	void Mul(const Mat4 &mat);
	Vec4f Mul(const Vec4f &v) const;

	float Get(const ui8 x) const;
	float Get(const ui8 x, const ui8 y) const;
	const MAT_ARRAY_2D_X& GetLine(const ui8 x) const;
	MAT_ARRAY_2D_X& GetLine(const ui8 x);

	MAT_ARRAY_2D_X& operator [] (const ui8 x);
	const MAT_ARRAY_2D_X& operator [] (const ui8 x) const;
	MAT_ARRAY_2D_X& operator () (const ui8 x);
	const MAT_ARRAY_2D_X& operator () (const ui8 x) const;

	bool operator == (const MAT_ARRAY_2D &a) const;
	bool operator == (const MAT_ARRAY &a) const;
	bool operator == (const Mat4 &mat) const;

	Mat4& operator = (const MAT_ARRAY_2D &a);
	Mat4& operator = (const MAT_ARRAY &a);
	Mat4& operator = (const Mat4 &mat);

	Mat4 operator * (const Mat4 &mat);
	Vec4f operator * (const Vec4f &vec);

	union
	{
		MAT_ARRAY_2D m;
		MAT_ARRAY M;

		struct
		{
			float m00, m10, m20, m30;
			float m01, m11, m21, m31;
			float m02, m12, m22, m32;
			float m03, m13, m23, m33;
		};
	};
};

stringStream& operator << (stringStream& stream, const Mat4 &m);

GEndNameSpace()

#endif // __MATH__Mat4__H__
