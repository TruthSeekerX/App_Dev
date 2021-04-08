#include "wlan.h"

int main(void) {
//	system(CMD);
	FILE* fp = fopen("wlan.txt", "r");
	if (fp == NULL) {
		printf("Error: can't open file.\n");
	}
	else {
		printf("File opened successfully. Now analysing wlan data...\n");
		wlan_analyse(fp);
		printf("Closing the file.\n");
		fclose(fp);
		printf("File closed successfully.\n");
	}
	return 0;
}