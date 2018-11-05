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
#include "bst.h"
#include <stdlib.h>
#pragma error(disable : 4996)
#pragma warning(disable : 4996)

/*************************************************
* Description: Main is responsible for the execution of the program;
Main calls methods in "bst.h" and "io.h" in order to
construct a tree using Nodes (BinaryTreeNodes) as well
as User input "key's" *
* Precondition: The program compiles correctly;
The files containing the methods called are in the
same directory as this C-file;
Enough room is availabe to allocate memory to Nodes
and pointers used throughout the program *
* Post condition: The post condition is that the memory allocated for
the buffers and roots is freed *
**************************************************/
int main() {

	Node * root = NewNode(NULL);
	char * buffer = malloc(sizeof(char));
	char choice;
	int temp;
	int key;

	do {
		choice = 'a';

		choice = Menu();

		if (choice == 'i')
		{
			root = Insert(root, InsertMessage());
			choice = 'a';
		}
		if (choice == 's')
		{
			temp = SearchMessage();
			SearchOutput(Search(root, temp), temp);
			choice = 'a';
		}
		if (choice == 't')
		{
			InorderTraversal(root, buffer);
			printf("\n");
		}
		if (choice == 'q')
		{
			Burn(root);
		}
		// Project 4 Implementation 
		if (choice == 'r')
		{
			key = RemoveMessage();
			root = Remove(root, key);
			RemoveSuccessMessage();
		}
		getchar();
	} while (choice != 'q');

	return 0;
}