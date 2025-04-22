// util.c
#include "util.h"
#include <stdlib.h>
#include <stdio.h>

void free_data(DataContext *ctx) {
    if (!ctx) return;

    // Free OperatingSystem entries
    for (size_t i = 0; i < ctx->os_count; i++) {
        // Assuming loader strdup'd id, name, platform
        free(ctx->oses[i].id);
        free(ctx->oses[i].name);
        free(ctx->oses[i].platform);
    }
    free(ctx->oses);

    // Free Software entries
    for (size_t i = 0; i < ctx->sw_count; i++) {
        // Assuming loader strdup'd id, name, category
        free(ctx->softs[i].id);
        free(ctx->softs[i].name);
        free(ctx->softs[i].category);
    }
    free(ctx->softs);

    // Free Hypervisor entries
    for (size_t i = 0; i < ctx->hv_count; i++) {
        // Assuming loader strdup'd id and name
        free(ctx->hvs[i].id);
        free(ctx->hvs[i].name);
    }
    free(ctx->hvs);

    // Free Product entries
    for (size_t i = 0; i < ctx->prod_count; i++) {
        // Assuming loader strdup'd id, name, and other strings
        free(ctx->prods[i].id);
        free(ctx->prods[i].name);
        // free any other strdup'd fields here
    }
    free(ctx->prods);

    // Optionally: zero out counts
    ctx->os_count   = 0;
    ctx->sw_count   = 0;
    ctx->hv_count   = 0;
    ctx->prod_count = 0;
}