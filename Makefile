execute: main.o student.o course.o class.o buildlist.o
	gcc -o execute main.o student.o course.o buildlist.o

main.o: main.c
	gcc -c main.c

student.o: student.c
	gcc -c student.c

course.o: course.c
	gcc -c course.c

class.o: class.c
	gcc -c class.c

buildlist.o: buildlist.c
	gcc -c buildlist.c
#clean up time

clean:
	rm -f *.o execute

# create linked list of courses
# 