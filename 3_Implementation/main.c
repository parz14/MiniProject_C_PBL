/**
 * @file main.c
 * @author sankalp 256183
 * @brief main file with data input logic and function callings for file opertaion
 * @version 0.1
 * @date 2021-06-13
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include "billheader.h"

int main()
{
    float total_price = 0, discount = 0, final_price = 0;

    char name[15], choice, choice2, choice3, choice4;

    int counter_number, item_number, total_item_no = 0, index = 0, quantity = 0, quantity_change = 0, difference = 0;

    printf("Welcome!, please enter the counter number\n");
    scanf("%d", &counter_number);

    printf("Please enter the name of customer\n");
    scanf("%s", name);

    //dynamic structure array for item details
    item_details *ptr;
    //need to change initillization
    ptr = (item_details *)calloc(10, sizeof(item_details));

    /* **********MODULE 1: input details of items********** */
    do
    {
        //price
        printf("Enter detail of item no %d\n", index + 1);
        printf("Price:\n");
        scanf("%f", &ptr[index].price);

    //discount on individual item
    l1: //label 1
        printf("Apply Product Discount?, Y for 'yes' N for 'no'\n");
        getchar();
        scanf("%c", &choice);

        //discount logic
        if (choice == 'Y')
        {
            printf("Enter Discount percentage:\n");
            scanf("%f", &ptr[index].discount);
            // final price of item after discount
            ptr[index].item_price = ptr[index].price - (ptr[index].price * (ptr[index].discount / 100));
        }

        else if (choice == 'N')
        {
            printf("No discount applied\n");
            ptr[index].item_price = ptr[index].price;
        }

        else
        {
            printf("Please enter correct choice\n");
            goto l1;
        }

        //quantity of item
        printf("Quantity:\n");
        scanf("%d", &ptr[index].quantity);

        //total quantity
        quantity = quantity + ptr[index].quantity;

        //to add new item details
        printf("Add new item?, Y for 'yes' N for 'no'\n");
        getchar();
        scanf("%c", &choice2);
        index++;
        total_item_no++;

    } while (choice2 == 'Y');

    /*// calculation of total price of all items
    for (index = 0; index < total_item_no; index++)
    {
        total_price = total_price + ((ptr[index].item_price) * (ptr[index].quantity));
    }*/

    /* **********MODULE 2: Review of input details and editing********** */

    //*****REVIEW*****

l2: //label 2
    printf("Review input item details?, Y for 'yes' N for 'no'\n");
    getchar();
    scanf("%c", &choice);

    if (choice == 'Y')
    {
        // display all item details
        for (index = 0; index < total_item_no; index++)
        {
            printf("Details of item no %d\n", index + 1);
            printf("Total Price: %f\n", (ptr[index].item_price * ptr[index].quantity));
            printf("Quantity: %d\n", ptr[index].quantity);
            printf("\n");
        }

        //*****Input Details Editing*****

    l3: //label 3
        printf("Edit input details?, Y for 'yes' N for 'no'\n");
        getchar();
        scanf("%c", &choice2);

        if (choice2 == 'Y')
        {
            printf("Enter the Item number to be updated:\n");
            scanf("%d", &item_number);
        l4: //label 4
            printf("Delete or Update Item number %d?, D for 'delete' U for 'update'\n", item_number);
            getchar();
            scanf("%c", &choice3);
            //DELETE
            if (choice3 == 'D')
            {
                quantity = quantity - ptr[item_number - 1].quantity;
                for (index = item_number; index < total_item_no; index++)
                {
                    ptr[index - 1].price = ptr[index].price;
                    ptr[index - 1].discount = ptr[index].discount;
                    ptr[index - 1].quantity = ptr[index].quantity;
                    ptr[index - 1].item_price = ptr[index].item_price;
                }
                total_item_no--;
            
                //display items after deletion
                for (index = 0; index < total_item_no; index++)
                {
                    printf("Details of item no %d\n", index + 1);
                    printf("Total Price: %f\n", (ptr[index].item_price * ptr[index].quantity));
                    printf("Quantity: %d\n", ptr[index].quantity);
                    printf("\n");
                }
                goto l3;
            }

            //UPDATE
            else if (choice3 == 'U')
            {
                //update price
                printf("Price:\n");
                scanf("%f", &ptr[item_number - 1].price);

            //update discount
            l5: //label 5
                printf("Update Product Discount?, Y for 'yes' N for 'no'\n");
                getchar();
                scanf("%c", &choice4);
                //discount logic
                if (choice4 == 'Y')
                {
                    printf("Enter Discount percentage:\n");
                    scanf("%f", &ptr[item_number - 1].discount);
                    // final price after updated discount
                    ptr[item_number - 1].item_price = ptr[item_number - 1].price - (ptr[item_number - 1].price * (ptr[item_number - 1].discount / 100));
                }

                else if (choice4 == 'N')
                {
                    printf("No discount applied\n");
                    ptr[item_number - 1].item_price = ptr[item_number - 1].price;
                }

                else
                {
                    printf("Please enter correct choice\n");
                    goto l5;
                }

                //update quantity
                printf("Quantity:\n");
                scanf("%d", &quantity_change);
                
                //total quantity calculation after update
                if (quantity_change > ptr[item_number - 1].quantity)
                {
                    difference = quantity_change - ptr[item_number - 1].quantity;
                    quantity = quantity + difference;
                }
                else
                {
                    difference = ptr[item_number - 1].quantity - quantity_change;
                    quantity = quantity - difference;
                }
                ptr[item_number - 1].quantity = quantity_change;
                //display items after updation
                for (index = 0; index < total_item_no; index++)
                {
                    printf("Details of item no %d\n", index + 1);
                    printf("Total Price: %f\n", (ptr[index].item_price * ptr[index].quantity));
                    printf("Quantity: %d\n", ptr[index].quantity);
                    printf("\n");
                }
                goto l3;
            }

            else
            {
                printf("Please enter correct choice\n");
                goto l4;
            }
        }

        else if (choice2 == 'N')
        {
            printf("No Edits!, Item Details Saved!\n");
        }

        else
        {
            printf("Please enter correct choice\n");
            goto l3;
        } // End of EDITING PART
    }

    else if (choice == 'N')
    {
        printf("No Review!, Item Details Saved!\n");
    }
    else
    {
        printf("Please enter correct choice\n");
        goto l2;
    }

    // calculation of final total price after full update
    for (index = 0; index < total_item_no; index++)
    {
        total_price = total_price + ((ptr[index].item_price) * (ptr[index].quantity));
    }

/* **********MODULE 3: Overall Discount Calculation********** */
l6: //label 6
    printf("Apply Overall Discount?, Y for 'yes' N for 'no'\n");
    getchar();
    scanf("%c", &choice);

    if (choice == 'Y')
    {
        printf("Enter Discount percentage:\n");
        scanf("%f", &discount);
        // final price after discount
        final_price = total_price - (total_price * (discount / 100));
    }

    else if (choice == 'N')
    {
        printf("No overall discount applied\n");
        final_price = total_price;
    }

    else
    {
        printf("Please enter correct choice\n");
        goto l6;
    }

/* **********MODULE 4: Bill Generartion********** */
l7: //label 7
    printf("Generate Bill?, Y for 'yes' N for 'no'\n");
    getchar();
    scanf("%c", &choice);
    if (choice == 'Y')
    {
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

    else if (choice == 'N')
    {
        free(ptr);
        return 0;
    }
    else
    {
        printf("Please enter correct choice\n");
        goto l7;
    }
}
