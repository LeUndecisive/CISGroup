/*
 * compatibility_ui.c
 * CIS 220 Spring 2025 Final Project — User Interface Module
 *
 * I figured it would be easier to upload a new file instead of trying to make all of the changes in the old one. I revamped a LOT of the code and implemented the neccesary code from the other files
 *
 * NOTE: "TODO" comments mark where we should plug our actual code in once the definitions
 * are in place.
 */

#include <stdio.h>
#include <string.h>
#include <strings.h>
#include <ctype.h>
#include "Menu.h"
#include "Main.h"  // Defines DataContext, OperatingSystem, RelatedSoftware, Hypervisor, Product

//------------------------------------------------------------------------
// MENU
//------------------------------------------------------------------------

void menu(DataContext *ctx) {
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
            while (getchar() != '\n');  // clear invalid input
            printf("Invalid input. Please enter a number.\n");
            continue;
        }
        switch (choice) {
            case 1: report_product_os(ctx);            break;
            case 2: list_all_os_by_platform(ctx);     break;
            case 3: report_product_sw(ctx);            break;
            case 4: list_all_sw_by_category(ctx);     break;
            case 5: report_product_hv(ctx);            break;
            case 6: list_all_hv(ctx);                 break;
            case 7: list_all_products(ctx);           break;
            case 0: printf("Exiting...\n");         break;
            default: printf("Invalid option.\n");
        }
    } while (choice != 0);
}

//------------------------------------------------------------------------
// Product-specific OS Support
//------------------------------------------------------------------------

void report_product_os(DataContext *ctx) {
    char input[100];  // Adjust size if needed
    printf("\nEnter product ID or name: ");
    while (getchar() != '\n');  // flush previous newline
    if (!fgets(input, sizeof(input), stdin)) return;
    input[strcspn(input, "\n")] = '\0';

    // Search for matching product by ID or name
    Product *p = NULL;
    for (size_t i = 0; i < ctx->prod_count; i++) {
        // TODO: change field names to match our Product struct
        if (strcasecmp(ctx->prods[i].id,   input) == 0 ||
            strcasecmp(ctx->prods[i].name, input) == 0) {
            p = &ctx->prods[i];
            break;
        }
    }
    if (!p) {
        printf("Product '%s' not found.\n", input);
        return;
    }

    // TODO: replace `os_ids` and `os_count` with our actual Product fields
    if (p->os_count == 0) {
        printf("No operating systems listed for '%s'.\n", p->name);
        return;
    }
    printf("\nOperating Systems supported by '%s':\n", p->name);
    for (size_t k = 0; k < p->os_count; k++) {
        char *osid = p->os_ids[k];  // placeholder
        // Find full OS info by ID
        for (size_t j = 0; j < ctx->os_count; j++) {
            if (strcasecmp(ctx->oss[j].id, osid) == 0) {
                printf(" - %s (Platform: %s)\n",
                       ctx->oss[j].name,
                       ctx->oss[j].platform);
                break;
            }
        }
    }
}

//------------------------------------------------------------------------
// All OS Grouped by Platform
//------------------------------------------------------------------------

void list_all_os_by_platform(DataContext *ctx) {
    // Collect unique platforms
    char *platforms[1000];
    size_t plat_count = 0;
    for (size_t i = 0; i < ctx->os_count; i++) {
        const char *plat = ctx->oss[i].platform;
        int seen = 0;
        for (size_t j = 0; j < plat_count; j++) {
            if (strcmp(platforms[j], plat) == 0) { seen = 1; break; }
        }
        if (!seen && plat_count < 1000) {
            platforms[plat_count++] = (char*)plat;
        }
    }

    // Print each platform and its OS
    for (size_t pi = 0; pi < plat_count; pi++) {
        printf("\nPlatform: %s\n", platforms[pi]);
        for (size_t i = 0; i < ctx->os_count; i++) {
            if (strcmp(ctx->oss[i].platform, platforms[pi]) == 0) {
                printf(" - %s (ID: %s)\n",
                       ctx->oss[i].name,
                       ctx->oss[i].id);
            }
        }
    }
}

//------------------------------------------------------------------------
// Product-specific Software Support
//------------------------------------------------------------------------

