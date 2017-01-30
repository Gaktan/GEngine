#ifndef __DEBUG__LOG__H__
#define __DEBUG__LOG__H__

#include <sstream>
typedef std::ostringstream		__GSTRINGSTREAM;

// for std::stew(int)
#include <iomanip>

string stringFormat(const string str, /* args */ ...);
void logOutput(const string str, /* args */ ...);

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
	string str();

	__GSTRINGSTREAM& getStream();

	stringStream& operator << (const ENDL_STRUCT &m);

	//stringStream& operator << (const double t);
	//stringStream& operator << (const gUInt t);
	//stringStream& operator << (const gInt t);
	//stringStream& operator << (const gChar t);
	//stringStream& operator << (const gLong t);
	stringStream& operator << (const string t);
	//stringStream& operator << (const gIndex t);
	//stringStream& operator << (const gBool t);
	stringStream& operator << (const float t);
	stringStream& operator << (const char *t);
	stringStream& operator << (const vector<byte> &t);
	stringStream& operator << (std::_Setw t);

private:
	__GSTRINGSTREAM stream;

};


static stringStream cout;
static ENDL_STRUCT endl;

GEndNameSpace()

#endif // __DEBUG__LOG__H__
