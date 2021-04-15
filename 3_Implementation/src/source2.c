#include "billheader.h"

/**
 * @brief function 2: manages conversion of all integer values into string for file operations 
 * 
 */
char string[15]; //for conversions functions

char *int_to_string_conversion(int integer_no)
{
    sprintf(string,"%d",integer_no);
    return string;
}


/**
  * @brief function 2: manages conversion of all float values into string for file operations
  * 
  */
char *float_to_string_conversion(float float_no)
{
    gcvt(float_no, 5, string);
    return string;
}
