#include "debug/testcase.h"

//#ifdef USE_TEST_CASE

#include "math/vector3.h"
#include "math/vector4.h"
#include "math/matrix4f.h"
#include "math/mathutil.h"

#include "debug/assert.h"

GBeginNameSpace()

#define v3test(condition) testCase(vector3Test, condition)
#define v4test(condition) testCase(vector4Test, condition)
#define mathtest(condition) testCase(mathTest, condition)
#define matrixtest(condition) testCase(matrixTest, condition)

using namespace std;

void startVector3TestCase()
{
	createTestCase(vector3Test);

	Vector3f v;

	// Testing constructor and == operator
	v3test(v == Vector3f(0.f, 0.f, 0.f));
	v3test(v == Vector3f({0, 0, 0}));
	float array[] = {0, 0, 0};
	v3test(v == array);

	v(0) = 1.0f;
	v[1] += 2.0f;
	v(2) = 3.0f;

	// Testing attributes modification
	v3test(v == Vector3f(1.0f, 2.0f, 3.0f));

	v += 2.25f;
	v -= 1.25f;
	v *= 2.0f;
	v /= 1.0f;


	// Testing overloaded operators
	v3test(v == Vector3f(4.0f, 6.0f, 8.0f));

	v.Set(0.f, 24.7386f, 48.f);

	// Testing Length and LengthSquared
	// Using Equals method to better compare floats
	v3test(equals(v.LengthSquared(), 54.0f * 54.0f));
	v3test(equals(v.Length(), 54.0f));

	Vector3f v2 = v;

	// Testing assignment
	v3test(v == v2);

	v = Vector3f(2, 4, 4);
	v2 = v.Normalize();

	// Testing normalization and int casting
	v3test(v2 == Vector3f(0.333f, 0.666f, 0.666f));

	v = (1.f / v2);

	// Testing division
	v3test(v == Vector3f(3, 1.5, 1.5));

	// Testing dot product
	v3test(equals(v.Dot(v2), 3.0f));

	v = v2 * v;

	// Testing cross product and different template
	v3test(v == Vector3<gFloat>(0, 1.5, -1.5f));

	Vector3i i(1, 2, 3);

	v = i;

	//v[8] = 0; v[-1] = 0; // Make sure this crashes

	// Testing Vector casting with different type
	v3test(v == Vector3f(1, 2, 3));
}

void startVector4TestCase()
{
	createTestCase(vector4Test);

	Vector4f v;

	// Testing constructor and == operator
	v4test(v == Vector4f(0.f, 0.f, 0.f, 0.f));
	v4test(v == Vector4f({0, 0, 0, 0}));
	float array[] = {0, 0, 0, 0};
	v4test(v == array);

	v(0) = 1.0f;
	v[1] += 2.0f;
	v(2) = 3.0f;

	// Testing attributes modification
	v4test(v == Vector4f(1.0f, 2.0f, 3.0f, 0.f));

	v += 2.25f;
	v -= 1.25f;
	v *= 2.0f;
	v /= 1.0f;

	// Testing overloaded operators
	v4test(v == Vector4f(4.0f, 6.0f, 8.0f, 2.f));

	v.Set(0.f, 24.7386f, 48.f, 0.f);

	// Testing Length and LengthSquared
	// Using Equals method to better compare floats
	v4test(equals(v.LengthSquared(), 54.0f * 54.0f));
	v4test(equals(v.Length(), 54.0f));

	Vector4f v2 = v;

	// Testing assignment
	v4test(v == v2);

	v = Vector4f(2, 4, 4, 0.f);
	v2 = v.Normalize();

	// Testing normalization and int casting
	v4test(v2 == Vector4f(0.333f, 0.666f, 0.666f, 0.f));

	v = (1.f / v2); // This should device w by 0

	v4test(isInfinite(v(3)));

	v(3) = 0.f;

	// Testing division
	v4test(v == Vector4f(3, 1.5, 1.5, 0.f));

	// Testing dot product
	v4test(equals(v.Dot(v2), 3.0f));

	v = v2 * v;

	// Testing cross product and different template
	v4test(v == Vector4<gFloat>(0, 1.5, -1.5f, 0.f));

	Vector4i i(1, 2, 3, 0);

	v = i;

	//v[8] = 0; v[-1] = 0; // Make sure this crashes

	// Testing Vector casting with different type
	v4test(v == Vector4f(1, 2, 3, 0.f));
}

