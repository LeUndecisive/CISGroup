#include <stdio.h>
#include <stdlib.h>

#include "loader.h"       // loader.c: load_all_* functions
#include "TechReport.h"   // TechReport.c: report functions
#include "cli.h"          // cli.c: run_cli()
#include "util.h"         // util.c: DataContext & free_data()

// File path macros (adjust names/paths as needed)
#define OS_FILE "FinalProjectDataOS.csv"
#define RS_FILE "FinalProjectDataRS.csv"
#define HS_FILE "FinalProjectDataHS.csv"
#define PS_FILE "FinalProjectDataPS.csv"

int main(int argc, char *argv[]) {
    // 1. Create context to hold all loaded data
    DataContext ctx;

    // 2. Load each data file via loader module
    ctx.oses       = load_all_os(OS_FILE,        &ctx.os_count);
    ctx.softs      = load_all_software(RS_FILE,  &ctx.sw_count);
    ctx.hvs        = load_all_hypervisors(HS_FILE, &ctx.hv_count);
    ctx.prods      = load_all_products(PS_FILE,  &ctx.prod_count);

    // 3. Check for loader errors (NULL on failure)
    if (!ctx.oses || !ctx.softs || !ctx.hvs || !ctx.prods) {
        fprintf(stderr, "Fatal: could not load one or more data files.\n");
        free_data(&ctx);  // cleanup any partially loaded data
        return EXIT_FAILURE;
    }

    // 4. Enter CLI loop; users choose report functions from TechReport
    run_cli(&ctx);

    // 5. After user exits, clean up all allocated memory
    free_data(&ctx);

    return EXIT_SUCCESS;
}
