#include <string.h>  
#include "../../unity.h"
#include "asm.h" 

 int call_func(int (*f)()); 
 
 extern int code; 
 extern int currentSalary;  
 extern int wall1; 
 extern int wall2; 
 extern int wall3; 

void setUp(void) {
    // set stuff up here
     
      wall1=0x12345678;  
      wall2=0x12345678;  
      wall3=0x12345678;  
       
}

void tearDown(void) {
    // clean stuff up here
}



void run_test(int x, int y, int expected)
{

    int result; 
    code=x; 
    currentSalary=y; 
    result=call_func(new_salary); 

    
    TEST_ASSERT_EQUAL_INT(expected,result); 
    TEST_ASSERT_EQUAL_INT(x,code); 
    TEST_ASSERT_EQUAL_INT(y,currentSalary); 
    TEST_ASSERT_EQUAL_INT(0x12345678,wall1); 
    TEST_ASSERT_EQUAL_INT(0x12345678,wall2); 
    TEST_ASSERT_EQUAL_INT(0x12345678,wall3); 
    
}

void test_Zero()
{ 
    run_test(0, 0, 100); 
}

void test_OneA()
{ 
    run_test(10, 0, 300); 
}

void test_OneB()
{ 
    run_test(11, 0, 250); 
}

void test_OneC()
{ 
    run_test( 12, 0, 150); 
}

void test_MinusA()
{ 
    run_test( 5, 1000, 1100); 
}

void test_MinusB()
{ 
    run_test( 12, 1000, 1150); 
}

void test_Big()
{ 
   run_test(11, 1000, 1250); 

}

void test_Big2()
{ 
   run_test(10, 1000, 1300); 

}


int main()
  { 

    UNITY_BEGIN();
    RUN_TEST(test_Zero);
    RUN_TEST(test_OneA);
    RUN_TEST(test_OneB);
    RUN_TEST(test_OneC);
    RUN_TEST(test_MinusA);
    RUN_TEST(test_MinusB);
    RUN_TEST(test_Big);
    RUN_TEST(test_Big2);
    return UNITY_END();  

  } 






