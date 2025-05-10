/*Info Box
]
]   The program is all connected together with the other files (after testing and correcting)
]   TechReport.C - TO DO - PrintStatements
]   Loader.c - TO DO - Free_Data
]   updated_compatibility_ui.c - TO DO - Rename the file -
]   updated_compatibility_ui.c - Optional - The option to print seperate Products (PS) is missing
]   TechReport.C - Optional - PrintNode_PS If its decided to have ^the above^ then this is required)
]   The main comparission may also have to get checked out
*/
#include <stdio.h>
#include <stdlib.h>
#include "Loader.h" // loader.c: load_all_* functions
#include "Print.h" // TechReport.c: Print functions
#include "Menu.h"
#include "Main.h"

// File path macros (adjust names/paths as needed).
#define OS_FILE "FinalProjectDataOS.csv"
#define RS_FILE "FinalProjectDataRS.csv"
#define HV_FILE "FinalProjectDataHV.csv"
#define PS_FILE "FinalProjectDataPS.csv"

/* load_files
Returns a message.
Loads all the required report 
files to be read and checks
to see if any of them can be loaded
and then prints a message to 
the user to confirm 
a success or failure. 
*/
int load_files(DataContext* ctx, const char* os_file, const char* rs_file, const char* hv_file, const char* ps_file) {

    initList(&ctx->oses);
    initList(&ctx->softs);
    initList(&ctx->hvs);
    initList(&ctx->prods);

    LoadAll_OS(os_file,&ctx->oses);
    LoadAll_RS(rs_file,&ctx->softs);
    LoadAll_HV(hv_file,&ctx->hvs);
    LoadAll_PS(ps_file,&ctx->prods);


    /** The contents of DataContext* have been altered resulting in this change

    */
    if (!&ctx->oses || !&ctx->softs || !&ctx->hvs || !&ctx->prods) {
            fprintf(stderr, "Fatal: could not load one or more data files.\n");
            free_data(ctx);
            return 0; // Failure
        }
    return 1; // Success



}

//------The-main-which-runs-all----------------

int main() {
//--Replaced Parts of main
    char *FILEARRAY[] = {OS_FILE,RS_FILE,HV_FILE,PS_FILE};

    DataContext ctx;

    if (!load_files(&ctx, FILEARRAY[0], FILEARRAY[1], FILEARRAY[2], FILEARRAY[3])) {
        return EXIT_FAILURE;
    }

    // Run the Menu  loop
    menu(&ctx);

    // Clean up and exit
    free_data(&ctx);
    return EXIT_SUCCESS;
}
