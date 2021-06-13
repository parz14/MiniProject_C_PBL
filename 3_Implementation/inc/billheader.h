/**
 * @file billheader.h
 * @author sankalp 256183
 * @brief header file containing function declarations & structure definations
 * @version 0.1
 * @date 2021-04-14
 * 
 * @copyright Copyright (c) 2021
 * 
 */

// header guard

#ifndef BILL_HEADER
#define BILL_HEADER

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/**
 * @brief structure : containing details of the itmes
 * 
 */

typedef struct item_details
{
    int quantity;
    float price;
    float discount;
    float item_price;
} item_details;

/**
 * @brief function 1 : manages file operation to replace a file word with given word (input data)
 * 
 */
char *replace_word(const char *str, const char *fileword, const char *realword);

/**
 * @brief function 2: manages conversion of all integer values into string for file operations 
 * 
 */
char *int_to_string_conversion(int integer_no);

 /**
  * @brief function 2: manages conversion of all float values into string for file operations
  * 
  */
char *float_to_string_conversion(float float_no);

#endif
