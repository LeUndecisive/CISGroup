/*---Info-Box-----------
]   Fill out print function declarations (To-DO)
]   TechReport.h also need declarations
]   Organization of the print statements can be altered (Formating)
]   Please use the other filled print statements as a reference source
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Loader.h"

void PrintALL_IDS(List* SentList){
    printf("\nAvailable ID's:");
    Node* CurrentNode = SentList->Head;
    while (CurrentNode != NULL){
        printf(" %s",CurrentNode->ID);
        CurrentNode =  CurrentNode->next;
    }
     printf("\n\n");
};

/**---Prints-Data-From-OS-Node----------
    Used when the user provided ID fails
*/
void PrintNode_OS(Node* SentNode){
    printf("Platform: %s ||",SentNode->Platform);
    printf(" ID: %s ||",SentNode->ID);
    printf(" Name: %s ||",SentNode->Name);
    printf(" Version: %s ||",SentNode->Version);
    printf(" Hardware: %s ||",SentNode->Hardware);
    printf(" Release Date: %s",SentNode->ReDate);

};

/**-----Prints-The-List-Data-Of-OS-------------------------

*/
void PrintALL_OS(List* SentList){
   // printf("\n\n [PrintALL_OS-TechReport.c] \n\n"); [Remove or Comment this placeholders]
    Node* CurrentNode = SentList->Head;
    while (CurrentNode != NULL){
        PrintNode_OS(CurrentNode);
        printf("\n\n");
        CurrentNode =  CurrentNode->next;
    }
};

/**----Prints-The-Data-Of-RS-Node--------------------------

*/
void PrintNode_RS(Node* SentNode){
    //printf("\n\n [PrintNode_RS-TechReport.c] \n\n");
    if (SentNode == NULL) {
        printf("Error: RS Node is NULL.\n");
        return;
    }
    // Printing details of the RS Node
    printf("ID: %s || ", SentNode->ID);
    printf("Name: %s || ", SentNode->Name);
    printf("Version: %s || ", SentNode->Version);
    printf("Platform: %s || ", SentNode->Platform);
    printf("Release Date: %s\n", SentNode->ReDate);
};


/**-----Prints-The-List-Data-Of-RS-------------------------

*/
void PrintALL_RS(List* SentList){
    //printf("\n\n [PrintALL_RS-TechReport.c] \n\n");
    if (SentList == NULL || SentList->Head == NULL) {
        printf("Error: List is empty or NULL.\n");
        return;
    }

    printf("\n--- RS Node Report ---\n");
    Node* CurrentNode = SentList->Head;

    while (CurrentNode != NULL) {
        PrintNode_RS(CurrentNode);  // Call PrintNode_RS to print each node's data
        printf("\n");  // Print a newline between nodes
        CurrentNode = CurrentNode->next;  // Move to the next node in the list
    }

    printf("\n--- End of RS Node Report ---\n");
};



/**----Prints-The-Data-Of-HV-Node--------------------------

*/
void PrintNode_HV(Node* SentNode){

    //printf("\n\n [PrintNode_HV-TechReport.c] \n\n");
    printf("ID: %s || ", SentNode->ID);
    printf("Name: %s || ", SentNode->Name);
    printf("Version: %s || ", SentNode->Version);
    printf("Release Date: %s", SentNode->ReDate);
};



/**-----Prints-The-List-Data-Of-HV-------------------------

*/
void PrintALL_HV(List* SentList){
    //printf("\n\n [Temp] \n\n");
    printf("\n--- Hypervisor Report ---\n");
    Node* CurrentNode = SentList->Head;
    if (!CurrentNode) {
        printf("No hypervisors found in the system.\n");
        return;
    }

    while (CurrentNode != NULL) {
        PrintNode_HV(CurrentNode);
        printf("\n");
        CurrentNode = CurrentNode->next;
    }
    printf("\n--- End of Report ---\n");
};

/**----Prints-The-Data-Of-PS-Node--------------------------
 * 
*/
void PrintNode_PS(Node* SentNode){
    //printf("\n\n [PrintNode_PS-TechReport.c] \n\n");
    printf("ID: %s || ", SentNode->ID);
    printf("Version: %s || ", SentNode->Version);
    printf("Hardware: %s || ", SentNode->Hardware);
    printf("Release Date: %s\n", SentNode->ReDate);

    printf("  Supported OS: %s\n", SentNode->Supported_OS[0] ? SentNode->Supported_OS : "None");
    printf("  Supported RS: %s\n", SentNode->Supported_RS[0] ? SentNode->Supported_RS : "None");
    printf("  Supported HS: %s\n", SentNode->Supported_HV[0] ? SentNode->Supported_HV : "None");
};





/**-----Prints-The-List-Data-Of-PS-------------------------

*/
void PrintALL_PS(List* SentList){
    //printf("\n\n [PrintALL_PS-TechReport.c] \n\n");
    printf("\n--- Product Report ---\n");
    Node* CurrentNode = SentList->Head;

    if (!CurrentNode) {
        printf("No products found in the system.\n");
        return;
    }

    while (CurrentNode != NULL) {
        PrintNode_PS(CurrentNode);
        printf("\n");
        CurrentNode = CurrentNode->next;
    }

    printf("--- End of Product Report ---\n");
};
