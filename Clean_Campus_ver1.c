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
	/* y값 제일 작은 point 찾기 */
}

void sort_point(P criterion) {
	/* 기준점 기준으로 반시계 방향으로 각도 재서 그에 맞게 점들 정렬하기 */
}

P* graham_scan(P* point) {
	/* 스택 사용하여 convex hull 만들기 */
}