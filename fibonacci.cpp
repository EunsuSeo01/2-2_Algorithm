/*
 Dynamic Programming으로 피보나치 수열 구현.
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
		// 삼항 연산자를 이용해서 조건이 참일 땐 저장된 값을 반환, 거짓일 땐 fibo()함수를 호출하도록 구현함.
		int a = (arr[n - 1] != 0) ? arr[n - 1] : fibo(n - 1);
		int b = (arr[n - 2] != 0) ? arr[n - 2] : fibo(n - 2);

		// Memoization.
		arr[n] = a + b;

		return arr[n];
	}
}

int main() {
	for (int i = 1; i <= 40; i++) {		// 40까지 해도 딜레이가 안 생김.
		printf("fibo[%d] = %d \n", i, fibo(i));
	}

	return 0;
}