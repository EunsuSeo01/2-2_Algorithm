/*
 202035340 ¼­Àº¼ö.
 Algorithm Homework 05 : Contest Trip.

 <My strategy>
 1. Find all possible paths from the starting point to the destination.
  1-1. If no path comes out, print "No connection". -> END.
 2. Find the earliest path among them.
  2-1. If there is one path, print that path. -> END.
  2-2. If there are multiple earliest arrival paths,
       choose the path with the latest departure time. -> END.
*/

#define _CRT_SECURE_NO_WARNINGS
#define NAME_SIZE 20
#define MAX_CITY 100
#define MAX_TRAIN 100

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Informations about all the train running during a day.
typedef struct trainInfo {
	int dept_time;
	char dept_location[NAME_SIZE];
	int arr_time;
	char arr_location[NAME_SIZE];
} train_info;

train_info path_no[MAX_TRAIN] = { 0 };	// For saving the possible paths.
void find_min(train_info train[], int path_num);
int find_path(int no, train_info train[], int train_num, int starting_time, char src[], char dest[]);

int main() {
	int scenario = 0, city_num = 0, train_num = 0;

	printf("[Input]\n");
	// Input the number of the scenario.
	scanf("%d\n", &scenario);

	for (int i = 0; i < scenario; i++) {
		scanf("%d\n", &city_num);

		// Defensive coding.
		if (city_num < 1 || city_num > MAX_CITY) {
			exit(0);
		}

		// Input the city names.
		char** city = (char**)malloc(sizeof(char) * city_num);
		for (int j = 0; j < city_num; j++) {
			city[j] = (char*)malloc(sizeof(char) * NAME_SIZE);
			scanf("%s", city[j]);
		}

		// Input the train informations.
		scanf("%d", &train_num);
		train_info* train = (train_info*)malloc(sizeof(train_info) * train_num);

		for (int i = 0; i < train_num; i++) {
			int num;
			scanf("%d", &num);
			scanf("%d %s\n", &train[i].dept_time, train[i].dept_location);
			scanf("%d %s\n", &train[i].arr_time, train[i].arr_location);
		}

		// Input the starting time and source and destination.
		int starting_time = 0;
		char src[NAME_SIZE], dest[NAME_SIZE];

		scanf("%d", &starting_time);
		scanf("%s", src);
		scanf("%s", dest);

		printf("\n[Output]\n");
		// Find all possible paths from source to destination.
		int no = find_path(0, train, train_num, starting_time, src, dest);

		if (no == 0)
			printf("No connection\n");
		else
			find_min(train, no);	// Find the earliest arrival.
	}

	return 0;
}

/*
 [find_path]
 description : Find all the paths from src to dest. (By filling in the path_no array.)
 input : the number of the paths, time table information about train, the number of the train,
 starting time, the starting point, destination.
 output : Returns the number of the paths.
*/
int find_path(int no, train_info train[], int train_num, int starting_time, char src[], char dest[]) {
	for (int i = 0; i < train_num; i++) {
		if (strcmp(train[i].dept_location, src) == 0 && starting_time <= train[i].dept_time) {
			if (path_no[no].dept_time == 0) {
				path_no[no].dept_time = train[i].dept_time;
				strcpy(path_no[no].dept_location, train[i].dept_location);
			}

			if (strcmp(train[i].arr_location, dest) == 0) {
				path_no[no].arr_time = train[i].arr_time;
				strcpy(path_no[no].arr_location, train[i].arr_location);
				no++;
			}
			else {
				no = find_path(no, train, train_num, train[i].arr_time, train[i].arr_location, dest);
			}
		}
	}

	return no;
}

/*
 [find_min]
 description : Find the earliest path from src to dest.
 (But if arriving at the same time, find the latest departure time.)
 input : time table information about train, the number of the paths.
 output : none.
*/
void find_min(train_info train[], int path_num) {
	int min = path_no[0].arr_time, max = path_no[0].dept_time;
	int check = 0, index = 0;

	//  Find the earliest path.
	for (int i = 1; i < path_num; i++) {
		if (path_no[i].arr_time <= min) {
			min = path_no[i].arr_time;
			index = i;
		}
		else if (path_no[i].arr_time == min) {
			check++;
		}
	}

	// Find the latest departure time with the same arrival time.
	if (check >= 1) {
		for (int i = 0; i < path_num; i++) {
			if (path_no[i].arr_time == path_no[index].arr_time) {
				if (max < path_no[i].dept_time) {
					max = path_no[i].dept_time;
					index = i;
				}
			}
		}
	}

	printf("Departure\t%04d\t%s\n", path_no[index].dept_time, path_no[index].dept_location);
	printf("Arrival\t%04d\t%s\n", path_no[index].arr_time, path_no[index].arr_location);
}