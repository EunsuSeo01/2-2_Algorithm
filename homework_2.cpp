/*
 202035340 ¼­Àº¼ö.
 Algorithm Homework 02.
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
int main() {

	while (1) {
		int student_num = 0;	// The number of students.
		int expense_sum = 0;	// Total travel expenses.
		int divided_expense = 0;	// Travel expenses that have to pay per student. 
		int exchanged_expense = 0;	// Exchanged expenses. (= Output)

		printf("Type the number of students (End: '0'):");
		scanf("%d", &student_num);

		if (student_num == 0)
			break;

		int* expense = (int*)malloc(sizeof(student_num) / sizeof(int));

		// Calculate total travel expenses.
		for (int i = 0; i < student_num; i++) {
			printf("%d-th money spent:", i + 1);
			scanf("%d", &expense[i]);
			expense_sum += expense[i];
		}
		// Calculate travel expenses that have to pay per student.
		divided_expense = expense_sum / student_num;

		// Find exchanged expenses.
		for (int j = 0; j < student_num; j++) {
			if (expense[j] > divided_expense) {
				exchanged_expense += expense[j] - divided_expense;
			}
		}

		printf("The money exchange is %d(Won)\n\n", exchanged_expense);
	}

	return 0;
}