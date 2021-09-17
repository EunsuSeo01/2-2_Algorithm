/*
 Dynamic Programming���� �Ǻ���ġ ���� ����.
 last modified 2021-09-17
*/
#include <stdio.h>
#define MAX 100

int arr[MAX] = { 0, 1, };

int fibo(int n) {
	if (n == 0 || n == 1) {
		return arr[n];
	}

	else {
		// ���� �����ڸ� �̿��ؼ� ������ ���� �� ����� ���� ��ȯ, ������ �� fibo()�Լ��� ȣ���ϵ��� ������.
		int a = (arr[n - 1] != 0) ? arr[n - 1] : fibo(n - 1);
		int b = (arr[n - 2] != 0) ? arr[n - 2] : fibo(n - 2);

		// Memoization.
		arr[n] = a + b;

		return arr[n];
	}
}

int main() {
	for (int i = 1; i <= 40; i++) {		// 40���� �ص� �����̰� �� ����.
		printf("fibo[%d] = %d \n", i, fibo(i));
	}

	return 0;
}