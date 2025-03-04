#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Nicholas Huish
// Chpt 5 PA

// Define a Node structure for each element in the queue
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Define a Queue structure to represent the queue implemented as a linked list
typedef struct Queue {
    Node* front;
    Node* rear;
} Queue;

// Function to create and initialize an empty queue
Queue* createQueue() {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    if (queue == NULL) {
        printf("Memory allocation error!\n");
        exit(1);
    }
    queue->front = NULL;
    queue->rear = NULL;
    return queue;
}

// Enqueue operation: adds an item to the end of the queue, pseudocode found in PA 5.5.1
void enqueue(Queue* queue, int item) {
    // Allocate new node and assign data (newNode->next is set to NULL)
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation error!\n");
        exit(1);
    }
    newNode->data = item;
    newNode->next = NULL;
    
    if (queue->front == NULL) {
        // If the queue is empty, set front to the new node
        queue->front = newNode;
    } else {
        // Otherwise, link the new node at the end of the queue
        queue->rear->next = newNode;
    }
    // Update the rear pointer to the new node
    queue->rear = newNode;
}

// Dequeue operation: removes and returns the item from the front of the queue, pseudocode found in PA 5.5.1
int dequeue(Queue* queue) {
    if (queue->front == NULL) {
        // Return 0 if the queue is empty
        return 0;
    }
    // Save the data from the front node and move the front pointer
    Node* temp = queue->front;
    int dequeuedItem = temp->data;
    queue->front = temp->next;
    // If the queue becomes empty, update the rear pointer to NULL
    if (queue->front == NULL) {
        queue->rear = NULL;
    }
    free(temp); // free memory for the dequeued node
    return dequeuedItem;
}

// Function to check if the queue is empty
bool isEmpty(Queue* queue) {
	
	if (queue->front == NULL){
		return true; // Returns true.
	}
	return false; // Returns false.
	
	// Implement function
}

// Function to peek at the front item without removing it

// Checking to see if the queue is empty.
int peek(Queue* queue) {
    if (isEmpty(queue)){
		return -1;
	}
	
	/* If not, the function will return the value
	located at the front of the queue.*/
	return queue->front->data;
}

// Function to get the length of the queue

// Checking to make sure the queue is not empty.
int getLength(Queue* queue) {
    if (isEmpty(queue)){
		return 0;
	}
	/* The function will count the amount of values 
	in the queue, and return that total amount to 
	main. */
	int count = 0;
	
	Node* current = queue->front;
	while(current != NULL){
		count++;
		current = current->next;
	}
	return count;
}

// Function to traverse and display the queue
void displayQueue(Queue* queue) {
	
	Node* current = queue->front;
	
	/* Checking to see if the current node is empty,
	if not, the function will output that value, 
	along with other values in the queue.*/
	if (current == NULL){
		printf("NULL");
	} else {
		while (current != NULL){
			printf("%d", current->data);
			current = current->next;
			if (current != NULL){
				printf(" -> ");
			}
		}
	}
	printf("\n");
}

int main() {
    
	/* The program is creating queues using linked- 
	lists and doing other various tasks with them.*/
	Queue* queue = createQueue();
    
	// Implement the main method
	displayQueue(queue);

	// Checking to see if the queue is empty.
	if (isEmpty(queue)){
	    printf("The queue is empty.\n");
	} else {
		printf("The queue is not empty.\n");
	}

	/* Checking to see if the queue is empty 
	in order to push a value to front of the queue.*/
	if (peek(queue) == -1){
		printf("The queue is empty.\n");
	}

	/* Displaying the length of the queue, (outputting 
	the total amount of values that are in the queue).*/
	printf("The queue's length is: %d\n", getLength(queue)); 
	
	// Inserting values into the queue. 
	enqueue(queue, 1);
	enqueue(queue, 2);

	// Pushing the first number to the top of the queue at this point. 
	printf("The number on the top of the queue is: %d\n", peek(queue));
	
	enqueue(queue, 3);
	
	printf("The queue's length is: %d\n", getLength(queue));
	
	// Removing a value from the front of the queue. 
	printf("Item %d was removed from the queue.\n", dequeue(queue));
	
	printf("The number on the top of the queue is: %d\n", peek(queue));
	
	enqueue(queue, 4);
	
	// Outputting the current list of values in the queue. 
	displayQueue(queue);

	enqueue(queue, 5);
	
	// Removing another value from the queue. 
	printf("Item %d was removed from the queue.\n", dequeue(queue));
	
	enqueue(queue, 6);
	
	// Outputting the new amount of values in the queue. 
	printf("The queue's length is: %d\n", getLength(queue));
	
	displayQueue(queue);
	
	printf("Item %d was removed from the queue.\n", dequeue(queue));
	
	
	/* Checking to see if the queue is empty (at this point
	it should not be).*/
	if (isEmpty(queue)){
	    printf("The queue is empty.\n");
	} else {
		printf("The queue is not empty.\n");
	}
	
	// Removing more values from the queue. 
	printf("Item %d was removed from the queue.\n", dequeue(queue));
	
	printf("Item %d was removed from the queue.\n", dequeue(queue));
	
	// Getting the final amount of values that are in the queue. 
	printf("The queue's length is: %d\n", getLength(queue));
	
	printf("Item %d was removed from the queue.\n", dequeue(queue));
	
	printf("Item %d was removed from the queue.\n", dequeue(queue));
	
	// Final checking to see if the queue is empty, which now should be.
	if (isEmpty(queue)){
	    printf("The queue is empty.\n");
	} else {
		printf("The queue is not empty.\n");
	}

	/* Free the queue structure (all nodes should have 
	been dequeued by now). Meaning memory will be free.*/
	free(queue);
    
    return 0;
}