#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Loader.h"
#include "Main.h"  // if you need access to structures like DataContext
/** Edited by LeUndecisive
    Make sure to check the history or hit me up with any questions (History shows who changed or edit files)
    This can included changes or suggestions
    I am free to discuss even through text 
    You can remove this edited by im just writting it for others to see who 
*/

//----------Data-Context-Clearing------------------ < Free data may have to be changed to match the storing of data
void free_data(DataContext *ctx) {
    if (!ctx) return;

    // Free OperatingSystem entries
    for (size_t i = 0; i < ctx->os_count; i++) {
        // Assuming loader strdup'd id, name, platform
        free(ctx->oses[i].id);
        free(ctx->oses[i].name);
        free(ctx->oses[i].platform);
    }
    free(ctx->oses);

    // Free Software entries
    for (size_t i = 0; i < ctx->sw_count; i++) {
        // Assuming loader strdup'd id, name, category
        free(ctx->softs[i].id);
        free(ctx->softs[i].name);
        free(ctx->softs[i].category);
    }
    free(ctx->softs);

    // Free Hypervisor entries
    for (size_t i = 0; i < ctx->hv_count; i++) {
        // Assuming loader strdup'd id and name
        free(ctx->hvs[i].id);
        free(ctx->hvs[i].name);
    }
    free(ctx->hvs);

    // Free Product entries
    for (size_t i = 0; i < ctx->prod_count; i++) {
        // Assuming loader strdup'd id, name, and other strings
        free(ctx->prods[i].id);
        free(ctx->prods[i].name);
        // free any other strdup'd fields here
    }
    free(ctx->prods);

    // Optionally: zero out counts
    ctx->os_count   = 0;
    ctx->sw_count   = 0;
    ctx->hv_count   = 0;
    ctx->prod_count = 0;
}

//-------------File-Loading-and-Data-Handle--------------------------------------------

