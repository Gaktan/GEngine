#ifndef __DEBUG__TESTCASE__H__
#define __DEBUG__TESTCASE__H__

GBeginNameSpace()

#ifdef USE_TEST_CASE
void startMathTestCase();
void startVector3TestCase();
void startVector4TestCase();
#endif // USE_TEST_CASE

void startMatrixTestCase();

GEndNameSpace()

#endif // __DEBUG__TESTCASE__H__
