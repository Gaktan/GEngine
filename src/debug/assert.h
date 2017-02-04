#ifndef __ASSERT__H__
#define __ASSERT__H__

GBeginNameSpace()

#ifdef _DEBUG_

#include <stdlib.h>

#include "debug/log.h"
#include "debug/debugbreak.h"

inline void _assert(const String expression, const String file, ui16 line, bool doBreak)
{
	cout << "Assertion '" << expression << "' failed, file '" << file << "' line '" /*<< line*/ << "'." << endl;

	if (doBreak)
		debug_break();
}

inline void _assert(const String expression, bool doBreak)
{
	cout << "Assertion '" << expression << "' failed." << endl;

	if (doBreak)
		debug_break();
}

inline void _assert_with_message(const String expression, const String text, bool doBreak)
{
	cout << "Assertion '" << expression << "' failed with error '" << text << "'." << endl;

	if (doBreak)
		debug_break();
}

#define assert(condition) ((condition) ? (void)0 : _assert(#condition, __FILE__, __LINE__, true))
#define assertWithMessage(condition, message) ((condition) ? (void)0 : _assert_with_message(#condition, message, true))

#define assertError(message) _assert(message, __FILE__, __LINE__, false)

#else // _DEBUG_

#define assert(condition) (void) 0
#define assertWithMessage(condition, message) (void) 0

#define assertError(message) (void) 0


#endif // _DEBUG_

GEndNameSpace()

#endif // __ASSERT__H__
