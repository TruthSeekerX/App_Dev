/* This project is meant for studying first year IT engineering course Application Development.
	This is a multi-platform project which contains backend, server and frontend programs.
	The backend program collects/generates data and send them to the server.
	The server program (php) collects the data from backend
	The frontend program (html, javascript) would generate visual representation of the data.
*/

#include "app_dev_project.h"

int main() {
	rock r;
	srand(time(NULL));
	printf("Application Developer Rock!\n");
	printf("Enter Rocker's name: ");
	scanf("%s", r.rname);
	r.max = rand() % 50 + 51;
	r.min = rand() % 50 + 1;

	send_data(r);
	
	printf("Rock'Roll\n");

	return 0;
}