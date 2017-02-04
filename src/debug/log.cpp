#include "precomp.h"

#include "debug/log.h"

#include <stdio.h>
#include <windows.h>

#define vsnprintf _vsnprintf

String stringFormat(const String str, /* args */ ...)
{
	char buffer[256];
	String ret;

	va_list args;
	va_start(args, str);
	vsnprintf(buffer, 255, str.c_str(), args);
	va_end(args);

	ret = buffer;

	return ret;
}

void logOutput(const String str, /* args */ ...)
{
	char buffer[256];

	va_list args;
	va_start(args, str);
	vsnprintf(buffer, 253, str.c_str(), args);
	va_end(args);

#ifndef _GCC_
	// If using visual, use OutputDebugString to print to the output window
	OutputDebugString(buffer);
#else // _GCC_
	// Else print as usual
	printf(buffer);
#endif // _GCC_
}

GBeginNameSpace()

stringStream::stringStream()
{
}

stringStream::~stringStream()
{
}

stringStream& stringStream::flush()
{
	logOutput(str());
	stream.flush();
	stream.str("");
	stream.clear();
	return *this;
}

String stringStream::str()
{
	return stream.str();
}

__GSTRINGSTREAM& stringStream::getStream()
{
	return stream;
}

stringStream& stringStream::operator << (const ENDL_STRUCT &m)
{
	stream << '\n';
	flush();
	return *this;
}

stringStream& stringStream::operator << (const String t)
{
	stream << t;
	return *this;
}

stringStream& stringStream::operator << (const float t)
{
	stream << t;
	return *this;
}

stringStream& stringStream::operator << (std::_Setw t)
{
	stream << t;
	return *this;
}

stringStream& stringStream::operator << (const char *t)
{
	stream << t;
	return *this;
}

stringStream& stringStream::operator << (const Vector<byte> &t)
{
	Vector<byte>::const_iterator begin = t.begin();
	Vector<byte>::const_iterator end = t.end();

	stream << "vector [";
	for (; begin != end; begin++)
	{
		stream << (*begin);
		if (begin != end - 1)
		{
			stream << ", ";
		}
	}
	stream << "]";

	return *this;
}

GEndNameSpace()
