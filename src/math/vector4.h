#ifndef __MATH__VECTOR4__H__
#define __MATH__VECTOR4__H__

GBeginNameSpace()

// Forward declaration
template<typename T>
class Vector3;

template<typename T>
class Vector4
{
public:
	inline Vector4()
	{
		Set(0, 0, 0, 0);
	}

	template<typename R>
	inline Vector4(const Vector4<R> &v)
	{
		Set(v);
	}

	inline Vector4(const T &x, const T &y, const T &z, const T &w)
	{
		Set(x, y, z, w);
	}

	inline Vector4(const T (&a) [4])
	{
		Set(a[0], a[1], a[2], a[3]);
	}

	virtual inline ~Vector4()
	{
	}

	// -- Operators

	template<typename R>
	inline Vector4<T>& operator = (const Vector4<R> &v)
	{
		Set(v);

		return *this;
	}

	template<typename R>
	inline gBool operator == (const Vector4<R> &v) const
	{
		return equals(x, v.x) && equals(y, v.y) && equals(z, v.z) && equals(w, v.w);
	}

	inline gBool operator == (const T (&a) [4]) const
	{
		return equals(x, a[0]) && equals(y, a[1]) && equals(z, a[2]) && equals(w, a[3]);
	}

	template<typename R>
	inline gBool operator != (const Vector4<R> &v) const
	{
		return !(*this == v);
	}

	inline gBool operator != (const T (&a) [4]) const
	{
		return !(*this == a);
	}

	inline const T& operator [] (const gIndex index) const
	{
		assert(index >= 0 && index < 4);
		return buffer[index];
	}

	inline T& operator [] (const gIndex index)
	{
		assert(index >= 0 && index < 4);
		return buffer[index];
	}

	inline const T& operator() (const gIndex index) const
	{
		assert(index >= 0 && index < 4);
		return buffer[index];
	}

	inline T& operator() (const gIndex index)
	{
		assert(index >= 0 && index < 4);
		return buffer[index];
	}

	friend gStringStream& operator << (gStringStream& stream, const Vector4<T> &v)
	{
		// write obj to stream
		stream << "[";
		for (int i = 0; i < 4; i++)
		{
			stream << v[i];
			stream << (i != 3 ? ", " : "]");
		}
		return stream;
	}

	// --

	template<typename R>
	inline void Set(const Vector4<R> &v)
	{
		Set(v.x, v.y, v.z, v.w);
	}

	inline void Set(const T x, const T y, const T z, const T w)
	{
		this->x = x;
		this->y = y;
		this->z = z;
		this->w = w;
	}

	template<typename R>
	inline void Set(const Vector3<R> &v)
	{
		Set(v.x, v.y, v.z, 0.0);
	}

	inline T Length() const
	{
		return sqrt(LengthSquared());
	}

	inline T LengthSquared() const
	{
		return x*x + y*y + z*z + w*w;
	}

	inline Vector4<T> Normalize() const
	{
		const T length = fastInvSqrt(LengthSquared());
		return Mul(length);
	}

	template<typename R>
	inline Vector4<T> Add(const Vector4<R> &v) const
	{
		return Vector4<T>(x + v.x, y + v.y, z + v.z, w + v.w);
	}

	template<typename R>
	inline Vector4<T> Add(const R &v) const
	{
		return Vector4<T>(x + v, y + v, z + v, w + v);
	}

	template<typename R>
	inline Vector4<T> Sub(const Vector4<R> &v) const
	{
		return Vector4<T>(x - v.x, y - v.y, z - v.z, w - v.w);
	}

	template<typename R>
	inline Vector4<T> Sub(const R &v) const
	{
		return Vector4<T>(x - v, y - v, z - v, w - v);
	}

	template<typename R>
	inline Vector4<T> Mul(const Vector4<R> &v) const
	{
		return Vector4<T>(x * v.x, y * v.y, z * v.z, w * v.w);
	}

	template<typename R>
	inline Vector4<T> Mul(const R &v) const
	{
		return Vector4<T>(x * v, y * v, z * v, w * v);
	}

	template<typename R>
	inline Vector4<T> Div(const R &v) const
	{
		const T d = 1 / v;
		return Mul(d);
	}

	template<typename R>
	inline T Dot(const Vector4<R> &v) const
	{
		return x * v.x + y * v.y + z * v.z + w * v.w;
	}

