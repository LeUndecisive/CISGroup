/*---Info-Box-----------
]   Fill out print function declarations (To-DO)
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
void PrintNode_RS(){

    printf("\n\n [PrintNode_RS-TechReport.c] \n\n");

};


/**-----Prints-The-List-Data-Of-RS-------------------------

*/
void PrintALL_RS(List* SentList){
    printf("\n\n [PrintALL_RS-TechReport.c] \n\n");
};



/**----Prints-The-Data-Of-HV-Node--------------------------

*/
void PrintNode_HV(){

    printf("\n\n [PrintNode_HV-TechReport.c] \n\n");

};



/**-----Prints-The-List-Data-Of-HV-------------------------

*/
void PrintALL_HV(List* SentList){
    printf("\n\n [Temp] \n\n");
};

/**----Prints-The-Data-Of-PS-Node--------------------------
    This one may not be needed as this is not an option yet
*/
void PrintNode_PS(){
    printf("\n\n [PrintNode_PS-TechReport.c] \n\n");
};





/**-----Prints-The-List-Data-Of-PS-------------------------

*/
void PrintALL_PS(List* SentList){
    printf("\n\n [PrintALL_PS-TechReport.c] \n\n");
};
