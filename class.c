/*
File Name: class.c
Name: Zhen Ye Chen (Raymond)
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "class.h"


int read_from_studentfile(FILE* file_ptr, int* id, int* semester, char* subject, char* catalog_code, char* let_grade, float* num_grade){
	int status;
	//takes in a line and assigns each element to a variable 
	status = fscanf (file_ptr, "%d %d %s %s %s %f", id, semester, subject, catalog_code, let_grade, num_grade);
	return status;
}

