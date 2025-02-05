#include <stdio.h>
#include <string.h>

char* ReverseString(char* stringToReverse) {
	/* TODO: Complete recursive ReverseString() function here. */
     
    int length = 0; 
	
	/* To reverse characters in an array, we need to find the length.
	But because we do not know how many indexes the user plans to put in, 
	we need the strlen function and then assign it to our function 
	"stringToReverse" and variable "length." */
	length = strlen(stringToReverse); 
	
	/* In C,  the number 1 acts as an error code. So in this case the statment 
	checks to see if the array is empty 
	and if so, it will automatically exit the whole function and return to main. 
	*/
	
	
	if (length == 1) {
			return stringToReverse; 
	}
	
	/* If the array is not empty, the following procedure immediately 
	takes place below */
	else { 
		
		/* With a pointer, we indicate that it is pointing to the first value 
		in the array (a character) and then 
		and it will point to the next value until all the values imputed have 
		been fully pointed to. */
		
		char* newArray = ReverseString(stringToReverse + 1); 
		
		/* Now, we need to reverse the characters, and the 
		best way is to make whatever the end value is as the 
		first value to be printed at index 0. */
		
		newArray[length - 1] = stringToReverse[0]; 
																						
		/* Then once the new end value is reached ' \0 ', 
		the function will now return the new array to main and 
		print the new order of inputed characters. */
		
		newArray[length] = '\0';
																						
		return newArray;
	}
} 

int main(void) {
	char inStr[50];
	char* resultStr;
   
	printf("Enter the string to be reversed: ");
	fgets(inStr, 20, stdin);
	strtok(inStr, "\n");  // Remove newline character from input.
	
	resultStr = ReverseString(inStr);
	
	printf("Reversed: %s\n", resultStr);

   return 0;
}