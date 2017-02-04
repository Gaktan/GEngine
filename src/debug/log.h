#ifndef __DEBUG__LOG__H__
#define __DEBUG__LOG__H__

#include <sstream>
typedef std::ostringstream		__GSTRINGSTREAM;

// for std::stew(int)
#include <iomanip>

String stringFormat(const String str, /* args */ ...);
void logOutput(const String str, /* args */ ...);

GBeginNameSpace()

struct ENDL_STRUCT
{
};

class stringStream
{
public:

	stringStream();
	virtual ~stringStream();

	stringStream& flush();
	String str();

	__GSTRINGSTREAM& getStream();

	stringStream& operator << (const ENDL_STRUCT &m);

	//stringStream& operator << (const double t);
	//stringStream& operator << (const gUInt t);
	//stringStream& operator << (const gInt t);
	//stringStream& operator << (const gChar t);
	//stringStream& operator << (const gLong t);
	stringStream& operator << (const String t);
	//stringStream& operator << (const gIndex t);
	//stringStream& operator << (const gBool t);
	stringStream& operator << (const float t);
	stringStream& operator << (const char *t);
	stringStream& operator << (const Vector<byte> &t);
	stringStream& operator << (std::_Setw t);

private:
	__GSTRINGSTREAM stream;

};


static stringStream cout;
static ENDL_STRUCT endl;

GEndNameSpace()

#endif // __DEBUG__LOG__H__
