#include "testcode.h"

/**
 * @brief function 2: manages conversion of all integer values into string for file operations, test function defination
 * 
 */
char string[15]; //for conversions functions
int test = 0;    // for testing int to string
float test2 = 0; // for testing float to string

int int_to_string_conversion(int integer_no)
{
    sprintf(string,"%d",integer_no);
    test = atoi(string);
    if (test == integer_no)
        return 1;
    else
        return 0;
}

/**
  * @brief function 2: manages conversion of all float values into string for file operations, test function defination
  * 
  */
int float_to_string_conversion(float float_no)
{
    gcvt(float_no, 5, string);
    test2 = atof(string);
    if ((int)test2 == (int)float_no)
        return 1;
    else
        return 0;
}
