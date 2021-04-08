#include "score.h"

void input_scores(int *scores) {
	int i, input = 0;

	//using a sentinel-controled loop
	printf("Enter Scores, -1 to end:\n");

	for (i = 0; i < MAX && input != -1; i++) {	
		//Soloution 1 for input error, is to ask user to input the data again
		//till the data is within the range[-1,100]. -1 is for sentinel-control
		do {
			printf("%d: ", i + 1);
			scanf("%d", &input);
			if (input < -1 || input > 100) {
				printf("Sorry,the input data is out of range, please try again.\n");
			}
			else continue;
		} while (input < -1 || input > 100);
		*(scores + i) = input;
	}
}