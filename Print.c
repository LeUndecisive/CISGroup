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
	return; 
}

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
	
	return;
}

/**-----Prints-The-List-Data-Of-OS-------------------------
PrintAll_OS 
Returns nothing. 
Takes in a node list 
and outputs the nodes. 
*/
void PrintALL_OS(List* SentList){
   // printf("\n\n [PrintALL_OS-TechReport.c] \n\n"); [Remove or Comment this placeholders]
    Node* CurrentNode = SentList->Head;
    while (CurrentNode != NULL){
        PrintNode_OS(CurrentNode);
        printf("\n\n");
        CurrentNode =  CurrentNode->next;
    }
	return;
}

/**----Prints-The-Data-Of-RS-Node--------------------------
PrintNode_RS
Returns nothing.
Outputs all the related software
from a file.
*/
void PrintNode_RS(){

    printf("\n\n [PrintNode_RS-TechReport.c] \n\n");

	return;
}

/**-----Prints-The-List-Data-Of-RS-------------------------
PrintALL_RS
Returns nothing.
Takes in a node list and 
outputs all the related software.
*/
void PrintALL_RS(List* SentList){
    printf("\n\n [PrintALL_RS-TechReport.c] \n\n");
	// TODO 
	return;
}

/**----Prints-The-Data-Of-HV-Node--------------------------
PrintNode_HV
Returns nothing.
Outputs a node from the HV list.
*/
void PrintNode_HV(){

    printf("\n\n [PrintNode_HV-TechReport.c] \n\n");
	return;
}

/**-----Prints-The-List-Data-Of-HV-------------------------
PrintALL_HV
Returns nothing.
Outputs all the hypervisor information.
*/
void PrintALL_HV(List* SentList){
    printf("\n\n [Temp] \n\n");
	return;
}

/**----Prints-The-Data-Of-PS-Node--------------------------
    This one may not be needed as this is not an option yet
	
PrintNode_PS
Returns nothing.
Ouptuts a node from the PS list. 
*/
void PrintNode_PS(){
    printf("\n\n [PrintNode_PS-TechReport.c] \n\n");
	return;
}

/**-----Prints-The-List-Data-Of-PS-------------------------
PrintALL_PS
Returns nothing.
Outputs the list of products. 
*/
void PrintALL_PS(List* SentList){
    printf("\n\n [PrintALL_PS-TechReport.c] \n\n");
	return;
}