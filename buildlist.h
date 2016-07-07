/*
File Name: buildlist.h
Name: Zhen Ye Chen (Raymond)
*/

#ifndef BUILDLIST_H
#define BUILDLIST_H
#include "course.h"
#include "student.h"

extern CRS_PTR build_CourseList(FILE*);
extern SDT_PTR build_StudentList(FILE*);
extern void print_CourseList(CRS_PTR);
extern void print_StudentList(SDT_PTR);
extern void clean_StudentList(SDT_PTR);
extern void clean_StudentList(SDT_PTR);
extern void calculate_GPA(SDT_PTR);
#endif