#ifndef __DEBUG__TESTCASE__H__
#define __DEBUG__TESTCASE__H__

GBeginNameSpace()

#ifdef USE_TEST_CASE

#define createTestCase(name) TestCase name(#name);
#define testCase(name, condition) name.a(condition, #condition)

class TestCase
{
public:
	bool failed;
	String name;

	TestCase(const String &Name)
	{
		name = Name;
		failed = false;
		cout << "Starting test case '" << name << "'." << endl;
	}

	inline ~TestCase()
	{
		if (failed)
		{
			cout << "Test case '" << name << "' failed." << endl;
		}
		else
		{
			cout << "Test case '" << name << "' was a success." << endl;
		}
	}

	inline void a(bool condition, String conditionText)
	{
		if (!condition)
		{
			failed = true;
			_assert(conditionText, false);
		}
	}
};

void startPrimitiveTestCase();
void startMathTestCase();
void startVector4TestCase();
void startMatrixTestCase();

#endif // USE_TEST_CASE


GEndNameSpace()

#endif // __DEBUG__TESTCASE__H__
