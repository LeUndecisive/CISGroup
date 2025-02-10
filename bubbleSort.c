#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Nicholas Huish
// Chpt 3 PA

void bubbleSort(int sort_Array[], int n) { // Function sorts the array of random integers. 
	
int num_numbers = 25;	
int Array[num_numbers]; 
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

void printArray( int  sort_Array[], int size) {

	int i; // Iterate through array of integers. 

	for (i = 0; i < size; ++i) {
		
		// Going to output 25 random sorted integers between 1 and 1000.
		printf("%d ", sort_Array[i]);
	}
}

int main() {
	
	/*The program is going to generate a list of numbers
	   and then sort them in ascending order. */
	
	int currentArray;
	int num_numbers = 25; // Program can generate 25 total numbers. 
	int min = 1;
	int max = 1000;
	int i;
	int Array[num_numbers]; 
	int size = sizeof(Array) / sizeof(Array[0]); // Need to indicate the real size of the array. 
	
	srand(time(0)); // Will generate a new set of numbers every time the program is run. The "0" is required.
	
	currentArray = (rand() % 1000) + 1; // Will generate a number between 1 - 1000.
	
	printf("Unsorted Array: \n");
	
	// Will output multiple unsorted numbers between 1 - 1000. 
	for (i = 0; i < num_numbers; ++i) {
		Array[i] = rand() % (max - min + 1) + min; // Need an end value since we start from index 0. 
		printf("%d ", Array[i]);
	}
	
	printf("\n");
	
	bubbleSort(Array, size); // Calling in a sorting algorithm. 
	
	printf("\n");
	
	printf("Sorted Array: ");
	
	printf("\n");
	
	printArray(Array, size);

	return 0;
}

// Steps to implement bubble sort:

    /* In first cycle,
        Start by comparing 1st and 2nd element and swap if 1st element is greater.
        After that do the same for 2nd and 3rd element.
        At the end of cycle you will get max element at the end of list.
    Now do the same in all subsequent cycles.
    Perform this for (number of elements – 1) times.
    You will get sorted list. */