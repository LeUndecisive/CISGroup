/*Info Box
]
]   Free_Data has to be rewritten to free the new data formating (To-DO)
]
*/
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "Loader.h" // Self
#include "Main.h"   // Free_data


//----------Data-Context-Clearing------------------ 

/* free_data
Returns nothing.
Frees data in the nodes 
and in memory so all the files
can be navigated and properly
loaded. */

void free_data(DataContext *ctx) {
   
    printf("\n\n [free_data-Loader.c] \n\n");

    /* Commented out | I do apolgize for removing contents 
    if (!&ctx) return;
    
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
    
    
    */
}

//-------------File-Loading-and-Data-Handle--------------------------------------------

/* 
CreateNode
Returns a new node.
Creates a new node to be 
used for each file and any
other associated data.
*/
Node* CreateNode(){
    Node* NewNode = (Node*)malloc(sizeof(Node));
    return NewNode;
}

/* AssignListHead
Returns nothing.
Updates the tail 
for the new node.
*/ 
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
	return;
}

/* SearchForID
Returns NULL (unless Node is found).
Searches for an ID that the 
user selects within the menu like
option 1, 2, 4, 4, 5, and etc. */

Node* SearchForID(List* SentList,char SentID[5]){

    Node* CurrentNode = SentList->Head;

    while (CurrentNode != NULL){
        int CompareResults = strcmp(CurrentNode->ID,SentID);
        if (CompareResults == 0){
            return CurrentNode;
        }
        CurrentNode =  CurrentNode->next;
    }
    return NULL;

}

// Set list Head and Tail to NULL.
void initList(List* SentList){
    SentList->Head = NULL;
    SentList->Tail = NULL;
	return;
}

/*String to detect comma characters
and filter them out.*/
const char Filters[] = ",\"";


/* removeSpaces
Returns nothing.
Clears random spacing characters 
when reading in the files. */

/* Clear spaces within reading 
(Used for removing random spaces)*/
void removeSpaces(char *str) {
    int i, j = 0;
    int len = strlen(str);
    for (i = 0; i < len; i++) {
        if (str[i] != ' ') {
            str[j++] = str[i];
        }
    }
    str[j] = '\0'; // Null-terminate the modified string
	return;
}

/* removeLastChar
Returns nothing.
Removes added characters 
when sorting strings. */

void removeLastChar(char *str){
    int Length = strlen(str);
    if (Length > 1){
        str[Length - 1] = '\0';
    }
	return;
}

/*
OpenFile 
Returns an item to main.
Opens files to be read.
*/

FILE* OpenFile(const char *SentFileTxt){
   // printf("Opening: %s\n",SentFileTxt);
    FILE* OpenedFile = NULL;
    OpenedFile = fopen(SentFileTxt,"r");
    return OpenedFile;
}

/*
CloseFile 
Returns nothing.
Closes files once done being 
read. */

void CloseFile(FILE* SentFile){
   // printf("Closing File\n");
    fclose(SentFile);
	return;
}

/*
LoadAll_OS
Returns nothing.
Loads all the files relating
to the operating systems. */

void LoadAll_OS(const char *SentFileTxt, List* SentList){
    //Loop until file end.

    FILE* SentFile = OpenFile(SentFileTxt);
    //-----Read-Line----------
    char ReadLine[100];
    char Tempcategory[20];
    int Readcount = 0;

    while(fgets(ReadLine,sizeof(ReadLine),SentFile) != NULL){
    //---Seperate-Read-Data------
        char* token = strtok(ReadLine,Filters);
       // printf("%s\n",token);
    // Detect for catagories and data
        if (Readcount == 0){
            strcpy(Tempcategory,token);

        }else if (Readcount == 12){
            Tempcategory[0] = '\0';
            strcpy(Tempcategory,token);

        }else{
            //------Create-Empty-Node---
           // printf("Storing ID\n");
            Node* CurrentNode = CreateNode();
            AssignListHead(SentList,CurrentNode);
            //Fill List with data
            strcpy(CurrentNode->ID,ReadLine);
            strcpy(CurrentNode->Platform,Tempcategory);

            int I;
            //printf("Data\n");
            for (I = 0; I < 4;I++){
                token = strtok(NULL,Filters);
                //printf("Data: %s\n",token);
                switch(I){
                    case 0:
                        strcpy(CurrentNode->Name,token);
                       // printf("Stored: %s\n",CurrentNode->Name);
                    break;
                    case 1:
                        strcpy(CurrentNode->Version,token);
                         // printf("Stored: %s\n",CurrentNode->Version);
                    break;
                    case 2:
                        strcpy(CurrentNode->Hardware,token);
                         // printf("Stored: %s\n",CurrentNode->Hardware);
                    break;
                    case 3:
                        strcpy(CurrentNode->ReDate,token);
                         // printf("Stored: %s\n",CurrentNode->ReDate);
                    break;
                }
            }
        }
        //------Increase-Count-Read-Next-------
        Readcount += 1;
      // printf("ReadCount: %d\n", Readcount);
    }
    CloseFile(SentFile);
  // printf("\n---Finished-Filling-OS----\n");
  return;
}

