#ifndef MAIN_H
#define MAIN_H

#include <stddef.h>

// Define the Node struct
typedef struct Node {
    char ID[6];         // Unique identifier for the node
    char Name[100];     // Name associated with the node
    char Version[10];   // Version info
    char ReDate[10];    // Release date
    char Hardware[100]; // Hardware type
    struct Node* next;  // Pointer to the next node in the list
} Node;

// Define the List struct
typedef struct List {
    Node* Head;        // Pointer to the head (first node)
    Node* Tail;        // Pointer to the tail (last node)
} List;

// Define the OperatingSystem struct
typedef struct {
    char id[6];         // Unique identifier for OS
    char name[100];     // Name of the OS
    char platform[50];  // Platform of the OS (e.g., Windows, Linux, etc.)
} OperatingSystem;

// Define the Software struct
typedef struct {
    char id[6];         // Unique identifier for Software
    char name[100];     // Name of the Software
    char category[50];  // Category of the Software (e.g., utility, application)
} Software;

// Define the Hypervisor struct
typedef struct {
    char id[6];         // Unique identifier for Hypervisor
    char name[100];     // Name of the Hypervisor
} Hypervisor;

// Define the Product struct
typedef struct {
    char id[6];         // Unique identifier for Product
    char name[100];     // Name of the Product
    char **os_names;    // Array of supported OS names for the product
    int os_count;       // Number of supported OS
    char **sw_names;    // Array of supported Software names
    int sw_count;       // Number of supported Software
    char **hyper_names; // Array of supported Hypervisors for the product
    int hyper_count;    // Number of supported Hypervisors
} Product;

// Define DataContext to hold all lists of data
typedef struct {
    OperatingSystem *oses;    /**< Array of OperatingSystem entries */
    size_t os_count;          /**< Number of OperatingSystem entries */
    Software *softs;          /**< Array of Software entries */
    size_t sw_count;          /**< Number of Software entries */
    Hypervisor *hvs;          /**< Array of Hypervisor entries */
    size_t hv_count;          /**< Number of Hypervisor entries */
    Product *prods;           /**< Array of Product entries */
    size_t prod_count;        /**< Number of Product entries */
} DataContext;

// Function declarations
void free_data(DataContext *ctx);
void initList(List* SentList);
Node* SearchForID(List* SentList, char SentID[5]);
void ReadStoredData(FILE* SelectedFile, List* SentList);

#endif // MAIN_H
