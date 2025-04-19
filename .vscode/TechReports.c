#include <stdio.h> 
#include <stdlib.h>
#include <string.h>
//#include <xlsxwriter.h>

#define OS_FILE "FinalProjectDataOS.csv"
#define RS_FILE "FinalProjectDataRS.csv"
#define HS_FILE "FinalProjectDataHS.csv"
#define PS_FILE "FinalProjectDataPS.csv"


void print_to_file(FILE *inFile, const char *data, int numbers){
	if (inFile == NULL) {
		printf("Error: Invalid file pointer. \n");
	}
	fprintf(inFile, "%s %d\n", data, numbers);
}

int main(void){

// Remember the file type is an xlsx.

FILE* inFile = NULL;

// Test to open the reports file.
printf("Opening file %s.\n", OS_FILE);

inFile = fopen(OS_FILE, "r");

if (inFile == NULL) {
	printf("Could not open file %s!\n", OS_FILE);
	return -1; // Indicates an error in "C". 
}


char string_val[1000];


while (fscanf(inFile, "%s", string_val) == 1) {
	printf("%s\n", string_val);
}


// printf("Opening file %s.\n", RS_FILE);
// inFile = fopen(RS_FILE, "r");

// printf("Opening file %s.\n", PS_FILE);
// inFile = fopen(PS_FILE, "r");

// printf("Opening file %s.\n", HS_FILE);
// inFile = fopen(HS_FILE, "r");





//print_to_file(inFile, "List of operating systems: ", 42);
//print_to_file(inFile, "List of operating systems: ", 123);






/* This is just to test to see if I can open and potentially read the 
   report on the operating systems before trying to print it. */

//printf("Reading Operating Systems.\n");
//fscanf(inFile, 




/* Clean-up */
fclose(inFile);


return 0;

}