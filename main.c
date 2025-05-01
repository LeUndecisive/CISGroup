#include <stdio.h>
#include <stdlib.h>

#include "Loader.h"       // loader.c: load_all_* functions
#include "TechReport.h"   // TechReport.c: report functions
#include "Menu.h"          
#include "Print.h"         
#include "Main.h"

// File path macros (adjust names/paths as needed)
#define OS_FILE "FinalProjectDataOS.csv"
#define RS_FILE "FinalProjectDataRS.csv"
#define HS_FILE "FinalProjectDataHS.csv"
#define PS_FILE "FinalProjectDataPS.csv"

// Function to load files
int load_files(DataContext* ctx, const char* os_file, const char* rs_file, const char* hs_file, const char* ps_file) {
    ctx->oses = load_all_os(os_file, &ctx->os_count);
    ctx->softs = load_all_software(rs_file, &ctx->sw_count);
    ctx->hvs = load_all_hypervisors(hs_file, &ctx->hv_count);
    ctx->prods = load_all_products(ps_file, &ctx->prod_count);

    if (!ctx->oses || !ctx->softs || !ctx->hvs || !ctx->prods) {
        fprintf(stderr, "Fatal: could not load one or more data files.\n");
        free_data(ctx);
        return 0; // Failure
    }
    return 1; // Success
}

int main(int argc, char *argv[]) {
    if (argc < 5) {
        fprintf(stderr, "Error: Not enough arguments.\n");
        return EXIT_FAILURE;
    }

    DataContext ctx;
    
    if (!load_files(&ctx, argv[1], argv[2], argv[3], argv[4])) {
        return EXIT_FAILURE;
    }

    // Run the CLI loop
    run_cli(&ctx);

    // Clean up and exit
    free_data(&ctx);
    return EXIT_SUCCESS;
}
