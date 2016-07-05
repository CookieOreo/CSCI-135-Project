
#ifndef CLASS_H
#define CLASS_H

//definition of struct for Class

typedef struct Class {
	int term;
	char subject[6]; //remember to add 1 for null terminator since C
	char catalog_code[6];
	char let_grade[4];
	float num_grade;
	struct Class* next;
} CLASS, *CLS_PTR;

// define all external functions to export here

extern int read_from_studentfile(FILE*, int*, int*, char*, char*, char*, float*);
#endif