void report_product_sw(DataContext *ctx) {
    char input[100];
    printf("\nEnter product ID or name: ");
    while (getchar() != '\n');
    if (!fgets(input, sizeof(input), stdin)) return;
    input[strcspn(input, "\n")] = '\0';

    Product *p = NULL;
    for (size_t i = 0; i < ctx->prod_count; i++) {
        if (strcasecmp(ctx->prods[i].id,   input) == 0 ||
            strcasecmp(ctx->prods[i].name, input) == 0) {
            p = &ctx->prods[i];
            break;
        }
    }
    if (!p) {
        printf("Product '%s' not found.\n", input);
        return;
    }

    // TODO: replace `sw_ids` and `sw_count` with the actual fields
    if (p->sw_count == 0) {
        printf("No software listed for '%s'.\n", p->name);
        return;
    }
    printf("\nRelated Software supported by '%s':\n", p->name);
    for (size_t k = 0; k < p->sw_count; k++) {
        char *swid = p->sw_ids[k];  // placeholder
        for (size_t j = 0; j < ctx->sw_count; j++) {
            if (strcasecmp(ctx->sws[j].id, swid) == 0) {
                printf(" - %s (Category: %s)\n",
                       ctx->sws[j].name,
                       ctx->sws[j].category);
                break;
            }
        }
    }
}

//------------------------------------------------------------------------
// All Software Grouped by Category
//------------------------------------------------------------------------

void list_all_sw_by_category(DataContext *ctx) {
    char *categories[1000];
    size_t cat_count = 0;
    for (size_t i = 0; i < ctx->sw_count; i++) {
        const char *cat = ctx->sws[i].category;
        int seen = 0;
        for (size_t j = 0; j < cat_count; j++) {
            if (strcmp(categories[j], cat) == 0) { seen = 1; break; }
        }
        if (!seen && cat_count < 1000) {
            categories[cat_count++] = (char*)cat;
        }
    }

    for (size_t ci = 0; ci < cat_count; ci++) {
        printf("\nCategory: %s\n", categories[ci]);
        for (size_t i = 0; i < ctx->sw_count; i++) {
            if (strcmp(ctx->sws[i].category, categories[ci]) == 0) {
                printf(" - %s (ID: %s)\n",
                       ctx->sws[i].name,
                       ctx->sws[i].id);
            }
        }
    }
}

//------------------------------------------------------------------------
// Product-specific Hypervisor Support
//------------------------------------------------------------------------

void report_product_hv(DataContext *ctx) {
    char input[100];
    printf("\nEnter product ID or name: ");
    while (getchar() != '\n');
    if (!fgets(input, sizeof(input), stdin)) return;
    input[strcspn(input, "\n")] = '\0';

    Product *p = NULL;
    for (size_t i = 0; i < ctx->prod_count; i++) {
        if (strcasecmp(ctx->prods[i].id,   input) == 0 ||
            strcasecmp(ctx->prods[i].name, input) == 0) {
            p = &ctx->prods[i];
            break;
        }
    }
    if (!p) {
        printf("Product '%s' not found.\n", input);
        return;
    }

    // TODO: replace `hv_ids` and `hv_count` with the actual fields
    if (p->hv_count == 0) {
        printf("No hypervisors listed for '%s'.\n", p->name);
        return;
    }
    printf("\nHypervisors supported by '%s':\n", p->name);
    for (size_t k = 0; k < p->hv_count; k++) {
        char *hvid = p->hv_ids[k];  // placeholder
        for (size_t j = 0; j < ctx->hv_count; j++) {
            if (strcasecmp(ctx->hvs[j].id, hvid) == 0) {
                printf(" - %s\n", ctx->hvs[j].name);
                break;
            }
        }
    }
}

//------------------------------------------------------------------------
// All Hypervisors
//------------------------------------------------------------------------

void list_all_hv(DataContext *ctx) {
    printf("\nHypervisors:\n");
    for (size_t i = 0; i < ctx->hv_count; i++) {
        printf(" - %s (ID: %s)\n", ctx->hvs[i].name, ctx->hvs[i].id);
    }
}

//------------------------------------------------------------------------
// All Products
//------------------------------------------------------------------------

void list_all_products(DataContext *ctx) {
    printf("\nProducts:\n");
    for (size_t i = 0; i < ctx->prod_count; i++) {
        printf(" - %s (ID: %s)\n", ctx->prods[i].name, ctx->prods[i].id);
    }
}
