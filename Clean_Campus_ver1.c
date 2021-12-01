/*
 2021 Algorithm
 Problem 14: Clean Campus - Using Graham's scan algorithm.
 1:22~
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct point {
	int x;
	int y;
} P;

P find_starting_point(P* point);
void sort_point(P criterion);
P* graham_scan(P* point);

int main() {
	int point_num = 0;
	scanf("%d", &point_num);

	P* point = (P*)malloc(sizeof(P) * point_num);
	sort_point(find_starting_point(point));

	return 0;
}

P find_starting_point(P* point) {
	/* y�� ���� ���� point ã�� */
}

void sort_point(P criterion) {
	/* ������ �������� �ݽð� �������� ���� �缭 �׿� �°� ���� �����ϱ� */
}

P* graham_scan(P* point) {
	/* ���� ����Ͽ� convex hull ����� */
}