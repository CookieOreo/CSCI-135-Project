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
		previous_node->nextStudent = current_node;
		previous_node = current_node;
	}
	current_node->nextStudent = NULL;
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
	while(sptr->nextStudent != NULL){
		print_Student(sptr);
		sptr = sptr->nextStudent;
	}
}

void add_Class(SDT_PTR original, SDT_PTR duplicate){
// adds duplicate's class to original's list of class/classes
	CLS_PTR list = original->classesTaken;
	// reaches the end of the list so we can append this new class
	while(list->next != NULL){
		list = list->next;
	}
	list->next = duplicate->classesTaken;
}

void clean_StudentList(SDT_PTR sptr){
// traverses the list and for every different ID, find all the other classes
// that this person took and link it to their classTaken list
// as we traverse the list we "delete" the node once we have added the class
// to the respective person's classTaken list
	int id;
	while(sptr->nextStudent != NULL){
		id = sptr->id;
		SDT_PTR checkStudent = sptr->nextStudent;
		SDT_PTR previous = sptr;
		while(checkStudent->nextStudent != NULL){
			if(checkStudent->id == id){
				add_Class(sptr, checkStudent);
				// this is the "deleting" line. sets the previous node's next
				// to this node's next, essentially ignoring this node when 
				// traversing down the list
				previous->nextStudent = checkStudent->nextStudent;
				checkStudent = checkStudent->nextStudent;
			}
			else{
				// condition doesn't pass so we move previous node to current node 
				// and current node to next node
				previous = checkStudent;
				checkStudent = checkStudent->nextStudent;
			}
		}
		sptr = sptr->nextStudent;
	}
}

int calculate_Overall_GPA(SDT_PTR){
	// caluclates and returns the overall gpa of a single student
}






