#ifndef __ENGINE__H__
#define __ENGINE__H__

typedef double					gDouble;

typedef long unsigned int		gUInt;
typedef int						gInt;
typedef char					gChar;
typedef long					gLong;

#include <string>
typedef std::string				gString;

typedef size_t					gIndex;

typedef bool					gBool;

typedef float					gFloat;

#include <array>
//typedef std::array			gArray;
#define gArray					std::array

// Namespace used for the engine
#define GBeginNameSpace() namespace gfe {
#define GEndNameSpace() }

#include "debug/log.h"
#include "debug/assert.h"

#ifdef _DEBUG_
#define USE_TEST_CASE
#endif // _DEBUG_

#endif // __ENGINE__H__
