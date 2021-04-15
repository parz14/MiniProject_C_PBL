#include "unity_internals.h"
#include "unity.h"
#include "testcode.h"

void test_replace_word(void);
void test_int_to_string_conversion(void);
void test_float_to_string_conversion(void);

/* Required by the unity test framework */
void setUp(){}
/* Required by the unity test framework */
void tearDown(){}

/* Start of the application test */
int main()
{
/* Initiate the Unity Test Framework */
  UNITY_BEGIN();

/* Run Test functions */
  RUN_TEST(test_replace_word);
  RUN_TEST(test_int_to_string_conversion);
  RUN_TEST(test_float_to_string_conversion);

  /* Close the Unity Test Framework */
  return UNITY_END();
}

/* Write all the test functions */ 

//replace_word
void test_replace_word(void)
{
  FILE * ptr;
  ptr=fopen("Template_no_2.txt","r");
  char str[400];
  fgets(str, 400, ptr);
  fclose(ptr);
  TEST_ASSERT_EQUAL(1, replace_word(str,"{{name}}", "sankalp"));
  TEST_ASSERT_EQUAL(1, replace_word(str,"{{counter_no}}", "10"));
  TEST_ASSERT_EQUAL(0, replace_word(str,"{{unknown}}", "250"));
  TEST_ASSERT_EQUAL(1, replace_word(str,"{{discount}}", "45.6"));
  TEST_ASSERT_EQUAL(1, replace_word(str,"{{date}}", __DATE__));
  TEST_ASSERT_EQUAL(0, replace_word(str,"{{price}}", "1000"));
  
}

//int_to_string_conversion
void test_int_to_string_conversion(void)
{
  TEST_ASSERT_EQUAL(1, int_to_string_conversion(56));
  TEST_ASSERT_EQUAL(1, int_to_string_conversion(1342));
}

//float_to_string_conversion
void test_float_to_string_conversion(void)
{
  TEST_ASSERT_EQUAL(1, float_to_string_conversion(56.5));
  TEST_ASSERT_EQUAL(1, float_to_string_conversion(13.42));
}

