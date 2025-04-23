/*
 * compatibility_ui_template.c
 * this is just a template I made so far. i will adjust the code accordingly when the header file is done
 *
 */

#ifndef COMPATIBILITY_REPORTS_H
#define MAX_NAME_LEN 100
#define MAX_ITEMS    1000

// Placeholder struct definitions
typedef struct {
    char name[MAX_NAME_LEN];
    char platform[MAX_NAME_LEN];
} OperatingSystem;

typedef struct {
    char name[MAX_NAME_LEN];
    char category[MAX_NAME_LEN];
} RelatedSoftware;

typedef struct {
    char name[MAX_NAME_LEN];
} Hypervisor;

typedef struct {
    char name[MAX_NAME_LEN];
    char **os_names;
    int os_count;
    char **sw_names;
    int sw_count;
    char **hyper_names;
    int hyper_count;
} Product;

// Placeholder extern declarations; ensure these match the actual globals when ported
extern OperatingSystem os_list[MAX_ITEMS];
extern int              os_count;
extern RelatedSoftware  sw_list[MAX_ITEMS];
extern int              sw_count;
extern Hypervisor       hv_list[MAX_ITEMS];
extern int              hv_count;
extern Product          prod_list[MAX_ITEMS];
extern int              prod_count;

#endif // COMPATIBILITY_REPORTS_H

#include <stdio.h>
#include <string.h>
#include <strings.h>
#include <ctype.h>

// UI function prototypes
void menu(void);
void report_product_os(void);
void list_all_os_by_platform(void);
void report_product_sw(void);
void list_all_sw_by_category(void);
void report_product_hv(void);
void list_all_hv(void);
void list_all_products(void);

void menu() {
    int choice;
    do {
        printf("\n=== Software Compatibility Reports ===\n");
        printf("1. OS support for a product\n");
        printf("2. List all OS by platform\n");
        printf("3. Software support for a product\n");
        printf("4. List all software by category\n");
        printf("5. Hypervisor support for a product\n");
        printf("6. List all hypervisors\n");
        printf("7. List all products\n");
        printf("0. Exit\n");
        printf("Select an option: ");
        if (scanf("%d", &choice) != 1) {
            while (getchar() != '\\n');
            printf("Invalid input. Please enter a number.\n");
            continue;
        }
        switch (choice) {
            case 1: report_product_os(); break;
            case 2: list_all_os_by_platform(); break;
            case 3: report_product_sw(); break;
            case 4: list_all_sw_by_category(); break;
            case 5: report_product_hv(); break;
            case 6: list_all_hv(); break;
            case 7: list_all_products(); break;
            case 0: printf("Exiting...\n"); break;
            default: printf("Invalid option.\n");
        }
    } while (choice != 0);
}

void report_product_os() {
    char input[MAX_NAME_LEN];
    printf("\nEnter product name: ");
    while (getchar() != '\\n');
    if (!fgets(input, sizeof(input), stdin)) return;
    input[strcspn(input, "\\n")] = '\\0';

    // ... (implementation as before) ...
    printf("[report_product_os implementation goes here]\\n");
}

void list_all_os_by_platform() {
    // ... (implementation placeholder) ...
    printf("[list_all_os_by_platform implementation goes here]\\n");
}

void report_product_sw() {
    char input[MAX_NAME_LEN];
    printf("\nEnter product name: ");
    while (getchar() != '\\n');
    if (!fgets(input, sizeof(input), stdin)) return;
    input[strcspn(input, "\\n")] = '\\0';

    // ... (implementation placeholder) ...
    printf("[report_product_sw implementation goes here]\\n");
}

void list_all_sw_by_category() {
    // ... (implementation placeholder) ...
    printf("[list_all_sw_by_category implementation goes here]\\n");
}

void report_product_hv() {
    char input[MAX_NAME_LEN];
    printf("\nEnter product name: ");
    while (getchar() != '\\n');
    if (!fgets(input, sizeof(input), stdin)) return;
    input[strcspn(input, "\\n")] = '\\0';

    // ... (implementation placeholder) ...
    printf("[report_product_hv implementation goes here]\\n");
}

void list_all_hv() {
    printf("\nHypervisors:\n");
    for (int i = 0; i < hv_count; i++) {
        printf(" - %s\n", hv_list[i].name);
    }
}

void list_all_products() {
    printf("\nProducts:\n");
    for (int i = 0; i < prod_count; i++) {
        printf(" - %s\n", prod_list[i].name);
    }
}
