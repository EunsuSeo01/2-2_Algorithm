/*
 202035340 ¼­Àº¼ö.
 Algorithm Homework 03.
*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int subsequenceCount(char S[], char T[])
{
	int m = strlen(S);
	int n = strlen(T);

	if (n > m) return 0;

	int** mat = (int**)malloc(sizeof(int*) * n);
	for (int i = 0; i < n; i++) {
		mat[i] = (int*)malloc(sizeof(int) * m);
	}

	// Initializing first column with all 0s.
	for (int i = 0; i < n; i++) {
		mat[i][0] = 0;
	}

	// Initializing first row with all 1s.
	for (int i = 0; i < m; i++) {
		mat[0][i] = 1;
	}

	// Fill mat[][] in bottom up manner
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			/* code here */
		}
	}

	// return value
	/* code here */
}

int main()
{
	int n;
	char T[10000];
	char S[100];

	printf("Type the number of test sets: ");
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		printf("Type sequence: ");
		gets_s(S);
		printf("Type sub-sequence: ");
		gets_s(T);
		printf("Result: %d \n", subsequenceCount(S, T));
	}

	return 0;
}
