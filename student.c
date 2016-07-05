/*
File Name: student.c
Name: Zhen Ye Chen (Raymond)
Description: This is the file that contains the functions to not only read data from another file and instantiate our SDT_PTR 
			 for our single linked list but also has class-like member functions to obtain the member variable values of this structure.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "student.h"
// include necessary files

int read_Student_Attributes(FILE* filePtr, SDT_PTR sptr){
// read one line of the data file here and assign all proper 
// values for the structure pointed by sptr
// return the number of succesfully read attributes
	int id, term;
	float num_grade;
	char subject[6]; //remember to add 1 for null terminator since C
	char catalog_code[6];
	char let_grade[4];
	int num_read = read_from_studentfile (filePtr, &id, &term, subject, catalog_code, let_grade, &num_grade);
	sptr->id = id;
	//allocates memory for this struct
	sptr->next = (CLS_PTR) malloc(sizeof (CLASS));
	build_first_class(sptr->next, term, subject, catalog_code, let_grade, num_grade);
	return num_read;
}

int read_from_studentfile(FILE* file_ptr, int* id, int* term, char* subject, char* catalog_code, char* let_grade, float* num_grade){
	int status;
	//takes in a line and assigns each element to a variable 
	status = fscanf (file_ptr, "%d %d %s %s %s %f", id, term, subject, catalog_code, let_grade, num_grade);
	return status;
}

void print_Student(SDT_PTR sptr){
	printf("ID = %d, Term = %d, Subject = %s, Catalog Code = %s, Letter Grade = %s, Number Grade = %.1f \n", sptr->id, sptr->next->term, sptr->next->subject, sptr->next->catalog_code, sptr->next->let_grade, sptr->next->num_grade);
	//printf("ID = %d\n", sptr->id);//Term = %d, Subject = %s, Catalog Code = %s, Letter Grade = %s, Number Grade = %f \n", sptr->id, sptr->next->term, sptr->next->subject, sptr->next->catalog_code, sptr->next->let_grade, sptr->next->num_grade);
}

void build_first_class(CLS_PTR cptr, int term, char* subject, char* catalog_code, char* let_grade, float num_grade){

	cptr->term = term;
	strcpy(cptr->subject, subject);
	strcpy(cptr->catalog_code, catalog_code);
	strcpy(cptr->let_grade, let_grade);
	cptr->num_grade = num_grade;
	cptr->next = NULL;
}