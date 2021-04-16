/* This project is meant for studying first year IT engineering course Application Development.
	Score project is meant for studying construct a software/program as multi files. 
*/
#include "score.h"

//main function only sketches out the logic of program
int main(int argc, char *argv[]) {
	int scores[MAX] = { 0 }, marks[MAX] = { 0 };
	int statistics[6] = { 0 };		//

	input_scores(scores);	//pointer
	evaluation(scores, marks);
	classification(marks, statistics);
	output_results(scores,marks, statistics);

	return 0;
}