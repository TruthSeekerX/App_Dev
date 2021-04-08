#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

/*
In a header file, usually we put following information:
1. constant definitions
2. data structure definitions
3. funtion prototypes
*/
#define MAX 30		//# is preprocessor

// we don't use complex data structure in this program

//Function prototypes
void input_scores(int *);
void evaluation(int *, int *);
void classification(int *, int *);
void output_results(int *,int *, int *);