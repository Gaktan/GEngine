#ifndef __MATH__VECTOR4__H__
#define __MATH__VECTOR4__H__

GBeginNameSpace()


template<typename T>
class Vector4
{
public:

	inline Vector4()
	{
		Set(0, 0, 0, 0);
	}

	inline Vector4(const Vector4<T> &v)
	{
		Set(v);
	}

	inline Vector4(const T x, const T y, const T z, const T w)
	{
		Set(x, y, z, w);
	}

	inline Vector4(const T a[4])
	{
		Set(a[0], a[1], a[2], a[3]);
	}

	inline virtual ~Vector4()
	{
	}

	// -- Methods

	template<typename R>
	inline void Set(const Vector4<R> &v)
	{
		this->x = v.x;
		this->y = v.y;
		this->z = v.z;
		this->w = v.w;
	}

	inline void Set(const T x, const T y, const T z, const T w)
	{
		this->x = x;
		this->y = y;
		this->z = z;
		this->w = w;
	}

	inline T Length() const
	{
		return sqrt(LengthSquared());
	}

	inline T LengthSquared() const
	{
		return x*x + y*y + z*z + w*w;
	}

	inline Vector4<T>& Normalize()
	{
		const T length = fastInvSqrt(LengthSquared());
		return Mul(length);
	}

	inline Vector4<T>& Add(const Vector4<T> &v)
	{
		x += v.x;
		y += v.y;
		z += v.z;
		w += v.w;
		return *this;
	}

	inline Vector4<T>& Add(const T v)
	{
		x += v;
		y += v;
		z += v;
		w += v;
		return *this;
	}

	inline Vector4<T>& Sub(const Vector4<T> &v)
	{
		x -= v.x;
		y -= v.y;
		z -= v.z;
		w -= v.w;
		return *this;
	}

	inline Vector4<T>& Sub(const T v)
	{
		x -= v;
		y -= v;
		z -= v;
		w -= v;
		return *this;
	}

	inline Vector4<T>& Mul(const Vector4<T> &v)
	{
		x *= v.x;
		y *= v.y;
		z *= v.z;
		w *= v.w;
		return *this;
	}

	inline Vector4<T>& Mul(const T v)
	{
		x *= v;
		y *= v;
		z *= v;
		w *= v;
		return *this;
	}

	inline Vector4<T>& Div(const T v)
	{
		// Not going to work for integers types
		const T d = 1 / v;
		return Mul(d);
	}

	inline T Dot(const Vector4<T> &v) const
	{
		return x * v.x + y * v.y + z * v.z + w * v.w;
	}

	inline Vector4<T>& Cross(const Vector4<T> &v)
	{
		T x1 = (y * v.z) - (z * v.y);
		T y1 = (z * v.x) - (x * v.z);
		T z1 = (x * v.y) - (y * v.x);

		x = x1;
		y = y1;
		z = z1;

		return *this;
	}

	inline gBool InRange(const T v) const
	{
		const T d = v * v;
		return (LengthSquared() < d);
	}


	// -- Operators


	template<typename R>
	inline Vector4<T>& operator = (const Vector4<R> &v)
	{
		Set(v);
		return *this;
	}

	inline gBool operator == (const Vector4<T> &v) const
	{
		return equals(x, v.x) && equals(y, v.y) && equals(z, v.z) && equals(w, v.w);
	}

	inline gBool operator == (const T a[4]) const
	{
		return equals(x, a[0]) && equals(y, a[1]) && equals(z, a[2]) && equals(w, a[3]);
	}

	inline gBool operator != (const Vector4<T> &v) const
	{
		return !(*this == v);
	}

	inline gBool operator != (const T a[4]) const
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

	inline const T& operator () (const gIndex index) const
	{
		assert(index >= 0 && index < 4);
		return buffer[index];
	}

	inline T& operator () (const gIndex index)
	{
		assert(index >= 0 && index < 4);
		return buffer[index];
	}

	inline friend gStringStream& operator << (gStringStream& stream, const Vector4<T> &v)
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

	// --------------
	// -- + PLUS + --
	// --------------

