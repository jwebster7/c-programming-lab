/**********************************************
* Name: Joseph Webster *
* Date: April 29, 2018*
* Assignment: Project 4 - Removing a node from a BST *
***********************************************
* This program is used for organizing user input (integers)
* into a Binary Search Tree using a user-defined data-type
* called a struct. All inserting, searching, and traversing
* is performed in the "bst.c" file, while all input/output
* is handled in the "io.c" file. 
* This program may now remove a node from the tree.
***********************************************/
#include "io.h"

/*************************************************
* Description: "Menu()" is used for printing the menu with options displayed *
* Precondition: The main method compiles and runs *
* Post condition: The returned value will be equal to a char *
**************************************************/
char Menu() {
	char input;
	printf("Enter (i)nsert, (s)earch, inorder (t)raversal, (r)remove, or (q)uit: ");
	scanf("%c", &input);
	return input;
}

/*************************************************
* Description: InsertMessage() is used for printing the insert prompt for inserting keys into the tree *
* Precondition: The Menu() method returns an 'i' char; The char 'choice' equals 'i' *
* Post condition: The returned value is a 32-bit integer *
**************************************************/
int InsertMessage() {
	int input;
	printf("Enter a number to insert: ");
	scanf("%d", &input);
	return input;
}

/*************************************************
* Description: SearchMessage() is used for displaying the 'search' prompt for searching keys in the tree *
* Precondition: The Menu() method returns an 's' char; The char 'choice' equals 's' *
* Post condition: The returned value is a 32-bit integer *
**************************************************/
int SearchMessage() {
	int input;
	printf("Enter a number to search for: ");
	scanf("%d", &input);
	return input;
}

/*************************************************
* Description: SearchOutput() displays the output from the 'Search' method searching the tree for a guessed key *
* Precondition: answer = true OR false; key = (a 32-bit int) *
* Post condition: Return void; display will print "key(value) is not in the tree" OR "key(value) is in the tree *
**************************************************/
void SearchOutput(bool answer, int key) {
	if (answer == false) {
		printf("%d is not in the tree.\n", key);
	}
	else {
		printf("%d is in the tree.\n", key);
	}
}

/*************************************************
* Description: TraversalOutput() displays the output from the "InorderTraversal" function *
* Precondition: buffer != NULL *
* Post condition: The buffers values will be printed as a string  *
**************************************************/
void TraversalOutput(char buffer[]) {
	if (strlen(buffer) == 0) {
		printf("There are no nodes to traverse or print.");
	}

	printf("%s ", buffer);
}

/*************************************************/
/****************PROJECT 4 METHODS****************/
/*************************************************/

/*************************************************
* Description: This method displays and prompts the user for the key value of a node to remove
* Precondition: user selects 'r'
* Post condition: input will be a real number
**************************************************/
int RemoveMessage() {
	int input;
	printf("Enter a number to remove from the tree: ");
	scanf("%d", &input);
	return input;
}

/*************************************************
* Description: Used for printing if the node was successfully removed
* Precondition: n/a
* Post condition: n/a
**************************************************/
void RemoveSuccessMessage() {
	printf("The node was successfully removed!!!\n");
}