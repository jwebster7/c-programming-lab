/**********************************************
* Name: Joseph Webster *
* Date: April 7th, 2018*
* Assignment: Project 3 - Jagged Arrays *
***********************************************
* This program is used for reading in a jagged 
* array from a .txt file
***********************************************/
#include <stdio.h> 
#include <stdlib.h>
#include <string.h>

// Method signatures for all methods (besides main)
void SortLists(int list[], int size);
void PrintLists(int sizeArr[], int rows, int r, int c, int **jaggedArr);
void SortRows(int *jaggedArr[], int size, int *rowSize);

// The main method runs the program
int main(void) {
	char filename[255];
	char line[100];
	int rows, columns, r, c;
	FILE * filePtr;
	int **jaggedArray;
	int *sizeArray;

	printf("Enter the name of a file of type '.txt': ");
	scanf("%s", filename);

	if ((filePtr = fopen(filename, "r")) == NULL)
	{
		printf("There was an error!\nPlease try again.");
		getchar();
		exit(1);
	}
	fscanf(filePtr, "%d", &rows);

	// Allocating memory for the jagged array and the size array
	jaggedArray = malloc(rows * sizeof(int*));
	sizeArray = malloc(rows * sizeof(int));

	// Loop for storing the size of each array, and for reallocating the jagged array
	// 'r' is a counter for the indicee's
	r = 0;
	while (fgets(line, sizeof(line), filePtr) != NULL) {
		columns = atoi(strtok(line, ":"));
		sizeArray[r] = columns;
		jaggedArray[r] = malloc(columns * sizeof(int));
		for (c = 0; c < columns; c++) {
			//printf("You are here");
			jaggedArray[r][c] = atoi(strtok(NULL, ","));
		}
		SortLists(jaggedArray[r++], columns);
		//printf("You are here");
	}
	fclose(filePtr);

	//printf("You are here YEET");
	SortRows(jaggedArray, rows, sizeArray);
	PrintLists(sizeArray, rows, r, c, jaggedArray);
	free(jaggedArray);
	free(sizeArray);
	getchar();
	return 0;
}

// This method sorts the jagged array from least to greatest (element count)
void SortRows(int *jaggedArray[], int rows, int *sizeArray) {
	int i, j, temp;
	int *tempPtr;

	for (i = 0; i < rows - 1; i++) {
		for (j = i + 1; j < rows; j++) {
			if (sizeArray[i] > sizeArray[j]) {
				//swap in pairs
				temp = sizeArray[i];
				sizeArray[i] = sizeArray[j];
				sizeArray[j] = temp;
				tempPtr = jaggedArray[i];
				jaggedArray[i] = jaggedArray[j];
				jaggedArray[j] = tempPtr;
			}
		}
	}

}

// This method sorts the lists on each indicee of the jagged array from least to greatest
void SortLists(int list[], int rows) {
	int i, j, temp;
	for (i = 0; i < rows - 1; i++) {
		for (j = i + 1; j < rows; j++) {

			if (list[i] > list[j]) {
				temp = list[i];
				list[i] = list[j];
				list[j] = temp;
			}
		}
	}
}

// This method prints the sorted jagged array out and frees the memory afterwards at that indicee of the double pointer
void PrintLists(int sizeArr[], int rows, int r, int c, int **jaggedArr)
{
	for (r = 0; r < rows + 1; r++) {
		for (c = 0; c < sizeArr[r]; c++)
			printf("%d ", jaggedArr[r][c]);
		printf("\n");
		free(jaggedArr[r]);
	}
}