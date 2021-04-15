/**
 * @file testcode.h
 * @author sankalp 256183
 * @brief header file containing function declarations for test code
 * @version 0.1
 * @date 2021-04-14
 * 
 * @copyright Copyright (c) 2021
 * 
 */

// header guard

#ifndef TEST_CODE
#define TEST_CODE

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/**
 * @brief function 1 : manages file operation to replace a file word with given word (input data)
 * 
 */
int replace_word(const char *str, const char *fileword, const char *realword);

/**
 * @brief function 2: manages conversion of all integer values into string for file operations 
 * 
 */
int int_to_string_conversion(int integer_no);

 /**
  * @brief function 2: manages conversion of all float values into string for file operations
  * 
  */
int float_to_string_conversion(float float_no);

#endif
