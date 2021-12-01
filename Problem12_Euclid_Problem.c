#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int gcd(int a, int b);
void extended(int a, int b);

int x, y, d;

int main() {
	int a = 0, b = 0;
	scanf("%d %d", &a, &b);

	if (a > b)
		d = gcd(a, b);
	else
		d = gcd(b, a);

	extended(a, b, d);

	printf("%d %d %d\n", x, y, d);

	return 0;
}

/* Find GCD using Euclid Algorithm */
int gcd(int a, int b) {
	if (b == 0)
		return a;
	else
		gcd(b, a % b);
}

/* Extended Euclid Algorithm */
void extended(int a, int b) {
	if (b == 0) {
		x = 1;
		y = 0;
	}
	else {
		extended(b, a % b);
		int tmp = y;
		y = x - a / b * y;
		x = tmp;
	}
}