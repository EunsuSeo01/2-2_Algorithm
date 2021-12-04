/*
 2021 Algorithm
 Problem 15: Clean Campus - Using Javis March Algorithm
*/
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>

struct point {
	double x, y;
};

// p->q->r 순으로 둘러싸는 방향이 반시계 방향이 맞는지
int ccw(struct point p, struct point q, struct point r)
{
	double val = (q.y - p.y) * (r.x - q.x) -
		(q.x - p.x) * (r.y - q.y);	// 세 점의 x,y값 차의 부호를 비교함으로써 반시계인지, 시계방향인지 알 수 있음.

	if (val == 0.0) return 0;  // collinear
	return (val > 0.0) ? -1 : 1; // clock or counterclock wise
}

// 두 점 사이의 거리 출력.
double distance(struct point p, struct point q) {
	double dist = sqrt((p.x - q.x) * (p.x - q.x) + (p.y - q.y) * (p.y - q.y));
	return dist;
}

// Prints convex hull of a set of n points.
void convexHull(int n, int* m, struct point* points)
{
	// There must be at least 3 points
	if (n < 3) return;

	// Initialize Result
	struct point* hull = (struct point*)malloc(sizeof(struct point) * n);

	// Find the leftmost point
	int l = 0;
	for (int i = 1; i < n; i++)
		if (points[i].x < points[l].x)
			l = i;

	// Start from leftmost point, keep moving counterclockwise until reach the start point again
	int p = l, q;
	int count = 0;
	do
	{
		hull[count] = points[p];

		// Search for a point 'q' such that orientation(p, q, x) is counterclockwise for all points 'x'. 
		q = (p + 1) % n;
		for (int i = 0; i < n; i++)
		{
			// If i is more counterclockwise than current q, then update q
			if (ccw(points[p], points[i], points[q]) == 1)	// 반시계 방향인 i가 있다. == p랑 현재의 q보다 더 작은 각도를 이루는 점이 i이다.
				/* 가운데에 points[i]가 들어가게 함으로써 기준점 p -> points[i] -> 새로 택한 q의
				   순서로 둘러쌌을 때의 방향을 확인하는 것임. 모든 점을 가운데에 두고 확인해서
				   새로 택한 q가 현재 p기준 제일 왼쪽에 있는 점이 맞는지 확인하는 것.
				   = p 다음의 점이 q라서 일단 골랐는데, 이 q가 p랑 가장 작은 각도를 이루는 점인지는 모름.
				   q보다 더 작은 각도를 이룰 수 있는 점이 또 없는지 확인하는 것. */
				q = i;	// 있으면 그걸 q로 설정함.
		}

		// Now q is the most counterclockwise with respect to p
		// Set p as q for next iteration, so that q is added to
		// result 'hull'
		p = q;
		count++;

	} while (p != l);  // While we don't come to first point

	for (int i = 0; i < count; i++) {
		points[i] = hull[i];	// 업데이트
	}
	*m = count;	// convex hull 개수 업데이트 -> main에서도 바뀐 값을 써야 해서 포인터 형태로 가져온 것.
}


void main(void) {
	int scenario_num = 0, point_num = 0, num_convex = 0;
	struct point stake = { 0.0, 0.0 };	// 원점.
	scanf("%d", &scenario_num);

	while (scenario_num > 0) {
		printf("\n");
		scanf("%d", &point_num);

		struct point* p = (struct point*)malloc(sizeof(struct point) * point_num);

		for (int i = 0; i < point_num; i++) {
			scanf("%lf %lf", &p[i].x, &p[i].y);
		}

		// get convext hull points
		convexHull(point_num, &num_convex, p);

		double length = 0.0;
		length += distance(stake, p[0]);

		int i;
		for (i = 0; i < num_convex - 1; i++) {
			length += distance(p[i], p[i + 1]);
		}
		length += distance(p[i], stake);

		length += 2.0;	// stake에 묶는 1m + 1m

		printf("Result : %.2lf\n", length);
		scenario_num--;
	}
}