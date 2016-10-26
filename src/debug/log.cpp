#include "precomp.h"

#include "debug/log.h"

#include <stdio.h>
#include <windows.h>

gString stringFormat(const gString str, /* args */ ...)
{
	gChar buffer[256];
	gString ret;

	va_list args;
	va_start(args, str);
	vsnprintf(buffer, 255, str.c_str(), args);
	va_end(args);

	ret = buffer;

	return ret;
}

void logOutput(const gString str, /* args */ ...)
{
	gChar buffer[256];

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

gStringStream::gStringStream()
{
}

gStringStream::~gStringStream()
{
}

gStringStream& gStringStream::flush()
{
	logOutput(str());
	stream.flush();
	stream.str("");
	stream.clear();
	return *this;
}

gString gStringStream::str()
{
	return stream.str();
}

gStringStream& gStringStream::operator << (const ENDL_STRUCT &m)
{
	stream << '\n';
	flush();
	return *this;
}

gStringStream& gStringStream::operator << (const gString t)
{
	stream << t;
	return *this;
}

gStringStream& gStringStream::operator << (const gFloat t)
{
	stream << t;
	return *this;
}

gStringStream& gStringStream::operator << (std::_Setw t)
{
	stream << t;
	return *this;
}

gStringStream& gStringStream::operator << (const gChar *t)
{
	stream << t;
	return *this;
}

gStringStream& gStringStream::operator << (const gVector<gByte> &t)
{
	gVector<gByte>::const_iterator begin = t.begin();
	gVector<gByte>::const_iterator end = t.end();

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
