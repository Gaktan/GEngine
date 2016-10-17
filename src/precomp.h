#ifndef __PRECOMP__H__
#define __PRECOMP__H__

typedef double					gDouble;

typedef long unsigned int		gUInt;
typedef int						gInt;
typedef char					gChar;
typedef long					gLong;

#include <string>
typedef std::string				gString;

#include <iostream>
typedef std::ostream			ostream;

typedef size_t					gIndex;

typedef bool					gBool;

typedef float					gFloat;

#include <array>
//typedef std::array			gArray;
#define gArray					std::array

#include "engine.h"

#endif // __PRECOMP__H__
