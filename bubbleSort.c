#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Nicholas Huish
// Chpt 3 PA

void bubbleSort(int sort_Array[], int n) { // Function sorts the array of random integers. 
	
int num_numbers = 25;	
int numbers[num_numbers]; 
int i; // to iterate through the array.
int j; // to keep track of what is being swapped. 
int temp; // Acts as a place holder for swapping variables. 

// bubbleSort(num_numbers, 25);

     for (i = 0; i < n - 1;  i++){
          for (j = 0; j < n - i - 1; j++){
               if (sort_Array[j] > sort_Array[j + 1]){
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
		
		// Going to output 25 random integers between 1 and 1000.
		printf("%d ", sort_Array[i]);
	
	}
}

int main() {

	// Call the bubblesort, printArray, and rstArray functions. 
	
	// Numbers = ranNumbers(*minElement, *maxElement);
	
	int currentArray;
	int num_numbers = 25; 
	int min = 1;
	int max = 1000;
	int i;
	int numbers[num_numbers];
	int size = sizeof(numbers) / sizeof(numbers[0]);
	
	srand(time(0)); // Will generate a different number every time the program is run.  The "0" is required.
	
	currentArray = (rand() % 1000) + 1; // Will generate a number between 1 - 1000.
	
	// printf("currentArray: %d\n", currentArray);
	
	for (i = 0; i < num_numbers; ++i) {
		numbers[i] = rand() % (max - min + 1) + min;
		printf("%d ", numbers[i]);
	}
	
	// printf("\n");
	
	printf("Unsorted Array: \n");
	
	bubbleSort(numbers, size);
	
	printf("Sorted Array: \n");
	
	printArray(numbers, size);
	
	// rstArray = printArray(*Values);

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