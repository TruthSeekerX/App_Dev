#include "app_dev_project.h"

int main() {
	rock r;

	printf("Application Developer Rock!\n");
	printf("Enter Rocker's name: ");
	scanf("%s", r.rname);
	r.max = rand() % 50 + 51;
	r.min = rand() % 50 + 1;

	send_data(r);
	
	printf("Rock'Roll\n");

	return 0;
}