/* LoadAll_RS
Returns nothing.
Loads all the files 
pertaining to any related
software the user may want
to search. */
void LoadAll_RS(const char *SentFileTxt, List* SentList){
    FILE* SentFile = OpenFile(SentFileTxt);

    char ReadLine[100];
    char Tempcategory[20];
    int Readcount = 0;

    while(fgets(ReadLine,sizeof(ReadLine),SentFile) != NULL){
        // Seperate string
        char* token = strtok(ReadLine,Filters);

        // Detect for catagories and data
        if (Readcount == 0){
            strcpy(Tempcategory,token);
        }else if(Readcount == 5){
            Tempcategory[0] = '\0';
            strcpy(Tempcategory,token);

        }else if (Readcount == 10){
            Tempcategory[0] = '\0';
            strcpy(Tempcategory,token);

        }else if (Readcount == 15){
            Tempcategory[0] = '\0';
            strcpy(Tempcategory,token);
        }else{ //Data found store data

           //------Create-Empty-Node---
            Node* CurrentNode = CreateNode();
            AssignListHead(SentList,CurrentNode);
            //printf("Category: %s\n",Tempcategory);
            //Store Data
            strcpy(CurrentNode->ID,ReadLine);
            strcpy(CurrentNode->Platform,Tempcategory);

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
        //------Increase-Count-Read-Next-------
        Readcount += 1;
    }
     CloseFile(SentFile);
   // printf("\n---Finished-Filling-RS----\n");
   return;
}

/* LoadAll_HV
Returns nothing.
Loads all the files relating 
to hypervisors. */
void LoadAll_HV(const char *SentFileTxt, List* SentList){
    FILE* SentFile = OpenFile(SentFileTxt);

    char ReadLine[100];

    while(fgets(ReadLine,sizeof(ReadLine),SentFile) != NULL){
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
     CloseFile(SentFile);
    //printf("\n---Finished-Filling-HS----\n");
	return;
}

/* LoadAll_PS
Returns nothing.
Loads all files pertaining
to any software 
product that the user 
may want to search. */
void LoadAll_PS(const char *SentFileTxt, List* SentList){
    FILE* SentFile = OpenFile(SentFileTxt);
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
                    strcpy(CurrentNode->Name,token);
                break;
                case 2:
                    strcpy(CurrentNode->Version,token);
                break;
            }
            token = strtok(NULL,Filters);
        }

    //----Store-Etc-Data-----------
        while (token != NULL ){
            removeSpaces(token);
            if (strlen(token) > 1 ){

                if (token[0] == 'O'){
                    strcat(CurrentNode->Supported_OS,token);
                    strcat(CurrentNode->Supported_OS,",");

                }else if(token[0] == 'S'){
                    strcat(CurrentNode->Supported_RS,token);
                    strcat(CurrentNode->Supported_RS,",");

                }else if(token[0] == 'H'){
                    strcat(CurrentNode->Supported_HV,token);
                    strcat(CurrentNode->Supported_HV,",");

                }
            }

            token = strtok(NULL,Filters);
        }
        //--Read-new-Line-Clear-commas--------
        removeLastChar(CurrentNode->Supported_OS);
        removeLastChar(CurrentNode->Supported_RS);
        removeLastChar(CurrentNode->Supported_HV);

    }
     CloseFile(SentFile);
    //printf("\n---Finished-Filling-PS----\n");
	return;
}
