/*
File Name: student.h
Name: Zhen Ye Chen (Raymond)
Description: This is the header file for student.c that contains the function declarations of the functions
			 to not only read data from another file and instantiate our SDT_PTR for our single linked list
			 but also declares the class-like member functions to obtain the member variable values of this structure.
			 The structure of car is also declared here so the other files only have to include student.h for the structure.
*/
#ifndef STUDENT_H
#define STUDENT_H
#include "class.h"

//definition of struct for Student
typedef struct Student {
	int id;
	//ClassList classesTaken; //a linked list of Class Objects
	CLS_PTR classesTaken;
	struct Student* nextStudent;
} STUDENT, *SDT_PTR;

//declare all external functions to export
extern int read_Student_Attributes(FILE*, SDT_PTR);
extern int read_from_studentfile(FILE*, int*, int*, char*, char*, char*, float*);
extern void print_Student(SDT_PTR);
extern void build_first_class(CLS_PTR, int, char*, char*, char*, float);
extern float calculate_Overall_GPA(SDT_PTR);
extern float calculate_CSCI_GPA(SDT_PTR);
#endif