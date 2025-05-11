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

/* PrintALL_IDS
Returns nothing.
Prints all the available IDs
the user can choose to search with when 
they select a specific category 
(like Operating systems, hypervisors,
related software, and so forth) 
pertaining to the software products. */
void PrintALL_IDS(List* SentList){
    printf("\nAvailable ID's:");
    Node* CurrentNode = SentList->Head;
    while (CurrentNode != NULL){
        printf(" %s",CurrentNode->ID);
        CurrentNode = CurrentNode->next;
    }
     printf("\n\n");
	 return;
}

/*---Prints-Data-From-OS-Node----------
Used when the user provided ID fails
	
PrintNode_OS
Returns nothing.
Prints an alternative message
to the user when the inputed ID (for operating 
systems) fails to be found within the report files.
It is also used to help narrow down search
results when looking for specifc products 
pertaining to the operating systems. 
*/
void PrintNode_OS(Node* SentNode){
    printf("%-10s %-40s %-11s %-25s %-35s\n","ID","Name","Version","Platform","Release Date");
	// printf("Platform: %s ||",SentNode->Platform);
    
	printf("%-10s ",SentNode->ID);
    printf("%-40s ",SentNode->Name);
    printf("%-11s ",SentNode->Version);
    printf("%-25s ",SentNode->Hardware);
    printf("%-35s",SentNode->ReDate);
	
	// printf(" ID: %s ||",SentNode->ID);
    // printf(" Name: %s ||",SentNode->Name);
    // printf(" Version: %s ||",SentNode->Version);
    // printf(" Hardware: %s ||",SentNode->Hardware);
    // printf(" Release Date: %s",SentNode->ReDate);
	return;
}

/*
-----Prints-The-List-Data-Of-OS-------------------------
 
PrintALL_OS
Returns nothing.
Prints all data pertaining 
to the operating systems.
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

/*----Prints-The-Data-Of-RS-Node--------------------------

PrintNode_RS
Returns nothing.
Prints a specific portion of
data pertaining to
the related software and checks to see
if the node containing the data is empty.
It also allows the user to narrow down
the amount of information about hypervisors they
want to view.
*/
void PrintNode_RS(Node* SentNode){
    //printf("\n\n [PrintNode_RS-TechReport.c] \n\n");
    if (SentNode == NULL) {
        printf("Error: RS Node is NULL.\n");
        return;
    }
    // Printing details of the RS Node
    // printf("ID: %s || ", SentNode->ID);
    // printf("Name: %s || ", SentNode->Name);
    // printf("Version: %s || ", SentNode->Version);
    // printf("Platform: %s || ", SentNode->Platform);
    // printf("Release Date: %s\n", SentNode->ReDate);
	// printf("%-6s %-14s %-8s %-14s %-11s\n","ID","Name","Version","Platform","Release Date");
	printf("%-10s ", SentNode->ID);
    printf("%-40s ", SentNode->Name);
    printf("%-11s ", SentNode->Version);
    printf("%-20s ", SentNode->Platform);
    printf("%-20s", SentNode->ReDate);
	return;
}

/*-----Prints-The-List-Data-Of-RS-------------------------

PrintALL_RS
Returns nothing.
Prints all the data pertaining
to related software and checks
to make sure that the nodes containing
the data are not empty.
*/
void PrintALL_RS(List* SentList){
    //printf("\n\n [PrintALL_RS-TechReport.c] \n\n");
    if (SentList == NULL || SentList->Head == NULL) {
        printf("Error: List is empty or NULL.\n");
        return;
    }

    printf("\n--- RS Node Report ---\n");
	printf("%-10s %-40s %-11s %-20s %-20s\n","ID","Name","Version","Platform","Release Date");
    Node* CurrentNode = SentList->Head;

    while (CurrentNode != NULL) {
        PrintNode_RS(CurrentNode);  // Call PrintNode_RS to print each node's data.
        printf("\n");  // Print a newline between nodes.
        CurrentNode = CurrentNode->next;  // Move to the next node in the list.
    }

    printf("\n--- End of RS Node Report ---\n");
	return;
}

/*----Prints-The-Data-Of-HV-Node--------------------------

PrintNode_HV
Returns nothing.
Prints a specific portion of data
pertaining to the hypervisors, 
which also allows the user to narrow down 
search results relating to those items.
*/
void PrintNode_HV(Node* SentNode){

    //New print formatting ideas for testing.
	
	//printf("\n\n [PrintNode_HV-TechReport.c] \n\n");
	printf("%-10s %-15s %-11s %-11s\n","ID","Name","Version","Release Date");
    printf("%-12s ", SentNode->ID);
	printf("%-8s ", SentNode->Name);
    printf("%-20s ", SentNode->Version);
    printf("%-8s ", SentNode->ReDate);
    printf("Release Date: %s", SentNode->ReDate);


	// printf("ID: %s || ", SentNode->ID);
    // printf("Name: %s || ", SentNode->Name);
    // printf("Version: %s || ", SentNode->Version);
    // printf("Release Date: %s", SentNode->ReDate);
	return;
}

/*-----Prints-The-List-Data-Of-HV-------------------------

PrintALL_HV
Returns nothing.
Prints all the data pertaining 
to the hypervisors and checks to make
sure none of the nodes containing the 
data are not empty.
*/
void PrintALL_HV(List* SentList){
    //printf("\n\n [Temp] \n\n");
    printf("\n--- Hypervisor Report ---\n");
    Node* CurrentNode = SentList->Head;
    if (!CurrentNode) {
        printf("No hypervisors found in the system.\n");
        return;
    }
	printf("%-10s %-40s %-11s %-35s\n","ID","Name","Version","Release Date");
    while (CurrentNode != NULL) {
		printf("%-10s ",CurrentNode->ID);
		printf("%-40s ",CurrentNode->Name);
		printf("%-11s ",CurrentNode->Version);
		printf("%-35s",CurrentNode->ReDate);
		//PrintNode_HV(CurrentNode);
        printf("\n");
        CurrentNode = CurrentNode->next;
    }
    printf("\n--- End of Report ---\n");
	return;
}

/*----Prints-The-Data-Of-PS-Node--------------------------
 
PrintNode_PS
Returns nothing.
Prints a specic portion of data 
pertaining to the products, which also allows 
the user to narrow down search results 
relating to those items. 
*/

void PrintNode_PS(Node* SentNode){
    //printf("\n\n [PrintNode_PS-TechReport.c] \n\n");
    printf("%-10s %-19s %65s \n","ID","Name","Version");
	printf("%-10s ", SentNode->ID);
	printf("%-19s ", SentNode->Name);
    printf("%54s ", SentNode->Version);
    
	// printf("ID: %s || ", SentNode->ID);
    // printf("Version: %s || ", SentNode->Version);
    // printf("Hardware: %s || ", SentNode->Hardware);
    // printf("Release Date: %s\n", SentNode->ReDate);

    printf("\n\nSupported OS: %s\n\n", SentNode->Supported_OS[0] ? SentNode->Supported_OS : "None");
    printf("\nSupported RS: %s\n\n", SentNode->Supported_RS[0] ? SentNode->Supported_RS : "None");
    printf("\nSupported HS: %s\n\n", SentNode->Supported_HV[0] ? SentNode->Supported_HV : "None");
	return;
}

/**-----Prints-The-List-Data-Of-PS-------------------------
 
PrintALL_PS
Returns nothing.
Prints all the data pertaining
to the products and checks to 
make sure that the nodes containing 
the data are not empty. 

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
	return;
}
