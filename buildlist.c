/*
File Name: buildlist.c
Name: Zhen Ye Chen (Raymond)
Description: This is the file that contains the functions that have to deal with single linked lists,
			 more specifically this file contains functions that pertain to SLL of type CRS_PTR and SDT_PTR.
			 Includes string.h because we call on the strstr functions that find substrings.
*/
#include <stdio.h>
#include <stdlib.h>
#include "buildlist.h"
#include <string.h>

CRS_PTR build_CourseList(FILE* fp){
	// this function receive a pointer to a data file and read from it
	// and construct a linked list as it reads the data file.
	// returns the head of the list
	CRS_PTR head, current_node, previous_node;
	head = (CRS_PTR) malloc(sizeof (COURSE));
	int attribute = read_Course_Attributes(fp, head);
	previous_node = head;
	while (attribute > 0){
		current_node = (CRS_PTR) malloc(sizeof (COURSE));
		attribute = read_Course_Attributes(fp, current_node);
		previous_node->next = current_node;
		previous_node = current_node;
	}
	current_node->next = NULL;
	return head;
}

SDT_PTR build_StudentList(FILE* fp){
	SDT_PTR head, current_node, previous_node;
	head = (SDT_PTR) malloc(sizeof (STUDENT));
	int attribute = read_Student_Attributes(fp, head);
	previous_node = head;
	while (attribute > 0){
		current_node = (SDT_PTR) malloc(sizeof (STUDENT));
		attribute = read_Student_Attributes(fp, current_node);
		previous_node->nextstudent = current_node;
		previous_node = current_node;
	}
	current_node->next = NULL;
	return head;
}

void print_CourseList(CRS_PTR cptr){
// traverses the list and returns the number of elements traversed
// prints out the single linked list
	while(cptr->next != NULL){
		print_Course(cptr);
		cptr = cptr->next;
	}
}

void print_StudentList(SDT_PTR sptr){
// traverses the list and returns the number of elements traversed
// prints out the single linked list
	while(sptr->nextstudent != NULL){
		print_Student(sptr);
		sptr = sptr->nextstudent;
	}
}