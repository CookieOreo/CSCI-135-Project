/*
File Name: course.c
Name: Zhen Ye Chen (Raymond)
Description: This is the file that contains the functions to not only read data from another file and instantiate our CRS_PTR 
			 for our single linked list but also has class-like member functions to obtain the member variable values of this structure.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "course.h"
// include necessary files

int read_from_coursefile(FILE* file_ptr, char* subject, char* catalog, float* hours, char* DR){
	int status;
	//takes in a line and assigns each element to a variable 
	status = fscanf (file_ptr, "%s %s %f %s", subject, catalog, hours, DR);
	return status;
}

int read_Course_Attributes(FILE* file_ptr, CRS_PTR cptr){
// read one line of the data file here and assign all proper 
// values for the structure pointed by cptr
// return the number of succesfully read attributes
	char subject[5];
	char catalog[6];
	float hours;
	char DR[5];
	int num_read = read_from_coursefile(file_ptr, subject, catalog, &hours, DR);
	strcpy(cptr->subject, subject);
	strcpy(cptr->catalog, catalog);
	cptr->hours = hours;
	strcpy(cptr->DR, DR);
	return num_read;
}

void print_Course(CRS_PTR cptr){
	printf("Subject = %s, Catalog Code = %s, Hours = %.2f, DR = %s\n", cptr->subject, cptr->catalog, cptr->hours, cptr->DR);
}