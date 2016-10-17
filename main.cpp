#include "debug/testcase.h"

int main()
{
#ifdef USE_TEST_CASE
	gfe::startVector3TestCase();
	gfe::startVector4TestCase();
	gfe::startMathTestCase();
	gfe::startMatrixTestCase();
#endif
	return 0;
}
