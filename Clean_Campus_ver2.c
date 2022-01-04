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

// p->q->r ������ �ѷ��δ� ������ �ݽð� ������ �´���
int ccw(struct point p, struct point q, struct point r)
{
	double val = (q.y - p.y) * (r.x - q.x) -
		(q.x - p.x) * (r.y - q.y);	// �� ���� x,y�� ���� ��ȣ�� �������ν� �ݽð�����, �ð�������� �� �� ����.

	if (val == 0.0) return 0;  // collinear
	return (val > 0.0) ? -1 : 1; // clock or counterclock wise
}

// �� �� ������ �Ÿ� ���.
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
			if (ccw(points[p], points[q], points[i]) == -1)	// �ð� ������ i�� �ִ�. == p�� ������ q���� �� ���� ������ �̷�� ���� i�̴�.
				/* �������� points[i]�� ���� �����ν� ������ p -> ���� ���� q -> points[i]��
				   ������ �ѷ����� ���� ������ Ȯ���ϴ� ����. q�� ����� �ΰ�, ��� ���� �̾���ν�
				   �ð� ������ �̷�� �� �ִ��� Ȯ����. = ���� ���� q�� ���� p�� ���� ���� ������ �̷�� ���� �´��� Ȯ���ϴ� ��.
				   �ð� ���� �̷�� ���� �ִٸ� �� ���̶� p�� �̷�� ������ �� ���� ������ ��. */
				q = i;	// ������ �� ���� q�� ������.
		}

		// Now q is the most counterclockwise with respect to p
		// Set p as q for next iteration, so that q is added to
		// result 'hull'
		p = q;
		count++;

	} while (p != l);  // While we don't come to first point

	for (int i = 0; i < count; i++) {
		points[i] = hull[i];	// ������Ʈ
	}
	*m = count;	// convex hull ���� ������Ʈ -> main������ �ٲ� ���� ��� �ؼ� ������ ���·� ������ ��.
}


void main(void) {
	int scenario_num = 0, point_num = 0, num_convex = 0;
	struct point stake = { 0.0, 0.0 };	// ����.
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

		length += 2.0;	// stake�� ���� 1m + 1m

		printf("Result : %.2lf\n", length);
		scenario_num--;
	}
}