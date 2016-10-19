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
	
	OutputDebugString(buffer);
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

//gStringStream& gStringStream::operator << (const gDouble t)
//{
//	stream << t;
//	return *this;
//}
//
//gStringStream& gStringStream::operator << (const gUInt t)
//{
//	stream << t;
//	return *this;
//}
//
//gStringStream& gStringStream::operator << (const gInt t)
//{
//	stream << t;
//	return *this;
//}
//
//gStringStream& gStringStream::operator << (const gChar t)
//{
//	stream << t;
//	return *this;
//}
//
//gStringStream& gStringStream::operator << (const gLong t)
//{
//	stream << t;
//	return *this;
//}

gStringStream& gStringStream::operator << (const gString t)
{
	stream << t;
	return *this;
}

//gStringStream& gStringStream::operator << (const gIndex t)
//{
//	stream << t;
//	return *this;
//}
//
//gStringStream& gStringStream::operator << (const gBool t)
//{
//	stream << t;
//	return *this;
//}
//
gStringStream& gStringStream::operator << (const gFloat t)
{
	stream << t;
	return *this;
}

gStringStream& gStringStream::operator << (const std::_Smanip<std::streamsize> t)
{
	stream << t;
	return *this;
}

gStringStream& gStringStream::operator << (const gChar *t)
{
	stream << t;
	return *this;
}

GEndNameSpace()