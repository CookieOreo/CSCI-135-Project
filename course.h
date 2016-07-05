/*
File Name: course.h
Name: Zhen Ye Chen (Raymond)
Description: This is the header file for course.c that contains the function declarations of the functions
			 to not only read data from another file and instantiate our SDT_PTR for our single linked list
			 but also declares the class-like member functions to obtain the member variable values of this structure.
			 The structure of car is also declared here so the other files only have to include student.h for the structure.
*/
#ifndef COURSE_H
#define COURSE_H

//definition of struct for Student
typedef struct Course {
	char subject[6];
	char catalog[6];
	float hours;
	char DR[5];
	struct Course* next; //creating a linked list of all courses
} COURSE, *CRS_PTR;

extern int read_from_coursefile(FILE*, char*, char*, float*, char*);
extern int read_Course_Attributes(FILE*, CRS_PTR);
extern void print_Course(CRS_PTR);
#endif

