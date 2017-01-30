#ifndef __MATH__Vec4__H__
#define __MATH__Vec4__H__

GBeginNameSpace()


template<typename T>
class Vec4
{
public:

	inline Vec4()
	{
		Set(0, 0, 0, 0);
	}

	inline Vec4(const Vec4<T> &v)
	{
		Set(v);
	}

	inline Vec4(const T x, const T y, const T z, const T w)
	{
		Set(x, y, z, w);
	}

	inline Vec4(const T a[4])
	{
		Set(a[0], a[1], a[2], a[3]);
	}

	inline virtual ~Vec4()
	{
	}

	// -- Methods

	template<typename R>
	inline void Set(const Vec4<R> &v)
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

	inline Vec4<T>& Normalize()
	{
		const T length = fastInvSqrt(LengthSquared());
		return Mul(length);
	}

	inline Vec4<T>& Add(const Vec4<T> &v)
	{
		x += v.x;
		y += v.y;
		z += v.z;
		w += v.w;
		return *this;
	}

	inline Vec4<T>& Add(const T v)
	{
		x += v;
		y += v;
		z += v;
		w += v;
		return *this;
	}

	inline Vec4<T>& Sub(const Vec4<T> &v)
	{
		x -= v.x;
		y -= v.y;
		z -= v.z;
		w -= v.w;
		return *this;
	}

	inline Vec4<T>& Sub(const T v)
	{
		x -= v;
		y -= v;
		z -= v;
		w -= v;
		return *this;
	}

	inline Vec4<T>& Mul(const Vec4<T> &v)
	{
		x *= v.x;
		y *= v.y;
		z *= v.z;
		w *= v.w;
		return *this;
	}

	inline Vec4<T>& Mul(const T v)
	{
		x *= v;
		y *= v;
		z *= v;
		w *= v;
		return *this;
	}

	inline Vec4<T>& Div(const T v)
	{
		// Not going to work for integers types
		const T d = 1 / v;
		return Mul(d);
	}

	inline T Dot(const Vec4<T> &v) const
	{
		return x * v.x + y * v.y + z * v.z + w * v.w;
	}

	inline Vec4<T>& Cross(const Vec4<T> &v)
	{
		T x1 = (y * v.z) - (z * v.y);
		T y1 = (z * v.x) - (x * v.z);
		T z1 = (x * v.y) - (y * v.x);

		x = x1;
		y = y1;
		z = z1;

		return *this;
	}

	inline bool InRange(const T v) const
	{
		const T d = v * v;
		return (LengthSquared() < d);
	}


	// -- Operators


	template<typename R>
	inline Vec4<T>& operator = (const Vec4<R> &v)
	{
		Set(v);
		return *this;
	}

	inline bool operator == (const Vec4<T> &v) const
	{
		return equals(x, v.x) && equals(y, v.y) && equals(z, v.z) && equals(w, v.w);
	}

	inline bool operator == (const T a[4]) const
	{
		return equals(x, a[0]) && equals(y, a[1]) && equals(z, a[2]) && equals(w, a[3]);
	}

	inline bool operator != (const Vec4<T> &v) const
	{
		return !(*this == v);
	}

	inline bool operator != (const T a[4]) const
	{
		return !(*this == a);
	}

	inline const T& operator [] (const ui32 index) const
	{
		assert(index >= 0 && index < 4);
		return buffer[index];
	}

	inline T& operator [] (const ui32 index)
	{
		assert(index >= 0 && index < 4);
		return buffer[index];
	}

	inline const T& operator () (const ui32 index) const
	{
		assert(index >= 0 && index < 4);
		return buffer[index];
	}

	inline T& operator () (const ui32 index)
	{
		assert(index >= 0 && index < 4);
		return buffer[index];
	}

	inline friend stringStream& operator << (stringStream& stream, const Vec4<T> &v)
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

