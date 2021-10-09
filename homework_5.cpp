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

void make_timetable(int n, int** timeT, char** city, int cityN) {
	int temp_time = 0;
	char temp_city[NAME_SIZE] = {};

	scanf("%d %s", &temp_time, temp_city);

	for (int i = 0; i < cityN; i++) {
		if (strcmp(temp_city, city[i]) == 0) {
			timeT[i][n] = temp_time;
		}
	}
}

void find_shortest(int** timeT, int col, int row) {
	int starting_time = 0;
	char src[NAME_SIZE], dest[NAME_SIZE];

	scanf("%d", &starting_time);
	scanf("%s", src);
	scanf("%s", dest);

	for (int j = 0; j < col; j++) {
		for (int i = 0; i < row; i++) {

		}
	}
	
}

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
		}										// 연결된 도시의 수까지 받음.

		scanf("%d", &table_num);
		int** timetable = (int**)calloc(sizeof(int), city_num);
		for (int i = 0; i < table_num; i++) {
			timetable[i] = (int*)calloc(sizeof(int), table_num);
		}

		for(int i = 0; i < table_num; i++) {
			int iter = 0;
			scanf("%d", &iter);

			for (int num = 0; num < iter; num++) {
				make_timetable(i, timetable, city, city_num);
			}
		}	// 시간표 까지 다 받음.
		
		find_shortest(timetable, table_num, city_num);
	}
  
	return 0;
}