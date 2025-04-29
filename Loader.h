#ifndef LOADER_H
#define LOADER_H
// LeUndecisive edited Please use history to check for older code or changes.
#include <stdio.h>
#include "Main.h"  /** Include the main header to use structures
This is a temp include and may not be used in final. (Depends on discussions)
*/

// A Node which simply can store all data
typedef struct Node{

    // These data types are used by all | ID Name Version ReDate
    char ID[6];
    char Name[30];
    char Version[20];
    char ReDate[20];
    // OS Exclusive | Hardware
    char Hardware[20];
    // PS exclusive | Supported_OS Supported_RS Supported_HS
    char Supported_OS[100];
    char Supported_RS[100];
    char Supported_HS[100];
    // Used to access the next data node if not NULL
    struct Node* next;

} Node;

// A list to store nodes
typedef struct List{
    Node* Head;
    Node* Tail;

} List;

//-----Loader-Functions-inner-working-------------

/** Receives a declared list and declared ID returning a node | SearchResults = SearchForID(&PS_List,"SearchKey");
    This should be used to retrieve a specific node from a list
*/
Node* SearchForID(List* SentList,char SentID[6]);

/** Used to create a list |  List PS_List; >  initList(&PS_List);
    This should be used to initalize a list for usage
*/
void initList(List* SentList);

//----Loader-Functions-outer-working-----------------------------

/** Fills a SentList with a SentFile contents |  LoadAll_PS(FILE_PS,&PS_List);
    As of now they do not read the word seperation of files only the data (so when testing you may have to remove the words, LINUX WINDOWS ETC)
    I can provide the file i used for testing
    I will work on making the program read the RAW file instead of a slightly edited version if needed (Wait till TUE)
*/
void LoadAll_OS(FILE* SentFile, List* SentList);

void LoadAll_RS(FILE* SentFile, List* SentList);

void LoadAll_HS(FILE* SentFile, List* SentList);

void LoadAll_PS(FILE* SentFile, List* SentList);


#endif // LOADER_H

