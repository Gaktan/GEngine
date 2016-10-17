#ifndef __MATH__VECTOR3__H__
#define __MATH__VECTOR3__H__

#include "math/mathutil.h"

GBeginNameSpace()

// Forward declaration
template<typename T>
class Vector4;

template<typename T>
class Vector3
{
public:
	inline Vector3()
	{
		Set(0, 0, 0);
	}

	template<typename R>
	inline Vector3(const Vector3<R> &v)
	{
		Set(v);
	}

	inline Vector3(const T x, const T y, const T z)
	{
		Set(x, y, z);
	}

	inline Vector3(const T (&a) [3])
	{
		Set(a[0], a[1], a[2]);
	}

	virtual inline ~Vector3()
	{
	}

	// -- Operators

	template<typename R>
	inline Vector3<T>& operator = (const Vector3<R> &v)
	{
		Set(v);

		return *this;
	}

	template<typename R>
	inline gBool operator == (const Vector3<R> &v) const
	{
		return equals(x, v.x) && equals(y, v.y) && equals(z, v.z);
	}

	inline gBool operator == (const T (&a) [3]) const
	{
		return equals(x, a[0]) && equals(y, a[1]) && equals(z, a[2]);
	}

	template<typename R>
	inline gBool operator != (const Vector3<R> &v) const
	{
		return !(*this == v);
	}

	inline gBool operator != (const T (&a) [3]) const
	{
		return !(*this == a);
	}

	inline const T& operator [] (const gIndex index) const
	{
		assert(index >= 0 && index < 3);
		return buffer[index];
	}

	inline T& operator [] (const gIndex index)
	{
		assert(index >= 0 && index < 3);
		return buffer[index];
	}

	inline const T& operator() (const gIndex index) const
	{
		assert(index >= 0 && index < 3);
		return buffer[index];
	}

	inline T& operator() (const gIndex index)
	{
		assert(index >= 0 && index < 3);
		return buffer[index];
	}

	friend ostream& operator << (ostream& os, const Vector3<T> &v)
	{
		// write obj to stream
		os << "[";
		for (int i = 0; i < 3; i++)
		{
			os << v[i];
			os << (i != 2 ? ", " : "]");
		}
		return os;
	}

	// --

	template<typename R>
	inline void Set(const Vector3<R> &v)
	{
		Set(v.x, v.y, v.z);
	}

	inline void Set(const T x, const T y, const T z)
	{
		this->x = x;
		this->y = y;
		this->z = z;
	}

	template<typename R>
	inline void Set(const Vector4<R> &v)
	{
		Set(v.x, v.y, v.z);
	}

	inline T Length() const
	{
		return sqrt(LengthSquared());
	}

	inline T LengthSquared() const
	{
		return x*x + y*y + z*z;
	}

	inline Vector3<T> Normalize() const
	{
		const T length = fastInvSqrt(LengthSquared());
		return Mul(length);
	}

	template<typename R>
	inline Vector3<T> Add(const Vector3<R> &v) const
	{
		return Vector3<T>(x + v.x, y + v.y, z + v.z);
	}

	template<typename R>
	inline Vector3<T> Add(const R v) const
	{
		return Vector3<T>(x + v, y + v, z + v);
	}

	template<typename R>
	inline Vector3<T> Sub(const Vector3<R> &v) const
	{
		return Vector3<T>(x - v.x, y - v.y, z - v.z);
	}

	template<typename R>
	inline Vector3<T> Sub(const R v) const
	{
		return Vector3<T>(x - v, y - v, z - v);
	}

	template<typename R>
	inline Vector3<T> Mul(const Vector3<R> &v) const
	{
		return Vector3<T>(x * v.x, y * v.y, z * v.z);
	}

	template<typename R>
	inline Vector3<T> Mul(const R v) const
	{
		return Vector3<T>(x * v, y * v, z * v);
	}

	template<typename R>
	inline Vector3<T> Div(const R v) const
	{
		const T d = 1 / v;
		return Mul(d);
	}

	template<typename R>
	inline T Dot(const Vector3<R> &v) const
	{
		return x * v.x + y * v.y + z * v.z;
	}