	inline friend Vec4<T> operator + (const Vec4<T> &a, const Vec4<T> &b)
	{
		return Vec4<T>(a).Add(b);
	}

	inline friend const Vec4<T> operator + (const Vec4<T> &a, const T b)
	{
		return Vec4<T>(a).Add(b);
	}

	inline friend const Vec4<T> operator + (const T a, const Vec4<T> &b)
	{
		return b + a;
	}

	inline friend Vec4<T>& operator += (Vec4<T> &a, const Vec4<T> &b)
	{
		return a = a + b;
	}

	inline friend const Vec4<T> operator += (Vec4<T> &a, const T b)
	{
		return a = a + b;
	}

	// ---------------
	// -- - MINUS - --
	// ---------------

	inline friend const Vec4<T> operator - (const Vec4<T> &a, const Vec4<T> &b)
	{
		return Vec4<T>(a).Sub(b);
	}

	inline friend const Vec4<T> operator - (const Vec4<T> &a, const T b)
	{
		return Vec4<T>(a).Sub(b);
	}

	inline friend const Vec4<T> operator - (const T a, const Vec4<T> &b)
	{
		const T x = a - b[0];
		const T y = a - b[1];
		const T z = a - b[2];
		const T w = a - b[3];

		return Vec4<T>(x, y, z, w);
	}

	inline friend Vec4<T>& operator -= (Vec4<T> &a, const Vec4<T> &b)
	{
		return a = a - b;
	}

	inline friend const Vec4<T> operator -= (Vec4<T> &a, const T b)
	{
		return a = a - b;
	}

	// ------------------
	// -- * Mul * --
	// ------------------

	// Cross product. Use Mul() for an actual multiplication
	inline friend const Vec4<T> operator * (const Vec4<T> &a, const Vec4<T> &b)
	{
		return Vec4<T>(a).Cross(b);
	}

	inline friend const Vec4<T> operator * (const Vec4<T> &a, const T b)
	{
		return Vec4<T>(a).Mul(b);
	}

	inline friend const Vec4<T> operator * (const T a, const Vec4<T> &b)
	{
		return b * a;
	}

	inline friend const Vec4<T> operator *= (Vec4<T> &a, const T b)
	{
		return a = a * b;
	}

	// ----------------
	// -- * Div * --
	// ----------------

	inline friend const Vec4<T> operator / (const Vec4<T> &a, const T b)
	{
		return Vec4<T>(a).Div(b);
	}

	inline friend const Vec4<T> operator / (const T a, const Vec4<T> &b)
	{
		const T x = a / b[0];
		const T y = a / b[1];
		const T z = a / b[2];
		const T w = a / b[3];

		return Vec4<T>(x, y, z, w);
	}

	inline friend const Vec4<T> operator /= (Vec4<T> &a, const T b)
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

class Vec4f : public Vec4<float>
{
public:

	Vec4f(const Vec4f &v)
	{
		Set(v);
	}

	Vec4f(const float x = 0.f, const float y = 0.f, const float z = 0.f, const float w = 0.f)
	{
		Set(x, y, z, w);
	}

	template<typename R>
	inline Vec4f& operator = (const Vec4<R> &v)
	{
		Set(v);
		return *this;
	}
};

class Vec4i : public Vec4<i32>
{
public:

	Vec4i()
	{
		Set(0, 0, 0, 0);
	}

	Vec4i(const Vec4i &v)
	{
		Set(v);
	}

	Vec4i(const i32 x, const i32 y, const i32 z, const i32 w)
	{
		Set(x, y, z, w);
	}

	Vec4i& Div(const i32 v)
	{
		x /= v;
		y /= v;
		z /= v;
		w /= v;
		return *this;
	}

	template<typename R>
	inline Vec4i& operator = (const Vec4<R> &v)
	{
		Set(v);
		return *this;
	}
};

GEndNameSpace()

#endif // __MATH__Vec4__H__
