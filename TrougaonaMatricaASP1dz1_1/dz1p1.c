#include <stdio.h>
#include <stdlib.h>


#define MAX_LINE 100


int *matrixAllocation(int matrixSize) {
	int *a;
	a = malloc(matrixSize * sizeof(int));
	return a;
}


int isMatrixIndexOutOfRange(int matrixSize, int i, int j) {
	return (i >= matrixSize || j >= matrixSize);
}


int matrixIndicesToArrayIndex(int matrixSize, int i, int j) {
	return i * matrixSize - (i * (i - 1) / 2) + (j - i);
}


int memoryLocationsSaved(int matrixSize) {
	return ((matrixSize * (matrixSize - 1)) / 2) - 1;
}


int isCorrectIntInput(char *s) {
	int i;
	for (i = 0; s[i] != '\0'; i++) {
		if (s[i] > '9' || s[i] < '0') return 0;
	}
	return 1;
}


int strToInt(char *s) {
	int i;
	int returnValue = 0;
	for (i = 0; s[i] != '\0'; i++) {
		returnValue = returnValue * 10 + (int)(s[i] - '0');
	}
	return returnValue;
}


int readInt() {
	int num;
	char s[MAX_LINE];
	int flag = 1;
	while (flag) {
		scanf_s("%s", s, MAX_LINE);
		if (isCorrectIntInput(s)) {
			num = strToInt(s);
			flag = 0;
		}
		else printf("Incorrect input, you must input an integer\n");
	}
	return num;
}


void printMenu() {
	printf("1. Create and initialize matrix\n");
	printf("2. Set default value of matrix\n");
	printf("3. Get element\n");
	printf("4. Set element value\n");
	printf("5. Get number of non-default values\n");
	printf("6. Output matrix\n");
	printf("7. Calculate memory saved\n");
	printf("8. Delete matrix\n");
	printf("0. Exit program\n");
	printf("Enter menu action as integer:\n");
	return;
}


int main() {
	int *a, defaultValue, matrixSize;
	int i, j, arrayIndex;
	int menuOption;
	a = NULL;

	while (1) {
		printMenu();
		menuOption = readInt();
		switch (menuOption) {
		case 1:	// Create and initialize matrix
			if (a != NULL) {
				free(a);
				a = NULL;
			}
			/* TODO: implement */
			break;
		case 2:	// Set default value of matrix
			if (a != NULL) {
				printf("New default value for the matrix:\n");
				defaultValue = readInt();
			}
			break;
		case 3:	// Get element
			/* TODO: implement */
			break;
		case 4:	// Set element value
			/* TODO: implement */
			break;
		case 5:	// Get number of non-default values
			/* TODO: implement */
			break;
		case 6:	// Output matrix
			/* TODO: implement */
			break;
		case 7:	// Calculate memory saved
			if (a != NULL) {
				printf("%d\n", memoryLocationsSaved(matrixSize));
			}
			break;
		case 8:	// Delete matrix
			free(a);
			a = NULL;
			break;
		case 0:	// Exit program
			free(a);
			exit(0);
		default:
			break;
		}
		printf("\n");
	}
	return 0;
}
