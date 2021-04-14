/**
 * @file main.c
 * @author sankalp 256183
 * @brief main file with data input logic and function callings for file opertaion
 * @version 0.1
 * @date 2021-04-14
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include "billheader.h"

int main()
{
    float total_price = 0, discount = 0, final_price = 0, quantity = 0;
    char name[15], choice, choice2;
    int counter_number, total_item_no;

    printf("Welcome!, please enter the counter number\n");
    scanf("%d", &counter_number);

    printf("Please enter the name of customer\n");
    scanf("%s", name);

l2: //label 2
    total_price = 0;
    quantity = 0;
    printf("Enter total number of items:\n");
    scanf("%d", &total_item_no);

    item_details *ptr;
    ptr = (item_details *)calloc(total_item_no, sizeof(item_details));

    // input details of items
    for (int index = 0; index < total_item_no; index++)
    {
        printf("Enter detail of item no %d\n", index + 1);

        printf("Price:\n");
        scanf("%f", &ptr[index].price);

        printf("Quantity:\n");
        scanf("%d", &ptr[index].quantity);

        quantity = quantity + ptr[index].quantity;
    }

    // calculation of total price
    for (int index = 0; index < total_item_no; index++)
    {
        total_price = total_price + ((ptr[index].price) * (ptr[index].quantity));
    }

l1: //label 1 , Discount calculation
    printf("Apply Discount?, Y for 'yes' N for 'no'\n");
    getchar();
    scanf("%c", &choice);

    //conditions set1
    if (choice == 'Y')
    {
        printf("Enter Discount percentage:\n");
        scanf("%f", &discount);
        // final price after discount
        final_price = total_price - (total_price * (discount / 100));
    }

    else if (choice == 'N')
    {
        printf("No discount applied\n");
        final_price = total_price;
    }

    else
    {
        printf("Please enter correct choice\n");
        goto l1;
    }

l4: //label 4
    printf("Review input item details?, Y for 'yes' N for 'no'\n");
    getchar();
    scanf("%c", &choice);

    //condition set 2
    if (choice == 'Y')
    {
        // display all item details
        for (int index = 0; index < total_item_no; index++)
        {
            printf("Details of item no %d\n", index + 1);
            printf("Price: %f\n", ptr[index].price);
            printf("Quantity: %d\n", ptr[index].quantity);
            printf("\n");
        }

    l3: //label 3
        printf("Want to change input details?, Y for 'yes' N for 'no'\n");
        getchar();
        scanf("%c", &choice2);

        //condition set 3
        if (choice2 == 'Y')
            goto l2;

        else if (choice2 == 'N')
        {
            printf("Details saved!\n");
        }

        else
        {
            printf("Please enter correct choice\n");
            goto l3;
        }
    }

    else if (choice == 'N')
    {
        printf("Details Saved!");
    }

    else
    {
        printf("Please enter correct choice\n");
        goto l4;
    }

    //files logic & function calling

    // file pointers
    FILE *fptr = NULL;
    FILE *fptr2 = NULL;

    fptr = fopen("Template_no_2.txt", "r");
    fptr2 = fopen("genBill.txt", "w");

    char str[400];
    fgets(str, 400, fptr);
    char *newstr;

    //function pointer declaration of int_to_conversion()
    char *(*intts)(int);
    intts = int_to_string_conversion;

    //function pointer declaration of int_to_conversion()
    char *(*fts)(float);
    fts = float_to_string_conversion;

    newstr = replace_word(str, "{{name}}", name);
    newstr = replace_word(newstr, "{{counter_no}}", (intts)(counter_number));
    newstr = replace_word(newstr, "{{date}}", __DATE__);
    newstr = replace_word(newstr, "{{discount}}", (fts)(discount));
    newstr = replace_word(newstr, "{{final_price}}", (fts)(final_price));
    newstr = replace_word(newstr, "{{total_item_no}}", (intts)(quantity));
    newstr = replace_word(newstr, "{{total_price}}", (fts)(total_price));

    fprintf(fptr2, "%s", newstr);
    fclose(fptr);
    fclose(fptr2);
    free(ptr);
    return 0;
}
