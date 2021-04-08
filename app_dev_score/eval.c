#include "score.h"

void evaluation(int* scores, int* marks) {
	int i;

	for (i = 0; i < MAX && scores[i] != -1; i++) {
		if (*(scores + i) >= 0 && *(scores + i) <= 30) *(marks + i) = 0;
		else if (*(scores + i) > 30 && *(scores + i) < 45) *(marks + i) = 1;
		else if (*(scores + i) >= 45 && *(scores + i) < 60) *(marks + i) = 2;
		else if (*(scores + i) >= 60 && *(scores + i) < 75) *(marks + i) = 3;
		else if (*(scores + i) >= 75 && *(scores + i) < 90) *(marks + i) = 4;
		else if (*(scores + i) >= 90 && *(scores + i) <= 100) *(marks + i) = 5;
		else *(marks + i) = NULL;	//option 2 is to discard the error data all together
	}
	printf("%d scores evaluated\n",i);
	marks[i] = -1;
}