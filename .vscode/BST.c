#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
// Nicholas Huish
// Chpt7 PA

#define COUNT 10

// Definition of the BST Node
typedef struct BSTNode {
    int key;
    struct BSTNode* left;
    struct BSTNode* right;
} BSTNode;

// Function to create a new BST node
BSTNode* createNode(int key) {
    BSTNode* newNode = (BSTNode*)malloc(sizeof(BSTNode));
    newNode->key = key;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Definition of the Binary Search Tree (BST)
typedef struct BST {
    BSTNode* root;
} BST;

// Function to create an empty BST
BST* createBST() {
    BST* tree = (BST*)malloc(sizeof(BST));
    tree->root = NULL;
    return tree;
}

BSTNode* getRoot(BST* tree) {
    return tree->root;
}

// Implement the BSTSearchRecursive PseudoCode found in PA 7.9.1
BSTNode* searchRecursive(BSTNode* node, int key) {
	
	/* This function continously compares the 
	search key with the a node's current 
	key in the binary search tree, and then 
	returns either the left or right node's key or 
	a message stating that the search key does not 
	exist. */
	if (node != NULL){
		if (key == node->key){
			return node;
		}
		else if (key < node->key){
			return searchRecursive(node->left, key);
		}
		else {
			return searchRecursive(node->right, key);
		}
	}
	return NULL;
}

// Implement the BSTSearch PseudoCode found in PA 7.9.1
BSTNode* search(BST* tree, int key) {
	
	/* This function calls for the recursive 
	function to conduct searches for particular 
	keys. */
	return searchRecursive(tree->root, key);
}

// Function to check if the tree contains a node with the given key
bool contains(BST* tree, int key) {
    return search(tree, key) != NULL;
}

// Implement the BSTInsertRecursive PseudoCode found in Fig. 7.9.2
void insertRecursive(BSTNode* parent, BSTNode* nodeToInsert) {
	    
		/* This function is continously comparing the 
		insert key with the parent key of the binary
		search tree to see where in the tree that 
		new key can be placed. */
		
		if (nodeToInsert->key < parent->key){
			if (parent->left == NULL){ 
			parent->left = nodeToInsert;
			} else {
				insertRecursive(parent->left, nodeToInsert);
			}
		} else { 
			if (parent->right == NULL){
				parent->right = nodeToInsert;
			} else {
				insertRecursive(parent->right, nodeToInsert);
			}		
		}
	}

// Implement the BSTInsertNode PseudoCode found in Fig. 7.9.2
void insertNode(BST* tree, BSTNode* node) {
	
	/* The function is making sure that when
	a new node needs to be inserted, it checks 
	to see if it can be implemented where the 
	root of the tree would normally be. Other-
	wise, it would have to call another function 
	to do more comparisons to find available space.
	*/
	if (tree->root == NULL){
		tree->root = node;
	} else {
		insertRecursive(tree->root, node);
	}
}

// Function to insert a key into the BST
bool insertKey(BST* tree, int key) {
    if (contains(tree, key)) {
        return false; // Duplicate keys not allowed
    }
	// Create a new node
    BSTNode* newNode = createNode(key);
	// Call insertNode method
    insertNode(tree, newNode);
    return true;
}

// Implement a printInReverseOrder function discussed in Section 7.7 
void printInReverseOrder(BSTNode* node) {
	if (node != NULL) {
		printInReverseOrder(node->right);
		printf("%d ", node->key);
		printInReverseOrder(node->left);
	}
}

 // Function to print the binary tree in 2D using reverse inorder traversal
void print2DUtil(BSTNode* root, int space) {
    // Base case: If the node is NULL, return
    if (root == NULL) {
        return;
    }

    // Increase space for the next level
    space += COUNT;

    // First, process the right child
    print2DUtil(root->right, space);

    // Print the current node after space count
    printf("\n");
    for (int i = COUNT; i < space; i++) {
        printf(" ");
    }
    printf("%d\n", root->key);

    // Then, process the left child
    print2DUtil(root->left, space);
}

// Wrapper function to print the tree
void print2D(BSTNode* root) {
    // Start with 0 space
    print2DUtil(root, 0);
}

// Function to free memory allocated for BST nodes
void freeTree(BSTNode* root) {
    if (root == NULL) {
        return;
    }
    freeTree(root->left);
    freeTree(root->right);
    free(root);
}

// Implement the main function based on the program instructions
int main() {
    
	// Implementing keys (values) recursively. 
	int keys[] = {35,41,13,57,3,83,88,51,38,20,11,22,27,21,48,8};
	
	/* Number of elements divided by the size of each element.
	One size of an integer in C is 8 bytes. */
	int n = sizeof(keys) / sizeof(int);  
	
	BST* tree = createBST();
	
	for (int i = 0; i < n; i++){
		insertKey(tree, keys[i]);
	}
	
	// Outputting the keys in reverse order.
	printInReverseOrder(getRoot(tree));
	
	// Outputting the binary search tree in 2D.
	print2D(getRoot(tree));
	
	printf("\n");
	
	/*Searching for keys and outputting messages
	to see if they are or not found. */
	int searchKey = 27;
	if (search(tree, searchKey) != NULL){
		printf("Found node with key = %d.\n", searchKey);
	} else {
		printf("Key %d is not found.\n", searchKey);
	}
	
	printf("\n");
	
	searchKey = 89;
	if (search(tree, searchKey) != NULL){
		printf("Key %d is found. \n", searchKey);
	} else {
		printf("Key %d not found.\n", searchKey);
	}

	/*clean up memory*/
	freeTree(tree->root);
	free(tree);
    return 0;
}