	template<typename R>
	inline Vector4<T> Cross(const Vector4<R> &v) const
	{
		T x1 = (y * v.z) - (z * v.y);
		T y1 = (z * v.x) - (x * v.z);
		T z1 = (x * v.y) - (y * v.x);

		return Vector4<T>(x1, y1, z1, w);
	}

	template<typename R>
	inline gBool InRange(const R &v) const
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
			T w;
		};
		T buffer[4];
	};
};

// --------------
// -- + PLUS + --
// --------------

template<typename T>
inline Vector4<T> operator + (const Vector4<T> &a, const Vector4<T> &b)
{
	return Vector4<T>(a).Add(b);
}

template<typename T>
inline const Vector4<T> operator + (const Vector4<T> &a, const T &b)
{
	return Vector4<T>(a).Add(b);
}

template<typename T>
inline const Vector4<T> operator + (const T &a, const Vector4<T> &b)
{
	return b + a;
}

template<typename T>
inline Vector4<T>& operator += (Vector4<T> &a, const Vector4<T> &b)
{
	return a = a + b;
}

template<typename T>
inline const Vector4<T> operator += (Vector4<T> &a, const T &b)
{
	return a = a + b;
}

// ---------------
// -- - MINUS - --
// ---------------

template<typename T>
inline const Vector4<T> operator - (const Vector4<T> &a, const Vector4<T> &b)
{
	return Vector4<T>(a).Sub(b);
}

template<typename T>
inline const Vector4<T> operator - (const Vector4<T> &a, const T &b)
{
	return Vector4<T>(a).Sub(b);
}

template<typename T>
inline const Vector4<T> operator - (const T &a, const Vector4<T> &b)
{
	const T x = a - b[0];
	const T y = a - b[1];
	const T z = a - b[2];
	const T w = a - b[3];

	return Vector4<T>(x, y, z, w);
}

template<typename T>
inline Vector4<T>& operator -= (Vector4<T> &a, const Vector4<T> &b)
{
	return a = a - b;
}

template<typename T>
inline const Vector4<T> operator -= (Vector4<T> &a, const T &b)
{
	return a = a - b;
}

// ------------------
// -- * Mul * --
// ------------------

// Cross product. Use Mul() for an actual multiplication
template<typename T>
inline const Vector4<T> operator * (const Vector4<T> &a, const Vector4<T> &b)
{
	return Vector4<T>(a).Cross(b);
}

template<typename T>
inline const Vector4<T> operator * (const Vector4<T> &a, const T &b)
{
	return Vector4<T>(a).Mul(b);
}

template<typename T>
inline const Vector4<T> operator * (const T &a, const Vector4<T> &b)
{
	return b * a;
}

template<typename T>
inline const Vector4<T> operator *= (Vector4<T> &a, const T &b)
{
	return a = a * b;
}


// ----------------
// -- * Div * --
// ----------------

template<typename T>
inline const Vector4<T> operator / (const Vector4<T> &a, const T &b)
{
	return Vector4<T>(a).Div(b);
}

template<typename T>
inline const Vector4<T> operator / (const T &a, const Vector4<T> &b)
{
	const T x = a / b[0];
	const T y = a / b[1];
	const T z = a / b[2];
	const T w = a / b[3];

	return Vector4<T>(x, y, z, w);
}

template<typename T>
inline const Vector4<T> operator /= (Vector4<T> &a, const T &b)
{
	return a = a / b;
}

class Vector4f : public Vector4<gFloat>
{
public:

	inline Vector4f()
	{
		Set(0.f, 0.f, 0.f, 0.f);
	}

	template<typename R>
	inline Vector4f(const Vector4<R> &v)
	{
		Set(v);
	}

	inline Vector4f(const gFloat &x, const gFloat &y, const gFloat &z, const gFloat &w)
	{
		Set(x, y, z, w);
	}
};

class Vector4i : public Vector4<gInt>
{
public:

	inline Vector4i()
	{
		Set(0, 0, 0, 0);
	}

	template<typename R>
	inline Vector4i(const Vector4<R> &v)
	{
		Set(v);
	}

	inline Vector4i(const gInt &x, const gInt &y, const gInt &z, const gInt &w)
	{
		Set(x, y, z, w);
	}
};

GEndNameSpace()

#endif // __MATH__VECTOR4__H__