void startMathTestCase()
{
	createTestCase(mathTest);

	// Equals
	mathtest(equals(42.f, 42.f));
	mathtest(equals(42.49999f, 42.5f, 0.001f));
	mathtest(equals(42.5f, 42.49999f, 0.001f));
	mathtest(equals(42.f, 42.99999f, 1.f));

	// Floor
	mathtest(floor(42.f) == 42.f);
	mathtest(floor(42.49999f) == 42.f);
	mathtest(floor(42.5f) == 42.f);
	mathtest(floor(42.99999f) == 42.f);

	// Round
	mathtest(round(42.f) == 42.f);
	mathtest(round(42.49999f) == 42.f);
	mathtest(round(42.5f) == 43.f);
	mathtest(round(42.99999f) == 43.f);

	// Mod
	mathtest(mod(42.f, 43.f) == 42.f);
	mathtest(mod(42.49999f, 43.f) == 42.49999f);
	mathtest(mod(42.5f, 2.f) == 0.5f);
	mathtest(mod(-2.5f, 4.f) == 1.5f);

	// Abs
	mathtest(abs(42.f) == 42.f);
	mathtest(abs(0.f) == 0.f);
	mathtest(abs(-0.00000001f) == 0.00000001f);
	mathtest(abs(-50.f) == 50.f);

	// Sin
	mathtest(equals(sin(0.f), 0.f, 0.01f));
	mathtest(equals(sin(PI), 0.f, 0.01f));
	mathtest(equals(sin(HALF_PI), 1.f, 0.01f));
	mathtest(equals(sin(12.f), -0.536572918f, 0.01f));

	// Cos
	mathtest(equals(cos(0.f), 1.f, 0.01f));
	mathtest(equals(cos(PI), -1.f, 0.01f));
	mathtest(equals(cos(HALF_PI), 0.f, 0.01f));
	mathtest(equals(cos(12.f), 0.843f, 0.01f));

	// Atan2
	mathtest(equals(atan2(1.f, 0.f), HALF_PI));
	mathtest(equals(atan2(0.f, 1.f), 0.f));
	mathtest(equals(atan2(0.f, 0.f), HALF_PI));

	// Max
	mathtest(max(0, 1) == 1);
	mathtest(max(0, -1) == 0);
	mathtest(max(1.999999f, 2.f) == 2.f);
	mathtest(max(0.0000001f, 0.f) == 0.0000001f);

	// Min
	mathtest(min(0, 1) == 0);
	mathtest(min(0, -1) == -1);
	mathtest(min(2.f, 2.0000001f) == 2.f);
	mathtest(min(0.0000001f, 0.f) == 0.f);

	// Clamp
	mathtest(clamp(0.5, 0, 1) == 0.5);
	mathtest(clamp(-0.5, 0, 1) == 0);
	mathtest(clamp(2, 0, 1) == 1.f);
	mathtest(clamp(-4, -5, -3) == -4.f);

	// Signum
	mathtest(signum(0) == 1);
	mathtest(signum(-0) == 1);
	mathtest(signum(1) == 1);
	mathtest(signum(-1) == -1);

	// Is infinite
	mathtest(!isInfinite(0));
	mathtest(!isInfinite(1));
	mathtest(isInfinite(1 / 0.f));

	// Sqrt
	mathtest(sqrt(0) == 0);
	mathtest(isInfinite(sqrt(-1)));
	mathtest(sqrt(9) == 3);
	mathtest(equals(sqrt(2), 1.41421356, 0.01f));

	// Fast inverse sqrt
	mathtest(equals(fastInvSqrt(9), 1.f / sqrt(9)));
	mathtest(equals(fastInvSqrt(1), 1.f / sqrt(1)));
	mathtest(equals(fastInvSqrt(2), 1.f / sqrt(2)));
	mathtest(equals(fastInvSqrt(3), 1.f / sqrt(3)));

	// Pow
	mathtest(pow(1, 2) == 1);
	mathtest(pow(2, 2) == 4);
	mathtest(pow(2, 0.5) == sqrt(2));
	mathtest(pow(2, 8) == 256);

	// In range
	mathtest(inRange(0, -1, 1));
	mathtest(inRange(0, 0, 1));
	mathtest(!inRange(1, 0, 1));
	mathtest(!inRange(1, 0, 0.5));

	// Lerp
	mathtest(lerp(0, 100, 0.5) == 50);
	mathtest(lerp(0, 1, 0.25) == 0.25);
	mathtest(lerp(-1, 1, 0.5) == 0);
	mathtest(lerp(0, 100, 1) == 100);
	mathtest(lerp(0, 100, 3) == 300);
	mathtest(lerp(0, 100, -1) == -100);

	// Smooth step
	mathtest(smoothStep(0, 100, 50) == 0.5);
	mathtest(smoothStep(0, 1, 0.25) == 0.15625f);
	mathtest(smoothStep(-1, 1, 0.0) == 0.5);
	mathtest(equals(smoothStep(0, 100, 10), 0.028f));
	mathtest(smoothStep(0, 1, 3) == 1);
	mathtest(smoothStep(0, 1, -1) == 0);

	// Slerp is smooht step + lerp. No need to test
}

void startMatrixTestCase()
{
	createTestCase(matrixTest);

	MAT_ARRAY_2D array2D =
	{
		{
			{1, 0, 0, 0},
			{0, 1, 0, 0},
			{1 / 5.f, 0, 1, 0},
			{0, 0, 0, 1},
		}
	};

	MAT_ARRAY array1D =
	{
		1, 0, 1 / 5.f, 0,
		0, 1, 0, 0,
		0, 0, 1, 0,
		0, 0, 0, 1
	};

	Matrix4f m;
	m.m02 = 0.2001f;

	// Testing equals and identity matrix
	matrixtest(m.Equals(array2D));
	matrixtest(!m.Equals(array1D));

	m = m.Mul(array2D);

	cout << m << endl;
}

GEndNameSpace()

//#endif // USE_TEST_CASE
