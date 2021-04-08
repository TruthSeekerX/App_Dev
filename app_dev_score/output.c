#include "score.h"

void output_results(int *scores, int *marks, int*statistics) {
	int i;
	printf("Here are the marks:\n");
	for (i = 0; i < MAX && scores[i] != -1; i++) {
		printf("%3d ", scores[i]);
	}
	puts("");
	for (i = 0; i < MAX && marks[i] != -1; i++) {
		printf("%3d ", marks[i]);
	}

	puts("");	//make a new line

	printf("Here are the statistics:\n");
	printf("________________________________________________\n");
	for (i = 0; i < 6; i++) {
		printf("Mark %d: %d hits\n", i, statistics[i]);
	}
}