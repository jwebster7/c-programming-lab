/**********************************************
* Name: Joseph Webster						  *
* Date: Wednesday, January 31st 2018		  *
* Assignment: Project 1: Integer Operations   *
***********************************************
* This program takes in an array of integers  *
* and computes the sum of the values in the   *
* array, and the reversed values of the array *
***********************************************/

#include <string.h>		// Includes the "string" libraries for C
#include <stdio.h>		// Includes the "standard input/output" libraries for C

void Reverse(char[]);	// Method signature for recursive function Reverse()
char reverseInput[10];	// A char[] which acts like a container for the reversedInput of the recursive function, Reverse()
int index = 0;			// A global index variable for keeping track of indicees.

void Summation(char[]);	// Method signature for recursive function Summation()
int sum = 0;			// An intever which acts like a container for the sum of the recursive function, Summation()

/**********************************************
* Input: Must be greater than 0 and real (non-decimal)
* Output: Will print the Reverse and Summation of the User input
*	      assuming the pre-condition is met
* Pre-condition: User input is a Real Number great than or equal to 0
* Post-condition: The Summation and Reverse of the User input will be displayed
***********************************************/
int main()
{
	char input[11];
	int valid = 1;

	do
	{
		printf("Enter a number: ");
		scanf_s("%s", &input, 11);
		getchar();

		// If the input is negative...
		if (input[0] == 45)
		{
			valid = 0;
			printf("Invalid input!!!\n\n");
		}
		// If the # of digits is greater than 10
		else if (strlen(input) - 1 > 10)
		{
			valid = 0;
			printf("Invalid input!!!\n\n");
		}
		else
		{
			valid = 1;
		}
	} while (valid == 0);

	Reverse(input);
	printf("\nReversed: %s", reverseInput);

	index = 0;
	Summation(input);
	printf("\nSum of digits: %d", sum);

	getchar();
	return 0;
}

/**********************************************
* Input: char[] from user input
* Output: char[] from user input reversed
* Pre-condition: For all real number that is 9 digits or less long & greater than or equal to 0
* Post-condition: For any 9 digit number:
*				  The first digit will now be in the ones place
*				  The second digit will now be in the tens place
*				  The third digit will noe be in the hundredths place
*				  This will be true for all nine digit number > 0
***********************************************/
void Reverse(char input[])
{
	if (strlen(input) != index)
	{
		reverseInput[index] = input[strlen(input) - (index + 1)];
		index++;
		Reverse(input);
	}
}

/**********************************************
* Input: char[] from user input
* Output: the sum of all char converted to ints from the number given by user input
* Pre-condition: For all real numbers, "input" must be less than 10 digits & greater than -1
* Post-condition: For any 9 digit real number > 0...
*				  "sum" will be sum of all digits within the 9 digit real number
***********************************************/
void Summation(char input[])
{
	if (strlen(input) != index)
	{
		sum += input[index] - 48;
		index++;
		Summation(input);
	}
}