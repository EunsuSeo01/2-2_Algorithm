/*
 202035340 ¼­Àº¼ö.
 Algorithm Homework 01.
 In this homework, 'front' means that index is 'zero' and 'end' means that index is 'pencake_num - 1'.
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 [flip]
 Description: Reversing the stack.
 Output: none.
 Input: num = the index that start reversing, diameter = stack, pencake_num = the number of pencake.
*/
void flip(int num, int diameter[], int pencake_num) {
	int count = (int)((double)num / 2 + 0.5);

	for (int i = 0; count > 0; i++) {
		int tmp = diameter[i];
		diameter[i] = diameter[num - i];
		diameter[num - i] = tmp;
		count--;
	}

	printf("%d ", pencake_num - num);
}

int main() {

	while (!feof(stdin)) {	// end at EOF.
		char temp[100];
		int pencake_num = 0;
		int diameter[30];
		int i, j;
		int find = 0;
		char* pt;

		if (!gets_s(temp, sizeof(temp))) break;

		printf("%s\n", temp);

		// Parsing and saving the input values.
		pt = strtok(temp, " ");

		for (int index = 0; pt != NULL; index++) {
			diameter[index] = atoi(pt);
			pt = strtok(NULL, " ");
			pencake_num++;
		}

		// Find a index for reversing.
		for (i = pencake_num - 1; i >= 1; i--) {
			int max = diameter[i];
			int max_position = i;

			// Find a max value. (Among indexes excluding i-th or later indexes)
			for (j = i - 1; j >= 0; j--) {
				if (max < diameter[j]) {
					max = diameter[j];
					max_position = j;
					find = 1;
				}
			}

			if (find == 1) {
				// Reversing step1: to send to the front.
				// except for the case that the value of the front position is already the max value.
				if (max_position != 0 && diameter[max_position] != diameter[0]) {
					flip(max_position, diameter, pencake_num);
					max_position = 0;
				}

				// Reversing step2: to send to the end.
				// If the front value has the same value as the i-th index, just go to the next i.
				if (diameter[max_position] != diameter[i]) {
					flip(i, diameter, pencake_num);
				}
				find = 0;
			}
		}
		printf("0\n");
	}
	return 0;
}