#include "Loader.h"
#include "Main.h"  // if you need access to structures like DataContext
#include <stdlib.h>
#include <stdio.h>

//----------Data-Context-Clearing------------------
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

// Reads from a inserted file and inserts contents into a sentlist.
void ReadStoredData(FILE* SelectedFile, List* SentList){
    //Loop until file end
    //-----Read-Line----------
    char ReadLine[100];

    while(fgets(ReadLine,sizeof(ReadLine),SelectedFile) != NULL){
        printf("Full Line: %s\n",ReadLine);
    //------Create-Empty-Node---
        Node* CurrentNode = CreateNode();
        AssignListHead(SentList,CurrentNode);

    //---Seperate-Read-Data------
        char* token = strtok(ReadLine,",");
        strcpy(CurrentNode->ID,ReadLine);
        printf("ID: %s\n",token);
        int I;

        for (I = 0; I < 4;I++){
            token = strtok(NULL,",");

           // printf("%s\n", token);
            switch(I){
                case 0:
                    strcpy(CurrentNode->Name,token);
                    printf("Name: %s\n",CurrentNode->Name);
                     break;
                case 1:
                    strcpy(CurrentNode->Version,token);
                    printf("Version: %s\n",CurrentNode->Version);
                    break;
                case 2:
                    strcpy(CurrentNode->Hardware,token);
                    printf("Hardware: %s\n",CurrentNode->Hardware);
                    break;
                case 3:
                    strcpy(CurrentNode->ReDate,token);
                    printf("ReDate: %s\n",CurrentNode->ReDate);
                    break;

            }
        }

    }
    printf("\nFinished Filling\n\n");
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

// Set list Head and Tail to NULL
void initList(List* SentList){
    SentList->Head = NULL;
    SentList->Tail = NULL;
}
