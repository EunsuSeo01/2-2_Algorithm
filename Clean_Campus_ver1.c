/*
 2021 Algorithm
 Problem 14: Clean Campus - Using Graham's scan algorithm.
 1:22~
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct point {
	float x;
	float y;
} P;

P find_starting_point(P* point, int point_num);
void sort_point(P criterion);
P* graham_scan(P* point);

int main() {
	int point_num = 0;
	scanf("%d", &point_num);

	P* point = (P*)malloc(sizeof(P) * point_num);

	for (int i = 0; i < point_num; i++) {
		scanf("%f %f", &point[i].x, &point[i].y);
	}
	sort_point(find_starting_point(point, point_num));

	return 0;
}

P find_starting_point(P* point, int point_num) {
	/* y�� ���� ���� point ã�� */
	P min = point[0];
	for (int i = 1; i < point_num; i++) {
		if (min.y == point[i].y) {
			if (min.x >= point[i].x) {
				min = point[i];
			}
		}
		else if (min.y > point[i].y) {
			min = point[i];
		}
	}

	return min;
}

void sort_point(P criterion) {
	/* ������ �������� �ݽð� �������� ���� �缭 �׿� �°� ���� �����ϱ� */
}

P* graham_scan(P* point) {
	/* ���� ����Ͽ� convex hull ����� */
}