	template<typename R>
	inline Vector3<T> Cross(const Vector3<R> &v) const
	{
		T x1 = (y * v.z) - (z * v.y);
		T y1 = (z * v.x) - (x * v.z);
		T z1 = (x * v.y) - (y * v.x);

		return Vector3<T>(x1, y1, z1);
	}

	template<typename R>
	inline gBool InRange(const R v) const
	{
		const R d = v * v;
		return (LengthSquared() < d);
	}

protected:
	union
	{
		struct
		{
			T x;
			T y;
			T z;
		};

		T buffer[3];
	};


};

// --------------
// -- + PLUS + --
// --------------

template<typename T>
inline Vector3<T> operator + (const Vector3<T> &a, const Vector3<T> &b)
{
	return a.Add(b);
}

template<typename T>
inline const Vector3<T> operator + (const Vector3<T> &a, const T b)
{
	return a.Add(b);
}

template<typename T>
inline const Vector3<T> operator + (const T a, const Vector3<T> &b)
{
	return b + a;
}

template<typename T>
inline Vector3<T>& operator += (Vector3<T> &a, const Vector3<T> &b)
{
	return a = a + b;
}

template<typename T>
inline const Vector3<T> operator += (Vector3<T> &a, const T b)
{
	return a = a + b;
}

// ---------------
// -- - MINUS - --
// ---------------

template<typename T>
inline const Vector3<T> operator - (const Vector3<T> &a, const Vector3<T> &b)
{
	return a.Sub(b);
}

template<typename T>
inline const Vector3<T> operator - (const Vector3<T> &a, const T b)
{
	return a.Sub(b);
}

template<typename T>
inline const Vector3<T> operator - (const T a, const Vector3<T> &b)
{
	const T x = a - b[0];
	const T y = a - b[1];
	const T z = a - b[2];

	return Vector3<T>(x, y, z);
}

template<typename T>
inline Vector3<T>& operator -= (Vector3<T> &a, const Vector3<T> &b)
{
	return a = a - b;
}

template<typename T>
inline const Vector3<T> operator -= (Vector3<T> &a, const T b)
{
	return a = a - b;
}

// ------------------
// -- * MULTIPLY * --
// ------------------

// Cross product. Use Multiply() for an actual multiplication
template<typename T>
inline const Vector3<T> operator * (const Vector3<T> &a, const Vector3<T> &b)
{
	return a.Cross(b);
}

template<typename T>
inline const Vector3<T> operator * (const Vector3<T> &a, const T b)
{
	return a.Mul(b);
}

template<typename T>
inline const Vector3<T> operator * (const T a, const Vector3<T> &b)
{
	return b * a;
}

template<typename T>
inline const Vector3<T> operator *= (Vector3<T> &a, const T b)
{
	return a = a * b;
}


// ----------------
// -- * DIVIDE * --
// ----------------

template<typename T>
inline const Vector3<T> operator / (const Vector3<T> &a, const T b)
{
	return a.Div(b);
}

template<typename T>
inline const Vector3<T> operator / (const T a, const Vector3<T> &b)
{
	const T x = a / b[0];
	const T y = a / b[1];
	const T z = a / b[2];

	return Vector3<T>(x, y, z);
}

template<typename T>
inline const Vector3<T> operator /= (Vector3<T> &a, const T b)
{
	return a = a / b;
}

class Vector3f : public Vector3<gFloat>
{
public:

	inline Vector3f()
	{
		Set(0.f, 0.f, 0.f);
	}

	template<typename R>
	inline Vector3f(const Vector3<R> &v)
	{
		Set(v);
	}

	inline Vector3f(const gFloat x, const gFloat y, const gFloat z)
	{
		Set(x, y, z);
	}
};

class Vector3i : public Vector3<gInt>
{
public:

	inline Vector3i()
	{
		Set(0, 0, 0);
	}

	template<typename R>
	inline Vector3i(const Vector3<R> &v)
	{
		Set(v);
	}

	inline Vector3i(const gInt x, const gInt y, const gInt z)
	{
		Set(x, y, z);
	}
};

GEndNameSpace()

#endif // __MATH__VECTOR3__H__
