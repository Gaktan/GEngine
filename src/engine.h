#ifndef __ENGINE__H__
#define __ENGINE__H__

#ifdef _WIN32_
#include <stdint.h>
typedef int8_t					i8;
typedef int16_t					i16;
typedef int32_t					i32;
typedef int64_t					i64;

typedef uint8_t					ui8;
typedef uint16_t				ui16;
typedef uint32_t				ui32;
typedef uint64_t				ui64;

typedef intptr_t				iptr;

typedef ui8						byte;

#include <string>
typedef std::string				String;

#include <array>
template <class C, std::size_t S> // better than int
using Array = std::array<C, S>;

#include <vector>
#define Vector					 std::vector

#else
#error Not yet implemented
#endif

// Namespace used for the engine
#define GBeginNameSpace() namespace gfe {
#define GEndNameSpace() }

#include "debug/log.h"
#include "debug/assert.h"

#ifdef _DEBUG_
#define USE_TEST_CASE
#endif // _DEBUG_

#endif // __ENGINE__H__
