/*
 202035340 ¼­Àº¼ö.
 Algorithm Homework 04 : The Cheapest Way.

 <My strategy>
 1. Read a file.
 2. Create a matrix.
 3. Fill the matrix.
 4. Update the value of the right side to the minimum value in the left three values.
 5. Repeat 4 until the index of column is n - 1.
 6. Find the minimum value of the values stored in the column of n - 1. (That is The Cheapest Way!)
 7. Trace the path in reverse order from the Cheapest Way.
*/

#define _CRT_SECURE_NO_WARNINGS
#define MAX_ROW 10
#define MAX_COL 100

#include <stdio.h>
#include <stdlib.h>

int result[2] = { 0 };	// For saving a path(result[0]) and the min value(result[1]).

void find_the_path(int** path, int row_size, int row, int col);
void find_min_from_left(int top_left, int left, int down_left);
int find_cheapest(int** mat, int m, int n);

int main() {
	FILE* inputFile = fopen("input.txt", "r");

	if (inputFile == NULL) {
		exit(0);
	}

	while (!feof(inputFile)) {
		int m, n;
		fscanf(inputFile, "%d %d\n", &m, &n);
		if (m > MAX_ROW || n > MAX_COL) {
			printf("Out of bounds! Please retry.");
			exit(0);
		}

		int** mat = (int**)malloc(sizeof(int*) * m);
		for (int i = 0; i < m; i++) {
			mat[i] = (int*)malloc(sizeof(int) * n);
		}												// Implement 1,2 of the strategy.

		int value = 0;
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				value = fgetc(inputFile);
				if (value == ' ') {
					value = fgetc(inputFile);
				}

				mat[i][j] = value - 48;
			}
			fgetc(inputFile);
		}												// Implement 3 of the strategy.

		printf("<Print the matrix for checking>\n");
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				printf("%d ", mat[i][j]);
			}
			printf("\n");
		}

		printf("\n<Output>\n");
		printf("%d \n", find_cheapest(mat, m, n));
		printf("\n");
	}

	return 0;
}

/*
 [find_min_from_left]
 description : Find the minimum value in the left three values.
 input : top left value, left value, down left value.
 output : none.
*/
void find_min_from_left(int top_left, int left, int down_left) {
	int min = top_left;	// temp.
	result[0] = 1;		// 1 means that this minimum value comes from the top left value.

	if (min > left) {
		min = left;
		result[0] = 2;	// 2 means that this minimum value comes from the left value.
	}
	if (min > down_left) {
		min = down_left;
		result[0] = 3;	// 3 means that this minimum value comes from the down left value.
	}

	result[1] = min;
}

/*
 [find_cheapest]
 description : Find the path and sum of the Cheapest Way.
 input : matrix, the size of row, the size of column.
 output : the sum of the Cheapest Way.
*/
int find_cheapest(int** mat, int m, int n) {
	int** path = (int**)malloc(sizeof(int) * m);
	for (int i = 0; i < m; i++) {
		path[i] = (int*)malloc(sizeof(int) * n);
	}

	for (int j = 1; j < n; j++) {
		for (int i = 0; i < m; i++) {
			if (i - 1 < 0)	// if the current row index is 0
				find_min_from_left(mat[m - 1][j - 1], mat[i][j - 1], mat[i + 1][j - 1]);
			else if (i + 1 > m - 1)	// if the current row index is row - 1
				find_min_from_left(mat[i - 1][j - 1], mat[i][j - 1], mat[0][j - 1]);
			else
				find_min_from_left(mat[i - 1][j - 1], mat[i][j - 1], mat[i + 1][j - 1]);

			path[i][j] = result[0];		// Denote where the value came from using numbers 1, 2, 3.
			mat[i][j] += result[1];		// Update a matrix.
		}
	}													// Implement 4,5 of the strategy.

	int	min = mat[0][n - 1];	// temp.
	int final_row = 0;		// The final row of the cheapest way.
	for (int k = 1; k < m; k++) {
		if (min > mat[k][n - 1]) {
			min = mat[k][n - 1];
			final_row = k;
		}
	}													// Implement 6 of the strategy.

	// Print the path of the Cheapest Way.
	find_the_path(path, m, final_row, n - 1);
	printf("%d \n", final_row + 1);

	return min;
}

/*
 [find_the_path]
 description : Trace the path in reverse order from where the minimum sum comes from and print that.
 input : path, size of the row, current row, current col.
 output : none.
*/
void find_the_path(int** path, int row_size, int row, int col) {
	if (col == 0)
		return;

	if (path[row][col] == 1) {
		if (row - 1 < 0)	// For connecting the bottom row and the top row.
			row = row_size;
		find_the_path(path, row_size, row - 1, col - 1);	// Go to the top left value.
		printf("%d ", row);
	}
	else if (path[row][col] == 2) {
		find_the_path(path, row_size, row, col - 1);	// Go to the left value.
		printf("%d ", row + 1);
	}
	else {
		if (row + 1 == row_size)	// For connecting the bottom row and the top row.
			row = -1;
		find_the_path(path, row_size, row + 1, col - 1);	// Go to the down left value.
		printf("%d ", row + 2);
	}													// Implement 7 of the strategy.
}

