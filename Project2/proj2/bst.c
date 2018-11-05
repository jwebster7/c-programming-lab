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
#include "bst.h"
#include "io.h"

// This is a struct for constructing a BinaryTreeNode;
// Type-defined as a 'Node';
// Has a (int) key, (BinaryTreeNode *) left, (BinaryTreeNode *) right;
typedef struct BinaryTreeNode {
	int key;
	struct BinaryTreeNode * left;
	struct BinaryTreeNode * right;
} Node;

/*************************************************
* Description: NewNode creates a new node using the 'Node' struct *
* Precondition: key is a valid, 32-bit integer*
* Post condition: Returns a newly constructed node whose key value is equal to key argument; left & right children are NULL *
**************************************************/
Node * NewNode(int key) {
	Node * node = malloc(sizeof(Node));
	node->key = key;
	node->left = NULL;
	node->right = NULL;
	return node;
}

/*************************************************
* Description: Insert inserts a node with the associated key into the tree *
* Precondition: Node != NULL, key is a valid 32-bit int *
* Post condition: Returns a tree with the arguments added in their respective destinations; Will not add duplciate keys *
**************************************************/
Node * Insert(Node * node, int key) {

	if ((node->key == 0 || node->key == NULL) && key != 0) {
		node->key = key;
		return node;
	}

	if (node->key == key) {
		return node;
	}
	
	else if (key > node->key) {
		if (node->right == NULL) {
			node->right = NewNode(key);
			return node;
		}
		else {
			Insert(node->right, key);
		}
	}
	
	else {
		if (node->left == NULL) {
			node->left = NewNode(key);
			return node;
		}
		else {
			Insert(node->left, key);
		}
	}
	
	return node;
}

/*************************************************
* Description: Search function is used for searching a given key in the node (tree)  *
* Precondition: Node != NULL; key is a valid 32-bit integer *
* Post condition: Return TRUE if the nodes key field is equivalent to argument key;
				  Return FALSE if the NODE is empty/NULL;
			      Recursively search right child if the NODES key field is less than the argument key 
				  Recursively search left child if the NODES key field is greater than the argument key *
**************************************************/
bool Search(Node * node, int key) {
	if(!node) {
		return false;
	}
	else if (node->key == key) {
		return true;
	}
	// If not the root, then search the right or left child
	else if (node->key < key) {
		return Search(node->right, key);
	}
	else {
		return Search(node->left, key);
	}
}

/*************************************************
* Description: InorderTraversal prints the trees keys in ascending order (1, 2, 3, etc.) to a buffer/pointer/string *
* Precondition: NODE != NULL; buffer != NULL *
* Post condition: buffer will contain the values stored in the NODES of the tree inorder *
**************************************************/
void InorderTraversal(Node * node, char * buffer) {
	if (node != NULL) {
		InorderTraversal(node->left, buffer);
		sprintf(buffer, "%d", node->key);
		TraversalOutput(buffer);
		InorderTraversal(node->right, buffer);
	}
}

/*************************************************
* Description: Burn frees the memory at the given address *
* Precondition: A NODE is passed in *
* Post condition: The memory @ &NODE is freed *
**************************************************/
void Burn(Node * node) {
	free(node);
}