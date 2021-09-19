/*
 202035340 ¼­Àº¼ö.
 Algorithm Homework 03.
*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 [subsequenceCount]
 description: Return the number of sub-sequence in sequence string.
 input: X -> Sequence string. Z -> sub-sequence string.
 output: The number of sub-sequence in sequence string
*/
int subsequenceCount(char X[], char Z[])
{
	int m = strlen(Z);
	int n = strlen(X);

	if (m > n) return 0;	// Invaild.

	// Create Matrix.
	int** mat = (int**)malloc(sizeof(int*) * (m + 1));
	for (int i = 0; i <= m; i++) {
		mat[i] = (int*)malloc(sizeof(int) * (n + 1));
	}

	// Initializing first column with all 0s.
	for (int i = 0; i <= m; i++) {
		mat[i][0] = 0;
	}

	// Initializing first row with all 1s.
	for (int j = 0; j <= n; j++) {
		mat[0][j] = 1;
	}

	// Fill mat[][] in bottom up manner
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			if (X[j - 1] == Z[i- 1])
				mat[i][j] = mat[i][j - 1] + mat[i - 1][j - 1];
			else
				mat[i][j] = mat[i][j - 1];
		}
	}

	// return value
	return mat[m][n];
}

int main()
{
	int n;
	char X[10000];
	char Z[100];

	printf("Type the number of test sets: ");
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		printf("Type sequence: ");
		scanf("%s", X);
		printf("Type sub-sequence: ");
		scanf("%s", Z);
		printf("Result: %d \n", subsequenceCount(X, Z));
	}

	return 0;
}
