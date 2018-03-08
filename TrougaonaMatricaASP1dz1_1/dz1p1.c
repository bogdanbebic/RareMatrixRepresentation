#include <stdio.h>
#include <stdlib.h>


#define MAX_LINE 100


int *matrixAllocation(int matrixSize) {
	int *a;
	a = malloc(matrixSize * sizeof(int));
	return a;
}


int isMatrixIndexOutOfRange(int matrixSize, int i, int j) {
	return (i >= matrixSize || j >= matrixSize || i < 0 || j < 0);
}


int matrixIndicesToArrayIndex(int matrixSize, int i, int j) {
	return i * matrixSize - (i * (i - 1) / 2) + (j - i);
}


int memoryLocationsSaved(int matrixSize) {
	return ((matrixSize * (matrixSize - 1)) / 2) - 1;
}


int isCorrectIntInput(char *s) {
	int i;
	if (s[0] == '-') i = 1;
	else i = 0;
	for (; s[i] != '\0'; i++) {
		if (s[i] > '9' || s[i] < '0') return 0;
	}
	return 1;
}


int strToInt(char *s) {
	int i;
	int returnValue = 0;
	int isNegative = 0;
	if (s[0] == '-') {
		i = 1;
		isNegative = 1;
	}
	else i = 0;
	for (; s[i] != '\0'; i++) {
		returnValue = returnValue * 10 + (int)(s[i] - '0');
	}
	if (isNegative) returnValue = -returnValue;
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


int *createMatrix(int *a, int *matrixSize) {
	int n;
	printf("Enter matrix dimensions as integer:\n");
	n = readInt();
	if (n > 0) {
		*matrixSize = n * (n + 1) / 2;
		a = matrixAllocation(*matrixSize);
		*matrixSize = n;
	}
	else a = NULL;
	return a;
}


void matrixInit(int *a, int matrixSize) {
	int i, j;
	for (i = 0; i < matrixSize; i++) {
		for (j = i; j < matrixSize; j++) {
			printf("Input the [%d,%d] element:\n", i, j);
			a[matrixIndicesToArrayIndex(matrixSize, i, j)] = readInt();
		}
	}
	return;
}


void outputMatrix(int *a, int defaultValue, int matrixSize) {
	int i, j;
	for (i = 0; i < matrixSize; i++) {
		for (j = 0; j < matrixSize; j++) {
			if (i <= j) 
				printf("%d ", a[matrixIndicesToArrayIndex(matrixSize, i, j)]);
			else 
				printf("%d ", defaultValue);
		}
		printf("\n");
	}
	return;
}


int getElement(int *a, int matrixSize, int i, int j, int defaultValue) {
	return (i <= j) ? a[matrixIndicesToArrayIndex(matrixSize, i, j)] : defaultValue;
}


int getNumberOfNonDefaultValues(int *a, int matrixSize, int defaultValue) {
	int i, j;
	int numberOfNonDefaultValues = 0;
	for (i = 0; i < matrixSize; i++) {
		for (j = i; j < matrixSize; j++) {
			if (a[matrixIndicesToArrayIndex(matrixSize, i, j)] != defaultValue) {
				numberOfNonDefaultValues++;
			}
		}
	}
	return numberOfNonDefaultValues;
}


void readMatrixIndices(int *i, int *j) {
	printf("Enter i (rows) index: ");
	*i = readInt();
	printf("Enter j (cols) index: ");
	*j = readInt();
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
	int *a, matrixSize;
	int defaultValue = 0;
	int i, j;
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
			a = createMatrix(a, &matrixSize);
			if (a != NULL) {
				matrixInit(a, matrixSize);
			}
			else {
				printf("Memory allocation failed, matrix not created\n");
			}
			break;
		case 2:	// Set default value of matrix
			if (a != NULL) {
				printf("New default value for the matrix:\n");
				defaultValue = readInt();
			}
			break;
		case 3:	// Get element
			if (a != NULL) {
				readMatrixIndices(&i, &j);
				if (isMatrixIndexOutOfRange(matrixSize, i, j)) {
					printf("Index error, out of range\n");
				}
				else {
					int elem;
					elem = getElement(a, matrixSize, i, j, defaultValue);
					printf("%d\n", elem);
				}
			}
			break;
		case 4:	// Set element value
			if (a != NULL) {
				readMatrixIndices(&i, &j);
				if (isMatrixIndexOutOfRange(matrixSize, i, j)) {
					printf("Index error, out of range\n");
				}
				else {
					int elem;
					elem = readInt();
					a[matrixIndicesToArrayIndex(matrixSize, i, j)] = elem;
				}
			}
			break;
		case 5:	// Get number of non-default values
			if (a != NULL) {
				int temp;
				temp = getNumberOfNonDefaultValues(a, matrixSize, defaultValue);
				printf("Number of non-default values: %d\n", temp);
			}
			break;
		case 6:	// Output matrix
			if (a != NULL) {
				outputMatrix(a, defaultValue, matrixSize);
			}
			break;
		case 7:	// Calculate memory saved
			if (a != NULL) {
				printf("Memory saved: %d locations\n", memoryLocationsSaved(matrixSize));
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
