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

 Contains functions which will be called by: Main.c Menu.c Print.C Loader.C
 These functions should be main functions which require background work.
 **PrintALL, SearchID, ReadStoredData, CliMenu**
 A function which can do all (Hiding manual writing)

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
 However I do have them written down somewhere however this is simply an overall outline

