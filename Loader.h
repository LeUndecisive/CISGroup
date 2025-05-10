#ifndef LOADER_H
#define LOADER_H

//Removed the Main.h include

/** A node which stores data
  Yes the nodes can store all data, however a data will not be filled if it does not have said data.
  For example no other data types (RS,HS,PS) has a hardware data type.
  Meaning if one were to print said RS->Hardware the result will be null.
  Attempting to print out the Supported_Name will print the entire string of that data. (OS1,OS2,OS3,etc)
  I can create or assist with seperating this if desired. (You can reference the strtok(String,",")
*/
typedef struct Node{

    // These data types are used by OS,RS,HV | ID Name Version ReDate.
    char ID[6];
    char Name[30];
    char Version[20];
    char ReDate[20];
    // OS and RS Exclusive | Platform.
    char Platform[20];
    // OS Exclusive | Hardware
    char Hardware[20];
    // PS exclusive | Supported_OS Supported_RS Supported_HS.
    char Supported_OS[100];
    char Supported_RS[100];
    char Supported_HV[100];
    // Used to access the next data node if not NULL.
    struct Node* next;

} Node;

/* A list is created to store nodes 
(file folders) filled with data and 
it is also used within the SearchForID
function. The list will be stored 
within a larger struct. */
typedef struct List{
    Node* Head;
    Node* Tail;
} List;

//-----Loader-Functions-inner-working-------------

/* SearchForID
Returns nothing.
Receives a declared list and declared 
ID returning a node | 
SearchResults = SearchForID(&PS_List,"SearchKey");
It is used to retrieve a specific node from a list.
*/
Node* SearchForID(List* SentList,char SentID[6]);

/*
initLIst
Returns nothing.
Used to create a 
list |  List PS_List; > initList(&PS_List);
This should be used 
to initalize a list for usage.
*/
void initList(List* SentList);

//----Loader-Functions-outer-working-----------------------------

/*
LoadAll_OS, RS, HV, PS
Return nothing.
Fills a SentList with thes 
SentFile contents | LoadAll_PS(FILE_PS,&PS_List);
*/
void LoadAll_OS(const char *SentFileTxt, List* SentList);

void LoadAll_RS(const char *SentFileTxt, List* SentList);

void LoadAll_HV(const char *SentFileTxt, List* SentList);

void LoadAll_PS(const char *SentFileTxt, List* SentList);


#endif // LOADER_H