	inline friend Vector4<T> operator + (const Vector4<T> &a, const Vector4<T> &b)
	{
		return Vector4<T>(a).Add(b);
	}

	inline friend const Vector4<T> operator + (const Vector4<T> &a, const T b)
	{
		return Vector4<T>(a).Add(b);
	}

	inline friend const Vector4<T> operator + (const T a, const Vector4<T> &b)
	{
		return b + a;
	}

	inline friend Vector4<T>& operator += (Vector4<T> &a, const Vector4<T> &b)
	{
		return a = a + b;
	}

	inline friend const Vector4<T> operator += (Vector4<T> &a, const T b)
	{
		return a = a + b;
	}

	// ---------------
	// -- - MINUS - --
	// ---------------

	inline friend const Vector4<T> operator - (const Vector4<T> &a, const Vector4<T> &b)
	{
		return Vector4<T>(a).Sub(b);
	}

	inline friend const Vector4<T> operator - (const Vector4<T> &a, const T b)
	{
		return Vector4<T>(a).Sub(b);
	}

	inline friend const Vector4<T> operator - (const T a, const Vector4<T> &b)
	{
		const T x = a - b[0];
		const T y = a - b[1];
		const T z = a - b[2];
		const T w = a - b[3];

		return Vector4<T>(x, y, z, w);
	}

	inline friend Vector4<T>& operator -= (Vector4<T> &a, const Vector4<T> &b)
	{
		return a = a - b;
	}

	inline friend const Vector4<T> operator -= (Vector4<T> &a, const T b)
	{
		return a = a - b;
	}

	// ------------------
	// -- * Mul * --
	// ------------------

	// Cross product. Use Mul() for an actual multiplication
	inline friend const Vector4<T> operator * (const Vector4<T> &a, const Vector4<T> &b)
	{
		return Vector4<T>(a).Cross(b);
	}

	inline friend const Vector4<T> operator * (const Vector4<T> &a, const T b)
	{
		return Vector4<T>(a).Mul(b);
	}

	inline friend const Vector4<T> operator * (const T a, const Vector4<T> &b)
	{
		return b * a;
	}

	inline friend const Vector4<T> operator *= (Vector4<T> &a, const T b)
	{
		return a = a * b;
	}

	// ----------------
	// -- * Div * --
	// ----------------

	inline friend const Vector4<T> operator / (const Vector4<T> &a, const T b)
	{
		return Vector4<T>(a).Div(b);
	}

	inline friend const Vector4<T> operator / (const T a, const Vector4<T> &b)
	{
		const T x = a / b[0];
		const T y = a / b[1];
		const T z = a / b[2];
		const T w = a / b[3];

		return Vector4<T>(x, y, z, w);
	}

	inline friend const Vector4<T> operator /= (Vector4<T> &a, const T b)
	{
		return a = a / b;
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

class Vector4f : public Vector4<gFloat>
{
public:

	Vector4f()
	{
		Set(0.f, 0.f, 0.f, 0.f);
	}

	Vector4f(const Vector4f &v)
	{
		Set(v);
	}

	Vector4f(const gFloat x, const gFloat y, const gFloat z, const gFloat w)
	{
		Set(x, y, z, w);
	}

	template<typename R>
	inline Vector4f& operator = (const Vector4<R> &v)
	{
		Set(v);
		return *this;
	}
};

class Vector4i : public Vector4<gInt>
{
public:

	Vector4i()
	{
		Set(0, 0, 0, 0);
	}

	Vector4i(const Vector4i &v)
	{
		Set(v);
	}

	Vector4i(const gInt x, const gInt y, const gInt z, const gInt w)
	{
		Set(x, y, z, w);
	}

	Vector4i& Div(const gInt v)
	{
		x /= v;
		y /= v;
		z /= v;
		w /= v;
		return *this;
	}

	template<typename R>
	inline Vector4i& operator = (const Vector4<R> &v)
	{
		Set(v);
		return *this;
	}
};

GEndNameSpace()

#endif // __MATH__VECTOR4__H__
