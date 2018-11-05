/**********************************************
* Name: Joseph Webster *
* Date: February 25th, 2017*
* Assignment: Project 2 - Sequence and Order validation *
***********************************************
* This program is used for organizing user input (integers)
* into a Binary Search Tree using a user-defined data-type
* called a struct. All inserting, searching, and traversing
* is performed in the "bst.c" file, while all input/output
* is handled in the "io.c" file.
***********************************************/
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

/*************************************************
* Description: "Menu()" is used for printing the menu with options displayed *
* Precondition: The main method compiles and runs *
* Post condition: The returned value will be equal to a char *
**************************************************/
char Menu();

/*************************************************
* Description: InsertMessage() is used for printing the insert prompt for inserting keys into the tree *
* Precondition: The Menu() method returns an 'i' char; The char 'choice' equals 'i' *
* Post condition: The returned value is a 32-bit integer *
**************************************************/
int InsertMessage();

/*************************************************
* Description: SearchMessage() is used for displaying the 'search' prompt for searching keys in the tree *
* Precondition: The Menu() method returns an 's' char; The char 'choice' equals 's' *
* Post condition: The returned value is a 32-bit integer *
**************************************************/
int SearchMessage();

/*************************************************
* Description: SearchOutput() displays the output from the 'Search' method searching the tree for a guessed key *
* Precondition: answer = true OR false; key = (a 32-bit int) *
* Post condition: Return void; display will print "key(value) is not in the tree" OR "key(value) is in the tree *
**************************************************/
void SearchOutput(bool, int);

/*************************************************
* Description: TraversalOutput() displays the output from the "InorderTraversal" function *
* Precondition: buffer != NULL *
* Post condition: The buffers values will be printed as a string  *
**************************************************/
void TraversalOutput(char[]);