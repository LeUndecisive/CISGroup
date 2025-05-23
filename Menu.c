/*---Info-Box-----------
*   CIS 220 Spring 2025 Final Project — User Interface Module
*   This file needs to be renamed for better clarification (To-DO)
*   Printing a single Product (PS) is not an option (To-Do or Not)
*   Print statements and more were altered, however not drastically changed
*   Print statements can be editited (Formating / Wording)
*/

#include <stdio.h>
#include <string.h>
#include <strings.h>
#include <ctype.h>
#include "Print.h" // Defines printf functions.
#include "Menu.h"       // Defines Self.
#include "Loader.h"     // Defines Nodes,List,loader functions.
#include "Main.h"       // Defines Data Context.

//------------------------------------------------------------------------
// Product-specific OS Support
//------------------------------------------------------------------------

void report_product_os(List *SentOS) {
    char input[6];  // Adjust size if needed.
    printf("\nEnter product ID: ");
    while (getchar() != '\n');  // flush previous newline.
    if (!fgets(input, sizeof(input), stdin)) return;
    input[strcspn(input, "\n")] = '\0';

    // Search for matching product by ID or name.
    Node *p = SearchForID(SentOS,input);

    // If not found notify user.
    if (!p) {
        printf("ID '%s' not found.\n", input);
         PrintALL_IDS(SentOS);
    }else{
        PrintNode_OS(p);
    }
    // Print the data of OS Node to user.

}

//------------------------------------------------------------------------
// Product-specific Software Support
//------------------------------------------------------------------------

void report_product_rs(List *SentRS) {
   char input[6];  // Adjust size if needed.
    printf("\nEnter product ID: ");
    while (getchar() != '\n');  // flush previous newline.
    if (!fgets(input, sizeof(input), stdin)) return;
    input[strcspn(input, "\n")] = '\0';

    // Search for matching product by ID or name.
    Node *p = SearchForID(SentRS,input);

    // If not found notify user.
    if (!p) {
        printf("ID '%s' not found.\n", input);
         PrintALL_IDS(SentRS);
    }else{
		printf("%-10s %-40s %-11s %-20s %-20s\n","ID","Name","Version","Platform","Release Date");
        PrintNode_RS(p);
    }
    // Print the data of RS Node to user.

}

//------------------------------------------------------------------------
// Product-specific Hypervisor Support
//------------------------------------------------------------------------

/* report_product_hv
Returns nothing.
Allows the user to input a product's
ID to not only search for that specific
item, but narrow down their search results 
so they do not feel overwhelmed when looking at
multiple results at once. The function also checks
to see if the inputed ID matches with any ones 
stored within the report files and prints a message
stating if a match has been found or not. 
*/
void report_product_hv(List *SentHV) {
 char input[6];  // Adjust size if needed.
    printf("\nEnter product ID: ");
    while (getchar() != '\n');  // flush previous newline.
    if (!fgets(input, sizeof(input), stdin)) 
	return;
    input[strcspn(input, "\n")] = '\0';

    // Search for matching product by ID or name.
    Node *p = SearchForID(SentHV,input);

    // If not found notify user.
    if (!p) {
        printf("ID '%s' not found.\n", input);
        PrintALL_IDS(SentHV);
    }else{
        PrintNode_HV(p);
    }
    // Print the data of HV Node to user.
	return;
}

//------------------------------------------------------------------------
// MENU
//------------------------------------------------------------------------

/* menu
Returns nothing.
Shows a menu of software 
reports that the user can select
from if they want to know any 
information about a paricular product
such as the name, release date, software 
version and so forth. */
void menu(DataContext *ctx) {
    int choice;
    do {
        printf("\n=== Software Compatibility Reports ===\n");
        // printf("1. OS support for a product\n");
        // printf("2. List all OS by platform\n");
        // printf("3. Software support for a product\n");
        // printf("4. List all software by category\n");
        // printf("5. Hypervisor support for a product\n");
        // printf("6. List all hypervisors\n");
        // printf("7. List all products\n");
		printf("1. List all products\n");
		printf("2. List all software by category\n");
		printf("3. Software support for a product\n");
		printf("4. List all OS by platform\n");
		printf("5. OS support for a product\n");
		printf("6. List all hypervisors\n");
		printf("7. Hypervisor support for a product\n");
		printf("0. Exit\n");
        printf("Select an option: ");
        if (scanf("%d", &choice) != 1) {
            while (getchar() != '\n');  // clear invalid input
            printf("Invalid input. Please enter a number.\n");
            continue;
        }
        switch (choice) {
            // case 1: report_product_os(&ctx->oses);   break;
            // case 2: PrintALL_OS(&ctx->oses);         break;
            // case 3: report_product_rs(&ctx->softs);  break;
            // case 4: PrintALL_RS(&ctx->softs);        break;
            // case 5: report_product_hv(&ctx->hvs);    break;
            // case 6: PrintALL_HV(&ctx->hvs);          break;
            // case 7: PrintALL_PS(&ctx->prods);        break;
			case 1: PrintALL_PS(&ctx->prods);       break;
			case 2: PrintALL_RS(&ctx->softs);       break;
			case 3: report_product_rs(&ctx->softs); break;
			case 4: PrintALL_OS(&ctx->oses);        break;
			case 5: report_product_os(&ctx->oses);  break;
			case 6: PrintALL_HV(&ctx->hvs);         break;
			case 7: report_product_hv(&ctx->hvs);   break;
            case 0: printf("Exiting...\n");         break;
            default: printf("Invalid option.\n");
        }
    } while (choice != 0);
}