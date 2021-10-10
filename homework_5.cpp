/*
 202035340 서은수.
 Algorithm Homework 05 : Contest Trip.

 <My strategy>
 1. 출발지부터 목적지까지 가는 가능한 경로를 다 찾는다.
 2. 그 중 목적지에 도착한 시간이 최소인 것을 고른다.
 2-1. 하나라면 그것이 정답.
 2-2. 여러개면 그 중 출발 시간이 최대인 것을 고른다.
*/

#define _CRT_SECURE_NO_WARNINGS
#define NAME_SIZE 20
#define MAX_CITY 100
#define MAX_TRAIN 100

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

// 출발지부터 목적지까지 가는 가능한 경로를 다 찾는다.
void find_available_path(int** timeT, char** city, int row, int col, int starting_time, char* src, char* dest) {
	int src_index = -1;
	int dest_index = -1;
	int start = 0, end = 0;

	for (int j = 0; j < col; j++) {
		for (int i = 0; i < row; i++) {
			if (strcmp(city[i], src) == 0) {
				src_index = i;
				dest_index = j;
				start = timeT[i][j];
				break;
			}
		}
	}
	printf("%04d %s\n", start, src);


	for (int i = src_index; i < row; i++) {
		if (timeT[i][dest_index] != 0 && end == 0) {
			//if (strcmp(city[i], dest) != 0)

			end = timeT[i][dest_index];
		}
	}
	printf("%04d %s\n", start, src);

	printf("%04d %s\n", end, dest);
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

		for (int i = 0; i < table_num; i++) {
			int iter = 0;
			scanf("%d", &iter);

			for (int num = 0; num < iter; num++) {
				make_timetable(i, timetable, city, city_num);
			}
		}	// 시간표 까지 다 받음.

		int starting_time = 0;
		char src[NAME_SIZE], dest[NAME_SIZE];

		scanf("%d", &starting_time);
		scanf("%s", src);
		scanf("%s", dest);

		for (int i = 0; i < city_num; i++) {
			find_available_path(timetable, city, city_num, table_num, starting_time, src, dest);
		}
	}

	return 0;
}