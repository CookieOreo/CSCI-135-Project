#include <stdio.h>
#include <string.h>
#include <stdlib.h> // for malloc fuction
#include "buildlist.h"

int main() {
// declarations of types that we'll be using. name only needs at most 6 letters so i made it an array of 7 since we need to
// include the null terminator for the "string".
int id, semester, num_grade;
char subject[5]; //remember to add 1 for null terminator since C
char catalog_code[6];
char let_grade[4];
FILE* fp;

// builds linked list using StudentData.tsv
fp = fopen("StudentData.tsv", "r");
SDT_PTR student_head = build_StudentList(fp);
fclose(fp);

// // builds the linked list using HunterCourses.tsv
// fp = fopen("HunterCourses.tsv", "r");
// CRS_PTR course_head = build_CourseList(fp);
// fclose(fp);

// cleans the StudentList linked list
clean_StudentList(student_head);
print_StudentList(student_head);
}