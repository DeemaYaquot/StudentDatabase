#include "STD.h"
#include "SDB.h"
#include <stdio.h>
#include <stdlib.h>

student *student1, *student2, *student3, *student4;
u8 no_students=4;

//Returns 1 if number of students in database is 10 which means that database is full
//Returns 0 otherwise
bool SDB_IsFull(){
	if(no_students==10){return true;}
	else{return false;}
}


//Returns number of students in database
u8 SDB_GetUsedSize(){
	return no_students;
}

//Checks if database is full and if so, returns 0.
//Adds student to database by initializing a pointer of type student. The pointer carries address of first entry.
//While loop runs until the entry pointing to NULL is found(aka last entry). User enters data and number of students increases by 1.
bool SDB_AddEntry(){
    if(SDB_IsFull()){return false;}
    student* current = student1;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = (student *) malloc(sizeof(student));
	printf("Enter student ID\n");
	scanf("%d",&current->next->Student_ID);
	printf("Enter student year\n");
	scanf("%d",&current->next->Student_year);
	printf("Enter Course 1 ID\n");
	scanf("%d",&current->next->Course1_ID);
	printf("Enter Course 1 grade\n");
	scanf("%d",&current->next->Course1_grade);
	printf("Enter Course 2 ID\n");
	scanf("%d",&current->next->Course2_ID);
	printf("Enter Course 2 grade\n");
	scanf("%d",&current->next->Course2_grade);
	printf("Enter Course 3 ID\n");
	scanf("%d",&current->next->Course3_ID);
	printf("Enter Course 3 grade\n");
	scanf("%d",&current->next->Course3_grade);
	current->next->next=NULL_;
	no_students++;
	return true;
}

//Looks for student ID in database. If ID is found, it decreases the number of students in database by 1 and locates the ID, then deletes it.
//If ID isn't found, it prints "ID not found in database".
void SDB_DeleteEntry(u32 id){
	if(SDB_IsIdExist(id)==1){
		if(student1->Student_ID==id) {student1=student1->next;}
		else{
			student* current = student1->next;
			student* previous = student1;
			while (current) {
				if (current->Student_ID == id) {
					previous->next = current->next;
					free(current);
					break;
				}
				previous = current;
				current  = current->next;
			}
		}
        printf("Entry deleted successfully\n");
		no_students-=1;
	}
	else printf("ID not found in database\n");
}

//Declares a pointer of type student called current that carries address of first entry.
//For loop runs until the ID entered by user matches one in the database.
//Function prints data of student then returns 1.
//Function returns 0 if ID is not found.
bool SDB_ReadEntry(u32 id){
    student* current = student1;
    u8 i;
    for(i=1;i<=no_students;i++){
        if(current->Student_ID == id){
            printf("Student ID = %d\n",current->Student_ID);
            printf("Student year = %d\n",current->Student_year);
            printf("Course 1 ID = %d\n",current->Course1_ID);
            printf("Course 1 grade = %d\n",current->Course1_grade);
            printf("Course 2 ID = %d\n",current->Course2_ID);
            printf("Course 2 grade = %d\n",current->Course2_grade);
            printf("Course 3 ID = %d\n",current->Course3_ID);
            printf("Course 3 grade = %d\n",current->Course3_grade);
            return true;
        }
        else{
           current = current->next;
        }
    }
	if(i>=no_students)return false;
}

//Declares a pointer of type student called current that carries address of first entry.
//ID of first entry is stored in an array pointed to by pointer called list.
//Current points to next entry to store ID and so on.
//Pointer count points to the number of students in database.
void SDB_GetList(u8* count, u32* list){
	student* current = student1;
    u8 i;
    *count=no_students;
    for(i=0;i<no_students;i++){
        list[i]=current->Student_ID;
        current = current->next;
    }
}

//Declares a pointer of type student called current that carries address of first entry.
//Function compares id pointed to by current pointer and returns 1 if it matches ID entered by user.
//If it doesn't match, current will point to next entry until ID is found.
//If ID is not found, function returns 0.
bool SDB_IsIdExist(u32 id){
	student* current = student1;
    u8 i;
    for(i=1;i<=no_students;i++){
        if(current->Student_ID == id){
            return true;
        }
        else{
           current = current->next;
        }
    }
	if(i>=no_students)return false;
}

