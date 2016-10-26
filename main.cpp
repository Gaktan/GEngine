#include "precomp.h"

#include "debug/testcase.h"
#include "debug/log.h"

using namespace gfe;

int main()
{
#ifdef USE_TEST_CASE
	startVector4TestCase();
	startMathTestCase();
	startMatrixTestCase();
#endif

	return 0;
}
