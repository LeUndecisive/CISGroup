// Main.h <- util.h
#ifndef MAIN_H
#define MAIN_H

#include <stddef.h>
#include "loader.h"       // Defines OperatingSystem and Software structs
#include "TechReport.h"   // Defines Hypervisor and Product structs

/**----Menu-Funcs----------------
   Contains a function to be called within main.c
   Menu(DataContext)
*/

/**-----Print-Funcs---------------
    Contains the functions to be called by Menu
    PrintALL(DataContext)
*/


/**-----Loader-Funcs---------------
    Contains functions to be called by Menu and Print
    SearchForID(DataContext->List, ID)
    ReadStoredData( File, DataContext->List)
*/


/**---Data-Context-----------------
    Bundles all loaded data arrays and their counts into one struct
    so that loader, report, and CLI modules can share a single context.
*/

typedef struct {
    OperatingSystem *oses;    /**< Array of OperatingSystem entries */
    size_t           os_count;/**< Number of OperatingSystem entries */

    Software        *softs;   /**< Array of Software entries */
    size_t           sw_count;/**< Number of Software entries */

    Hypervisor      *hvs;     /**< Array of Hypervisor entries */
    size_t           hv_count;/**< Number of Hypervisor entries */

    Product         *prods;   /**< Array of Product entries */
    size_t           prod_count;/**< Number of Product entries */
} DataContext;

/**
 * free_data
 * Frees all memory allocated for the DataContext:
 *  - For each entry in each array, frees any internally allocated strings or pointers
 *  - Frees the arrays themselves
 *
 * @param ctx Pointer to DataContext to clean up
 */
void free_data(DataContext *ctx);

#endif // MAIN_H
