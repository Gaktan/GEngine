#ifndef __DEBUG__LOG__H__
#define __DEBUG__LOG__H__

#include <sstream>
typedef std::ostringstream		__GSTRINGSTREAM;

// for std::stew(int)
#include <iomanip>

gString stringFormat(const gString str, /* args */ ...);
void logOutput(const gString str, /* args */ ...);

GBeginNameSpace()

struct ENDL_STRUCT
{
};

class gStringStream
{
public:

	gStringStream();
	virtual ~gStringStream();

	gStringStream& flush();
	gString str();

	__GSTRINGSTREAM& getStream();

	gStringStream& operator << (const ENDL_STRUCT &m);

	//gStringStream& operator << (const gDouble t);
	//gStringStream& operator << (const gUInt t);
	//gStringStream& operator << (const gInt t);
	//gStringStream& operator << (const gChar t);
	//gStringStream& operator << (const gLong t);
	gStringStream& operator << (const gString t);
	//gStringStream& operator << (const gIndex t);
	//gStringStream& operator << (const gBool t);
	gStringStream& operator << (const gFloat t);
	gStringStream& operator << (const gChar *t);
	gStringStream& operator << (const gVector<gByte> &t);
	gStringStream& operator << (std::_Setw t);

private:
	__GSTRINGSTREAM stream;

};


static gStringStream cout;
static ENDL_STRUCT endl;

GEndNameSpace()

#endif // __DEBUG__LOG__H__
