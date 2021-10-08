/*
 202035340 서은수.
 Algorithm Homework 05 : Contest Trip.

 <My strategy>
 1. Read a file.
 2. Use struct array.
*/

#define _CRT_SECURE_NO_WARNINGS
#define NAME_SIZE 20
#define MAX_CITY 100
#define MAX_TRAIN 100

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct timetable {
	int timestamp;
	char city[20];
} timeT;

int main() {
	int scenario = 0, city_num = 0, table_num = 0;

	scanf("%d\n", &scenario);	// 시나리오는 몇개 제한?
	
	for (int i = 0; i < scenario; i++) {
		scanf("%d\n", &city_num);
		
		// Defensive coding.
		if (city_num < 1 || city_num > MAX_CITY) {
			exit(0);
		}

		char** city = (char**)malloc(sizeof(char) * city_num);
		for (int j = 0; j < city_num; j++) {
			city[j] = (char*)malloc(sizeof(char) * NAME_SIZE);
			scanf("%s", city[j]);
		}

		scanf("%d", &table_num);
		int** timetable = (int**)calloc(sizeof(int), city_num);
		for (int i = 0; i < table_num; i++) {
			timetable[i] = (int*)calloc(sizeof(int), table_num);
		}

	/*	int iter = 0;
		char check_city[NAME_SIZE];
		scanf("%d", &iter);
		scanf("%d %s", &, check_city);*/

	}
		
	
  
	return 0;
}