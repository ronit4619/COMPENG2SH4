#include <assert.h>
#include <setjmp.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "CuTest.h"
#include "Questions.h"
    


   
    
//=========test 1==================================
	void TestQ1_1(CuTest *tc) {
		
		int input1=2,input2=4,expected=6,actual;
		actual=addFunction(input1,input2);
		CuAssertIntEquals(tc, expected, actual);
	}

//=========test 2==================================
    
	void TestQ1_2(CuTest *tc) {
		
		int input1=0,input2=4,expected=4,actual;
		actual=addFunction(input1,input2);
		CuAssertIntEquals(tc, expected, actual);
	}
    
//=========test 3==================================

	void TestQ1_3(CuTest *tc) {

		int input1=-3,input2=-2,expected=-5,actual;
		actual=addFunction(input1,input2);
		CuAssertIntEquals(tc, expected, actual);
	}
//=========test 4==================================

	void TestQ1_4(CuTest *tc) {

		int input1=0,input2=(-3),expected=-3,actual;
		actual=addFunction(input1,input2);
		CuAssertIntEquals(tc, expected, actual);
	}
//=========test 5==================================

	void TestQ1_5(CuTest *tc) {

		int input1=2,input2=(-1),expected=1,actual;
		actual=addFunction(input1,input2);
		CuAssertIntEquals(tc, expected, actual);
	}

  
//===========================================================
	CuSuite* Lab0GetSuite() {
		CuSuite* suite = CuSuiteNew();
		SUITE_ADD_TEST(suite, TestQ1_1);
		SUITE_ADD_TEST(suite, TestQ1_2);
		SUITE_ADD_TEST(suite, TestQ1_3);
		SUITE_ADD_TEST(suite, TestQ1_4);
		SUITE_ADD_TEST(suite, TestQ1_5);


		return suite;
	}
    
