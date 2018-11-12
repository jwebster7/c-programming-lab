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
#include "io.h"
#include "bst.h"
#include <stdlib.h>

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

		getchar();
	} while (choice != 'q');
	
	getchar();
	return 0;
}