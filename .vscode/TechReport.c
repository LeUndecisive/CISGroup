#include <stdio.h> 
#include <stdlib.h>
#include <string.h>

/* What I had to do was send each individual report
   to my Google Drive on Windows, log into the VLE
   and download them, and then convert each one into
   a csv file. Then after that, I was able to run and 
   display them using the Linux terminal. */
   
/* Here in C, you can define the type of files you
   want and easily use them for various tasks. */
   
/* In this case, you need the FILE portion for the
   naming conventions, but then you can do what you
   want after that. Here I used two letters to define
   each file name. So OS = Operating Systems, 
   RS = Related Software, HS = Hypervisors, and
   PS = Products. I personally named the files
   FinalProjectData along with their individual
   letters to signal which reports they belong
   too. If we want, we can change the names. */
   
#define OS_FILE "FinalProjectDataOS.csv" 
#define RS_FILE "FinalProjectDataRS.csv"
#define HS_FILE "FinalProjectDataHS.csv"
#define PS_FILE "FinalProjectDataPS.csv"							

// Code so far works without the function. READ BELOW.

/* I will eventually change the variable names in the function.
   But so far, it is just a sample and I believe it does not need 
   to be changed. When the time comes I will have to call it. 
   Potentially I may also have to create copies of this function,
   unless I can apply it to all the reports.*/
void print_to_file(FILE *inFile, const char *data, int numbers){
	if (inFile == NULL) {
		printf("Error: Invalid file pointer. \n");
	}
	fprintf(inFile, "%s %d\n", data, numbers);
}

int main(void){

/* Goes to general structure of the filing system
   But it can be changed and may be used for 
   a typedef struct if we all want to use those. */
FILE* inFile = NULL; 

// Test to open and read the OS report file.
printf("Opening file %s.\n", OS_FILE);

inFile = fopen(OS_FILE, "r");

/* Condition stating what happens if a file
   could not be opened. */
if (inFile == NULL) {
	printf("Could not open file %s!\n", OS_FILE);
	return -1; // Indicates an error in "C". 
}

/* Here I decided to create a temporary array for 
   now so the program could read all the characters
   including spaces within the
   files. We can keep it if we want, it 
   might be best that way. */
char string_val[1000];

/* Extra comments below are all the individual 
   files to be opened and closed, I have not
   yet figured out how to open all at once instead
   of individual at a time. I don't know if there is
   a more effecient way to do it, but just in case,
   I commented them all out and kept them. */
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