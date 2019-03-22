#include <CUnit/Basic.h>
#include <stdio.h>
#include <string.h>

#include "revert_string.h"

void testRevertString(void) {
  char simple_string[] = "Hello";
  char str_with_spaces[] = "String with spaces";
  char str_with_odd_chars_num[] = "abc";
  char str_with_even_chars_num[] = "abcd";

  RevertString(simple_string);
  CU_ASSERT_STRING_EQUAL_FATAL(simple_string, "olleH");

  RevertString(str_with_spaces);
  CU_ASSERT_STRING_EQUAL_FATAL(str_with_spaces, "secaps htiw gnirtS");

  RevertString(str_with_odd_chars_num);
  CU_ASSERT_STRING_EQUAL_FATAL(str_with_odd_chars_num, "cba");

  RevertString(str_with_even_chars_num);
  CU_ASSERT_STRING_EQUAL_FATAL(str_with_even_chars_num, "dcba");
}

void testRevertStringTwo(void) {
  char str_empty="";
  char str_A="AAAAA";
  char str_int = "12345";

  RevertString(str_empty);
  CU_ASSERT_STRING_EQUAL_FATAL(str_empty, "");

  RevertString(str_A);
  CU_ASSERT_STRING_EQUAL_FATAL(str_with_odd_chars_num, "AAAAA");
  
  RevertString(str_int);
  CU_ASSERT_STRING_EQUAL_FATAL(str_int, "54321");
}

int main() {
  CU_pSuite pSuite = NULL;

  /* initialize the CUnit test registry */
  if (CUE_SUCCESS != CU_initialize_registry()) return CU_get_error();

  /* add a suite to the registry */
  pSuite = CU_add_suite("Suite", NULL, NULL);
  if (NULL == pSuite) {
    CU_cleanup_registry();
    return CU_get_error();
  }

  /* add the tests to the suite */
  /* NOTE - ORDER IS IMPORTANT - MUST TEST fread() AFTER fprintf() */
  if ((NULL == CU_add_test(pSuite, "test1 of RevertString function",
                           testRevertString)) ||
     (NULL == CU_add_test(pSuite, "test2 of RevertString function",
                           testRevertStringTwo)))
                         {
    CU_cleanup_registry();
    return CU_get_error();
  }
  

  /* Run all tests using the CUnit Basic interface */
  CU_basic_set_mode(CU_BRM_VERBOSE);
  CU_basic_run_tests();
  CU_cleanup_registry();
  return CU_get_error();
}
