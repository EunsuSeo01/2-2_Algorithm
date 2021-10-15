/*
 202035340 ������.
 Algorithm Problem 08 : Fashionable Dressmaker's Problem.

 <My strategy>
 1. job ���� n��ŭ�� �迭�� �����.
 2. i��° job�� �Ǹ��������� ������ ���� ������ ���� ���Ѵ�.
 3. �� ������ ���� ���� ū job���� ���� �����Ѵ�.
 */
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

int find_min_penalty(int** job, int num, int* fine_sum);

int main() {
	int test_case = 0;
	scanf("%d", &test_case);

	while (test_case != 0) {
		int job_num = 0, time_sum = 0;
		scanf("%d", &job_num);

		int** job = (int**)malloc(sizeof(int*) * job_num);
		for (int i = 0; i < job_num; i++) {
			job[i] = (int*)malloc(sizeof(int) * 2);
			scanf("%d %d", &job[i][0], &job[i][1]);
			time_sum += job[i][0];
		}

		int* fine_sum = (int*)malloc(sizeof(int) * job_num);

		for (int i = 0; i < job_num; i++) {
			fine_sum[i] = (time_sum - job[i][0]) * job[i][1];
		}

		for (int i = 0; i < job_num; i++) {
			printf("%d ", find_min_penalty(job, job_num, fine_sum));
		}

		test_case--;
	}

	return 0;
}

/*
 ���� �ؾߵǴ� job�� ��ȣ�� �������ش�.
*/
int find_min_penalty(int** job, int num, int* fine_sum) {
	int max = fine_sum[0];
	int index = 0;

	for (int i = 1; i < num; i++) {
		if (max < fine_sum[i]) {
			max = fine_sum[i];
			index = i;
		}
	}

	for (int i = 0; i < num; i++) {
		if (i == index)
			fine_sum[i] = -1;
		else if (fine_sum[i] != -1)
			fine_sum[i] -= job[index][0] * job[i][1];
	}

	return index + 1;
}