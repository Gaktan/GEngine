#ifndef __ASSERT__H__
#define __ASSERT__H__

GBeginNameSpace()

#ifdef _DEBUG_

#include <iostream>
#include <stdlib.h>

#include "debugbreak.h"

inline void _assert(const gString expression, const gString file, int line, gBool doBreak)
{
	std::cerr << "Assertion '" << expression << "' failed, file '" << file << "' line '" << line << "'." << std::endl;
	if (doBreak)
		debug_break();
}

inline void _assert(const gString expression, gBool doBreak)
{
	std::cerr << "Assertion '" << expression << "' failed." << std::endl;
	if (doBreak)
		debug_break();
}

inline void _assert_with_message(const gString expression, const gString text, gBool doBreak)
{
	std::cerr << "Assertion '" << expression << "' failed with error '" << text << "'." << std::endl;
	if (doBreak)
		debug_break();
}

#define assert(condition) ((condition) ? (void)0 : _assert(#condition, __FILE__, __LINE__, true))
#define assertWithMessage(condition, message) ((condition) ? (void)0 : _assert_with_message(#condition, message, true))

#define assertError(message) _assert(message, __FILE__, __LINE__, false)

#define createTestCase(name) TestCase name(#name);
#define testCase(name, condition) name.a(condition, #condition)

class TestCase
{
public:
	gBool failed;
	gString name;

	TestCase(const gString &Name)
	{
		name = Name;
		failed = false;
		std::cerr << "Starting test case '" << name << "'." << std::endl;
	}

	inline ~TestCase()
	{
		if (failed)
		{
			std::cerr << "Test case '" << name << "' failed." << std::endl;
		}
		else
		{
			std::cerr << "Test case '" << name << "' was a success." << std::endl;
		}
	}

	inline void a(gBool condition, gString conditionText)
	{
		if (!condition)
		{
			failed = true;
			_assert(conditionText, false);
		}
	}
};

#else // _DEBUG_

#define assert(condition) (void) 0
#define assertWithMessage(condition, message) (void) 0

#define assertError(message) (void) 0

#define createTestCase(name) (void) 0
#define test(name, condition) (void) 0


#endif // _DEBUG_

GEndNameSpace()

#endif // __ASSERT__H__
