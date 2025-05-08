/*
C - Group: Nicholas, Joshua, Austin, and William 
Documented by Nicholas
*/

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
#include "Loader.h"       // loader.c: load_all_* functions
#include "Print.h"   // TechReport.c: Print functions
#include "Menu.h"
#include "Main.h"

// File path macros (adjust names/paths as needed)
#define OS_FILE "FinalProjectDataOS.csv"
#define RS_FILE "FinalProjectDataRS.csv"
#define HV_FILE "FinalProjectDataHV.csv"
#define PS_FILE "FinalProjectDataPS.csv"
#define FILE_LOAD_FAIL 0;
#define FILE_LOAD_SUCCESS 1;

/* 
Function to load files 
in order to gather all the required 
context within each file. 
*/
int load_files(DataContext* ctx, const char* os_file, const char* rs_file, const char* hv_file, const char* ps_file) {
	
	printf("Here.\n");
    initList(&ctx->oses);
    initList(&ctx->softs);
    initList(&ctx->hvs);
    initList(&ctx->prods);
	
	printf("Or Here.\n");

    LoadAll_OS(os_file,&ctx->oses);
    LoadAll_RS(rs_file,&ctx->softs);
    LoadAll_HV(hv_file,&ctx->hvs);
    LoadAll_PS(ps_file,&ctx->prods);

	/*
	Check to see if all or any of 
	the files could be loaded, if not
	the program will stop.
	*/
	if (!&ctx->oses || !&ctx->softs || !&ctx->hvs || !&ctx->prods) {
            fprintf(stderr, "Fatal: could not load one or more data files.\n");
            free_data(ctx);
            return FILE_LOAD_FAIL; 
        }
    return FILE_LOAD_SUCCESS;
}




/** Hard written data For running program with file
    This was created for my own testing purposes, as LeUndecisive is unable to directly input the necessary files due to their compilier

    char *FILEARRAY[] = {"CommandCall",OS_FILE,RS_FILE,HV_FILE,PS_FILE};

    DataContext ctx;

    if (!load_files(&ctx, FILEARRAY[1], FILEARRAY[2], FILEARRAY[3], FILEARRAY[4])) {
        return EXIT_FAILURE;
    }
*/

//------The-main-which-runs-all----------------

/* 
Gathering the number of things inputed into
the terminal command, with the first being gcc.
The next pieces of information gathered, are the 
additional array of string letter characters.

argc is the number of items in the command.
argv is the number of strings in the command. 
*/
int main(int argc, char *argv[]) {

    if (argc < 5) { // Checks to see if the all the files have been entered. 
        fprintf(stderr, "Error: Not enough arguments.\n");
        return EXIT_FAILURE;
    }

    DataContext ctx;
	printf("Here.\n");
	
	// Checks to make sure the files were correctly loaded. 
    if (!load_files(&ctx, argv[1], argv[2], argv[3], argv[4])) {
        return EXIT_FAILURE;
    }

    // Run the Menu loop.
    menu(&ctx);

    // Clean up and exit.
    free_data(&ctx);
    return EXIT_SUCCESS;
}