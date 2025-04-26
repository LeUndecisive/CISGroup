#ifndef MAIN_H
#define MAIN_H

#include <stddef.h>

// Structure definitions
typedef struct Node {
    char ID[6];
    char Name[100];
    char Version[10];
    char ReDate[10];
    char Hardware[100];
    struct Node* next;
} Node;

typedef struct List {
    Node* Head;
    Node* Tail;
} List;

typedef struct {
    OperatingSystem *oses;
    size_t os_count;
    Software *softs;
    size_t sw_count;
    Hypervisor *hvs;
    size_t hv_count;
    Product *prods;
    size_t prod_count;
} DataContext;

// Function declarations
void free_data(DataContext *ctx);
void initList(List* SentList);
Node* SearchForID(List* SentList, char SentID[5]);
void ReadStoredData(FILE* SelectedFile, List* SentList);

#endif // MAIN_H
