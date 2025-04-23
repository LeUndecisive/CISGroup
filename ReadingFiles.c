#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//---File-Defines-Variables--------

#define OS_FILE "FinalProjectDataOS.csv"

// A struct to store File Data
typedef struct Node{
    //All similar data
    char ID[5];
    char Name[30];
    char Version[5];
    char ReDate[12];

    // OS Hardware
    char Hardware[30];


    //next node
    struct Node* next;

} Node;

// A struct to store Nodes
typedef struct List{
    Node* Head;
    Node* Tail;

} List;

// Set list Head and Tail to NULL
void initList(List* SentList){
    SentList->Head = NULL;
    SentList->Tail = NULL;
}

// Create a new node to be used
Node* CreateNode(){
    Node* NewNode = (Node*)malloc(sizeof(Node));
    return NewNode;
}

//Prints the entire compiled list
void PrintList(List* SentList){
    printf("%s\n",SentList->Head->ID);
    printf("%s\n",SentList->Head->Name);
}

// While  search for a selected ID (Returns NULL unless Node is found)
Node* SearchForID(List* SentList,char SentID[5]){

    Node* CurrentNode = SentList->Head;

    while (CurrentNode != NULL){
        int CompareResults = strcmp(CurrentNode->ID,SentID);
        //printf("Comparing: %s %s\n", CurrentNode->ID,SentID); Test Statement
        if (CompareResults == 0){
            return CurrentNode;
        }
        CurrentNode =  CurrentNode->next;
    }
    return NULL;

}

// Assigns the list head and tail (Updates tail for new node)
void AssignListHead (List* SentList, Node* SentNode){
    if (SentList->Head == NULL){
        SentList->Head = SentNode;
        SentList->Tail = SentNode;
        SentList->Head->next = NULL;
    }else{
        SentList->Tail->next = SentNode;
        SentList->Tail = SentNode;
        SentList->Tail->next = NULL;
    }
}

// Reads from a inserted file and inserts contents into a sentlist.
void ReadStoredData(FILE* SelectedFile, List* SentList){

    //Loop until file end
    //-----Read-Line----------
    char ReadLine[100];

    while(fgets(ReadLine,sizeof(ReadLine),SelectedFile) != NULL){

    //------Create-Empty-Node---
        Node* CurrentNode = CreateNode();
        AssignListHead(SentList,CurrentNode);

    //---Seperate-Read-Data------
        char* token = strtok(ReadLine,",");
        strcpy(CurrentNode->ID,ReadLine);
        int I;

        for (I = 0; I < 4;I++){
            token = strtok(NULL,",");

           // printf("%s\n", token);
            switch(I){
                case 0:
                    strcpy(CurrentNode->Name,token);

                case 1:
                    strcpy(CurrentNode->Version,token);

                case 2:
                    strcpy(CurrentNode->Hardware,token);

                case 3:
                    strcpy(CurrentNode->ReDate,token);

            }
        }

    }

}


int main()
{

//----Get-Files---------
    FILE* SelectedFile;

    SelectedFile = fopen(OS_FILE, "r");

    if (SelectedFile != NULL){
        printf("File Found\n");
    }
    else{
        printf("File Missing\n");\
        exit(1);
    }

//-----Create-List-Entries----------
    List OS_List;
    initList(&OS_List);

//----------Read-Store-File-Data-----------------

    ReadStoredData(SelectedFile,&OS_List);

//---Search-For-ID-NODE-------
    char SearchKey[] = "OS23";
    Node* SearchResults = SearchForID(&OS_List,SearchKey);

//----Print-Node-Data------------

    if (SearchResults != NULL){
        printf("ID: %s\n",SearchResults->ID);
        printf("Name: %s\n",SearchResults->Name);
        printf("Version: %s\n",SearchResults->Version);
        printf("HardWare: %s\n",SearchResults->Hardware);
        printf("Date: %s\n",SearchResults->ReDate);
    }else{
        printf("Node with ID of: %s was not found\n",SearchKey);
    }

//----Close-Files----------------------

    fclose(SelectedFile);
    return 0;
}
