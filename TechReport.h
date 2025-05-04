#ifndef TECHREPORT_H
#define TECHREPORT_H
#include "Loader.h"
#include "Main.h"  // Include the main header for structures

// Function declarations for reporting

/**-----Prints-All-IDS-In-List------------
    Used when the user provided ID fails
*/
void PrintALL_IDS(List* SentList);

/**---Prints-Data-From-OS-Node----------
    Used when the user provided ID fails
*/
void PrintNode_OS(Node* SentNode);

/**------------------------------------

*/
void PrintNode_RS();

/**------------------------------------

*/
void PrintNode_HV();

/**------------------------------------

*/
void PrintNode_PS();

/**------------------------------------

*/
void PrintALL_OS(List* SentList);

/**------------------------------------

*/
void PrintALL_RS(List* SentList);

/**------------------------------------

*/
void PrintALL_HV(List* SentList);

/**------------------------------------

*/
void PrintALL_PS(List* SentList);

#endif // TECHREPORT_H