// Create a new node to be used
Node* CreateNode(){
    Node* NewNode = (Node*)malloc(sizeof(Node));
    return NewNode;
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

// While search for a selected ID (Returns NULL unless Node is found)
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

// Set list Head and Tail to NULL
void initList(List* SentList){
    SentList->Head = NULL;
    SentList->Tail = NULL;
}

// Strings to detect when filtering data (sorting)
 const char Filters[] = ",\"";

// Clear spaces within reading (Used for removing random spaces)
void removeSpaces(char *str) {
    int i, j = 0;
    int len = strlen(str);
    for (i = 0; i < len; i++) {
        if (str[i] != ' ') {
            str[j++] = str[i];
        }
    }
    str[j] = '\0'; // Null-terminate the modified string
}

// Clear last item from string (Used for clearing added characters when storing string)
void removeLastChar(char *str){
    int Length = strlen(str);
    if (Length > 1){
        str[Length - 1] = '\0';
    }

}

/** Load functions for specific files (Storing in the form of a linked list)
        These functions should be used for loading data into a created list
*/

void LoadAll_OS(FILE* SentFile, List* SentList){
    //Loop until file end
    //-----Read-Line----------
    char ReadLine[100];

    while(fgets(ReadLine,sizeof(ReadLine),SentFile) != NULL){
       // removeSpaces(ReadLine);
    //------Create-Empty-Node---
        Node* CurrentNode = CreateNode();
        AssignListHead(SentList,CurrentNode);

    //---Seperate-Read-Data------
        char* token = strtok(ReadLine,Filters);
        strcpy(CurrentNode->ID,ReadLine);
        int I;

        for (I = 0; I < 4;I++){
            token = strtok(NULL,Filters);

           // printf("%s\n", token);
            switch(I){
                case 0:
                    strcpy(CurrentNode->Name,token);
                break;
                case 1:
                    strcpy(CurrentNode->Version,token);
                break;
                case 2:
                    strcpy(CurrentNode->Hardware,token);
                break;
                case 3:
                    strcpy(CurrentNode->ReDate,token);
                break;
            }
        }

    }
    printf("\n---Finished Filling-OS----\n");
};

void LoadAll_RS(FILE* SentFile, List* SentList){
    char ReadLine[100];

    while(fgets(ReadLine,sizeof(ReadLine),SentFile) != NULL){
        // removeSpaces(ReadLine);
        //------Create-Empty-Node---
        Node* CurrentNode = CreateNode();
        AssignListHead(SentList,CurrentNode);

        //---Seperate-Read-Data------
        char* token = strtok(ReadLine,Filters);
        strcpy(CurrentNode->ID,ReadLine);

        int I;

        for(I = 0; I < 3; I++){
         token = strtok(NULL,Filters);\
         switch(I) {
            case 0:
                strcpy(CurrentNode->Name,token);
            break;
            case 1:
                strcpy(CurrentNode->Version,token);
            break;
            case 2:
                strcpy(CurrentNode->ReDate,token);
            break;
         }
        }

    }
    printf("\n---Finished-Filling-RS----\n");
};

void LoadAll_HS(FILE* SentFile, List* SentList){
    char ReadLine[100];

    while(fgets(ReadLine,sizeof(ReadLine),SentFile) != NULL){
       // removeSpaces(ReadLine);
    //------Create-Empty-Node---
        Node* CurrentNode = CreateNode();
        AssignListHead(SentList,CurrentNode);

    //---Seperate-Read-Data------
        char* token = strtok(ReadLine,Filters);
        strcpy(CurrentNode->ID,ReadLine);

        int I;

        for(I = 0; I < 3; I++){
             token = strtok(NULL,Filters);
             switch(I) {
                case 0:
                    strcpy(CurrentNode->Name,token);
                break;
                case 1:
                    strcpy(CurrentNode->Version,token);
                break;
                case 2:
                    strcpy(CurrentNode->ReDate,token);
                break;
             }
        }

}
    printf("\n---Finished Filling-HS----\n");
};

void LoadAll_PS(FILE* SentFile, List* SentList){

    char ReadLine[1000];

    while(fgets(ReadLine,sizeof(ReadLine),SentFile) != NULL){

    //------Create-Empty-Node---
        Node* CurrentNode = CreateNode();
        AssignListHead(SentList,CurrentNode);
    //-------Store-first-three--------------

        int I;
        char* token = strtok(ReadLine,Filters);

        for (I = 0; I < 3; I++){
            switch(I){
                case 0:
                    strcpy(CurrentNode->ID,token);
                break;
                case 1:
                    strcpy(CurrentNode->Version,token);
                break;
                case 2:
                    strcpy(CurrentNode->Hardware,token);
                break;
                case 3:
                    strcpy(CurrentNode->ReDate,token);
                break;
            }
            token = strtok(NULL,Filters);
        }

    //----Store-Etc-Data-----------


        while (token != NULL ){
            removeSpaces(token);
            if (strlen(token) > 1 ){

            /** Print statement test

                printf("TOKEN:%s",token);
                printf("> Length:%d",strlen(token));
                printf("> Comparing:%c\n",token[0]);

            */

                if (token[0] == 'O'){

                    strcat(CurrentNode->Supported_OS,token);
                    strcat(CurrentNode->Supported_OS,",");
                   // printf("Stored %s\n",&CurrentNode->Supported_OS[CurrentNode->OS_Count -1]);

                }else if(token[0] == 'S'){
                    strcat(CurrentNode->Supported_RS,token);
                    strcat(CurrentNode->Supported_RS,",");
                   // printf("Stored %s\n",&CurrentNode->Supported_RS[CurrentNode->RS_Count -1]);
                }else if(token[0] == 'H'){
                    strcat(CurrentNode->Supported_HS,token);
                    strcat(CurrentNode->Supported_HS,",");
                  //  printf("Stored %s\n",&CurrentNode->Supported_HS[CurrentNode->HS_Count -1]);
                }else{
                    printf("\n\n ERROR \n\n");
                }

            }

            token = strtok(NULL,Filters);
        }
        //--Read-new-Line-Clear-commas--------
        removeLastChar(CurrentNode->Supported_OS);
        removeLastChar(CurrentNode->Supported_RS);
        removeLastChar(CurrentNode->Supported_HS);

    }
    printf("\n---Finished-Filling-PS----\n");
};

