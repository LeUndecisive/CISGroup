#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// Nicholas Huish
// Chpt6 PA

// Define structure to represent the key-value pair (Item)
typedef struct Item {
    char *key;  
    char *value;  
    struct Item *next;  
} Item;

// Define structure to represent the hash table
typedef struct HashTable {
    Item **hashTable;  
    int length;  
} HashTable;

// Function to create a new Item (key-value pair)
Item* createItem(char *key, char *value) {
    Item *newItem = (Item*)malloc(sizeof(Item));  
    newItem->key = strdup(key);  
    newItem->value = strdup(value);  
    newItem->next = NULL;  
    return newItem;
}

// Function to create a new hash table with a specified number of buckets
HashTable* createHashTable(int size) {
    HashTable *table = (HashTable*)malloc(sizeof(HashTable));  
    table->length = size;  
    table->hashTable = (Item**)malloc(sizeof(Item*) * size);  

    for (int i = 0; i < size; i++) {
        table->hashTable[i] = NULL;  
    }
    return table;
}

// Hash function to compute the index for a given key
int hash(char *key) {
	// Implement the function based on the PseudoCode provided in Figure 6.8.3, with 1 modification:
	// DO NOT mod(%) the stringHash by the number of buckets.
	
	/* Essentially, the function is returning a hash
	everytime it finds a string character in each key. */
	
	int InitialValue = 0;
	int stringHash = InitialValue;
	int HashMultiplier = 13;
	int i;
	
	for (i = 0; i < strlen(key); i++){
		stringHash = (stringHash * HashMultiplier) + key[i];
	}
	
	return stringHash;
    
}

// Function to insert a key-value pair into the hash table, pseudocode found in Figure 6.3.1
int hashInsert(HashTable *table, char *key, char *value) {
    int bucketIndex = hash(key) % table->length;
   
    Item *currentItem = table->hashTable[bucketIndex];
    Item *previousItem = NULL;

    while (currentItem != NULL) {
        if (strcmp(currentItem->key, key) == 0) {
            free(currentItem->value);
            currentItem->value = strdup(value);
            return 1;
        }
        previousItem = currentItem;
        currentItem = currentItem->next;
    }

    Item *newItem = (Item *)malloc(sizeof(Item));
    newItem->key = strdup(key);
    newItem->value = strdup(value);
    newItem->next = NULL;

    if (table->hashTable[bucketIndex] == NULL) {
        table->hashTable[bucketIndex] = newItem;
    } else {
        previousItem->next = newItem;
    }
    return 1;  
}

// Function to search for the specified key and return the corresponding value, pseudocode found in Figure 6.3.1
char *hashGet(HashTable *table, char *key) {
    int bucketIndex = hash(key) % table->length;
    

    Item *item = table->hashTable[bucketIndex];

    while (item != NULL) {
        if (strcmp(item->key, key) == 0) {
            return item->value;
        }
        item = item->next;
    }
    return NULL;
}

// Function to remove the key-value pair from the hash table, pseudocode found in Figure 6.3.1 
int hashRemove(HashTable *table, char *key) {
    int bucketIndex = hash(key) % table->length;
    
    Item *currentItem = table->hashTable[bucketIndex];
    Item *previousItem = NULL;

    while (currentItem != NULL) {
        if (strcmp(currentItem->key, key) == 0) {
            if (previousItem == NULL) {
                table->hashTable[bucketIndex] = currentItem->next;
            } else {
                previousItem->next = currentItem->next;
            }
            free(currentItem->key);
            free(currentItem->value);
            free(currentItem);
            return 1;
        }
        previousItem = currentItem;
        currentItem = currentItem->next;
    }
    return 0;
}

// Function to print the contents of the hash table
// Update the function to display the hash for each key-value pair
void printTable(HashTable *table) {
    for (int i = 0; i < table->length; i++) {  
        printf("Bucket %d: ", i);  
        Item *currentItem = table->hashTable[i];  
        if (currentItem == NULL) {  
            printf("empty\n");  
        } else {
            while (currentItem != NULL) {  
				printf( "[Hash is: %d, key is: %s, value is: %s] ", 
					hash(currentItem->key),
					currentItem->key, 
					currentItem->value
				);  
                currentItem = currentItem->next;  
            }
            printf("\n");  
        }
    }
}

// Main function to test the hash table
// Implement the main function per the assignment instructions
int main() {
    // Create a hash table with 5 buckets
    HashTable *table = createHashTable(5);
	
	printf("HashTable contents: \n");
	
	/* The program is inserting values along 
	with their associated keys into the hashtable.*/
	hashInsert(table, "keyA1", "value1");
	hashInsert(table, "keyB2", "value2");
	hashInsert(table, "keyC3", "value3");
	hashInsert(table, "keyD23", "value23");
	hashInsert(table, "keyE45", "value45");
	hashInsert(table, "keyF52", "value52");
		
	printTable(table);
	
	printf("\n");
	
	/* Program is calling a function 
	to remove a key from the 
	hashtable and it is 
	checking to see if it was 
	done successfully. */
	
	if (hashRemove(table, "keyF52") == 1){
		printf("keyF52 was removed \n");
	} else {
		printf("keyF52 was not found.");
	}
	
	printf("\n");
	
	/* The program will call a function
	to search and retrieve a specific key 
	along with its value if it exists. */
	
	if (hashGet(table, "keyZ6") == NULL){
		printf("keyZ6 was not found \n");
	} else {
		printf("keyZ6 was found \n");
	}
	
	printf("\n");
	
	/* The program will call in a function
	to search and output a key that currently 
	exists in the hashtable. */
	
	char* ptr = hashGet(table, "keyC3");
	
	if (ptr != NULL){
		printf("%s\n", ptr);
	} else {
		printf("keyC3 was not found.");
	}
	
	printf("\n");
	
	/* The program will output the final
	results after conducting additional 
	tasks including more inserts, 
	removals, and updates. */
	
	printf("HashTable contents after additional inserts, removal, and update: \n");
	
	hashInsert(table, "keyG18", "value18");
	hashInsert(table, "keyH7", "value7");
	hashInsert(table, "keyI33", "value33");
	hashInsert(table, "keyD23", "newvalue23"); // Updated KeyD23's value.
	
	printTable(table);
	
	// Freeing memory for the hashtable after completing tasks. 
    for (int i = 0; i < table->length; i++) {
        Item *currentItem = table->hashTable[i];
        while (currentItem != NULL) {
            Item *temp = currentItem;
            currentItem = currentItem->next;
            free(temp->value);
            free(temp);
        }
    }

    free(table->hashTable);  
    free(table);  
    return 0;
}