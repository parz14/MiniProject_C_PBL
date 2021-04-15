#include "testcode.h"

/**
 * @brief function 1 : manages file operation to replace a file word with given word (input data), test function defination
 * 
 */
int replace_word(const char *str, const char *fileword, const char *realword)
{
    char *resultString;

    int index, count = 0;
    int realwordLength = strlen(realword);
    int filewordLength = strlen(fileword);
    for (index = 0; str[index] != '\0'; index++)
    {
        if (strstr(&str[index], fileword) == &str[index])
        {
            count++;
            index = index + filewordLength - 1;
        }
    }
    resultString = (char *)malloc(index + count * (realwordLength - filewordLength) + 1);
    index = 0;
    while (*str)
    {
        if (strstr(str, fileword) == str)
        {
            strcpy(&resultString[index], realword);
            index += realwordLength;
            str += filewordLength;
        }
        else
        {
            resultString[index] = *str;
            index += 1;
            str += 1;
        }
    }
    resultString[index] = '\0';
    //testing condition
    if (strstr(resultString, realword))
        return 1;
    else
        return 0;
}
