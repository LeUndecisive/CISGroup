/*Info Box
]
]  DataContext *etc was altered to better fit with loader data
]
*/
#ifndef MAIN_H
#define MAIN_H
#include <stddef.h>
#include "Loader.h"

// Define DataContext to hold all lists of data.
typedef struct {
    List oses;         /**< Array of OperatingSystem entries */

    List softs;        /**< Array of Related Software entries */

    List hvs;          /**< Array of Hypervisor entries */

    List prods;        /**< Array of Product entries */

} DataContext;

// Function declarations
void free_data(DataContext *ctx);
#endif // MAIN_H
