#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Nicholas Huish
// Chpt 3 PA

void bubbleSort(int sort_Array[], int n) { // Function sorts the array of random integers. 
	
int i; // To iterate through the array.
int j; // To keep track of what is being swapped. 
int temp; // Acts as a place holder for swapping variables. 

     for (i = 0; i < n - 1;  i++){ 
          for (j = 0; j < n - i - 1; j++){ 
               if (sort_Array[j] > sort_Array[j + 1]){ // The whole entire loop utilizes a bubble sort algorithm. 
                   temp = sort_Array[j]; 
				   sort_Array[j] = sort_Array[j + 1];
				   sort_Array[j + 1] = temp;
			   }
		  }
	 }
} 

void printArray( int sort_Array[], int size) { // Function prints the unsorted and sorted arrays. 

	int i;
	
	// Will output multiple unsorted numbers between 1 - 1000. 
	printf("Unsorted Array: \n");
	
	for (i = 0; i < size; ++i) {
		printf("%d ", sort_Array[i]);
	}
	
	printf("\n");
	
	bubbleSort(sort_Array, size); // Calling a function to sort the unsorted array. 
	
	printf("\n");
	
	printf("Sorted Array: ");
	
	printf("\n");
	
	// Going to output 25 random sorted integers between 1 and 1000.
	for (i = 0; i < size; ++i) {
		printf("%d ", sort_Array[i]);
	}
	
	printf("\n");
}

int main() {
	
	/*The program is going to generate a list of numbers
	   and then sort them in ascending order. */
	
	int Array[25];
	int currentArray;
	int i;
	int max = 1000;
	int min = 1;
	
	srand(time(0)); // Will generate a new set of numbers every time the program is run. The "0" is required.
	
	currentArray = (rand() % 1000) + 1; // Will generate a number between 1 - 1000.

	// Will now generate an array of 25 random integers ranging between 1 - 1000.
	for (i = 0; i < 25; ++i) {
		Array[i] = rand() % (max - min + 1) + min; // Need an end value since we start from index 0. 
	}
	
	// Calling a function to output a sorted and an unsorted array.
	printArray(Array, 25); 
	 
	return 0;
}