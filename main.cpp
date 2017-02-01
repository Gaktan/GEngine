#include "precomp.h"

#include "debug/testcase.h"

#include "engine/mainloop.h"

using namespace gfe;

int main()
{
#ifdef USE_TEST_CASE
	startPrimitiveTestCase();
	startVector4TestCase();
	startMathTestCase();
	startMatrixTestCase();
#endif

	MainLoop::GetInstance().StartLoop();

	return 0;
}
