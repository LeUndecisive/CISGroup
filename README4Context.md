# CISGroup
A group repository :D


# Purpose 
    This is just an outline or plan I have thought of, simply a way to thoery craft. Nothing is final however I beleive this will help build the ship. 
    So we can get closer to setting sail with our ideas / theorys on how to build this ship.

## MissionGoal
    Creating a program to read data from a FILE.CSV.
    
    Allowing the user to select from a menu system.
    
    To search and print specific or all data from the read files data.
    
    Ending the program when desired.

    
## Expected File contents:
     The functions <sub>or</sub> manual writing will depend on how function heavy we make it.
     
     Meaning there could be manual writing or simply function calling. 	<ins>(How function heavy do you wish a section / work to be for other files)</ins>

MainFunc.H  <sub>Houses functions which can be ~~universally~~ used by other c files</sub>

    struct Node | To store data (This may change)
    struct List | To create a list OS_List, RP_List
    struct DataContext | To store all list

    initList(List* SentList) | For main to create list
    ReadStoredData(File,SentList) | For main.c to store data to list
    SearchForID(List,ID) | For Menu.c or Print.c

    PrintALL(List* SentList) | For Menu to call

    Menu(DataContext) | For Main.c to call
~~----------------------------------------------------~~
    More functions / structs can be added, depedning on the workflow.
    These functions will / should be called by other c files.

Main.C <sub>References loader.c MainFunc.H</sub>

     Create a single struct containing four list* OS,RP,HV,PS.
     
     Calling ReadStoredData to fill each list with their respective files.
     
     Sending this single struct into the CliMenu( )
     
     Once this CliMenu( ) ends should all list* Data should be cleared

Menu.C | CliMenu( ) <sub>References Print.c and loader.c MainFunc.H</sub>

     Contain a loop which will not exit until desired by the user.
     
     Allowing the user to enter numbers to match a present selection, in the form of a base case.
     
     The user should be presented with: **"Operating Systems | Related Software | HyperVisors | Products | Exit"**
     
     Selecting anything other than exit should provide| **"PrintALL,SearchID,Back"**
     
     Searching an ID should prompt the user to enter an ID
     
     If the ID (Node) is found then should its contents be printed out
     
     Prompting the useragain with the three options
     
     Otherwise they should be prompted with: **"This ID could not be found"**
     
     Displaying a list of all ID avaiable to enter
     
     Allowing the user to enter an ID once again
     
     Upon selecting back and exiting should this loop be broken.

Print.C | PrintALL( ) <sub>References loader.c MainFunc.H()</sub>

     Contains a function to PrintALL(list* Data)
     
     Contains a function to ease any repetative printing statemets

Loader.C | ReadStoreData( ) | SearchID( ) <sub>References own MainFunc.H()</sub>

     Contains functions to store read data from file in the form of a list* Data
     
     Closing the files after being stored
     
     Contains a function to search for an ID


## TASKI can go over task through communications | I will write my idea / task down later
4/25/25 - LeUndecisive - Task Assignment - Job

### LeUndecisive
   - Implement and Define the Loader.C functions
   - Create .c and .h files

### nicholashuish
   - Implement and Define the Print.c functions
   - Assisting with printing and formating within Menu.c
   - Request for functions to be made by Loader.c

### banglea669
   - Implement and Define the Menu.c functions
   - Calling Loader.c or Print.c functions
   - Request for functions to be made by Print.c or Loader.c

### Atha3-S
   - Implement the main.c lines and functions
   - Error catch Print.c, Loader.c, Menu.c, main.c and Main.h (Write error checks / escapes)
   - Test the current build

### ALL
   - Any can / may ask another member to assist or update contents which they may have made. 
   - Request changes or makes changes to code.
   - Let others do work as well :D 
    
### Suggestions
   - I recommend banglea to add our run_cli to the Menu.c (and declare it in Menu.h "void run_cli(DataContext *ctx);") The run_cli could use the "switch" function and base on the number the user inputs it will do a different type of report, which would be used to call the corisponding function from TechReport (or Print if thats what we are using for output)
