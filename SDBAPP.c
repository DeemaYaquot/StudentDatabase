#include "STD.h"
#include "SDB.h"
#include "SDBAPP.h"
#include <stdlib.h>
#include <stdio.h>

extern student *student1, *student2, *student3, *student4; //declared in SDB.c
u8 choice;
//Function has super loop that prints a list of choices to user, takes their choice using scanf, calls SDB_action() and gives it choice as a parameter.
void SDB_APP(){


    student1=(student*)malloc(sizeof(student));
    student2=(student*)malloc(sizeof(student));
    student3=(student*)malloc(sizeof(student));
    student4=(student*)malloc(sizeof(student));

    //student 1
    student1->Student_ID=2001001;
    student1->Student_year=1;
    student1->Course1_ID=123;
    student1->Course1_grade=27;
    student1->Course2_ID=234;
    student1->Course2_grade=15;
    student1->Course3_ID=345;
    student1->Course3_grade=29;
    student1->next=student2;

    //student 2
    student2->Student_ID=2001002;
    student2->Student_year=2;
    student2->Course1_ID=456;
    student2->Course1_grade=16;
    student2->Course2_ID=567;
    student2->Course2_grade=18;
    student2->Course3_ID=678;
    student2->Course3_grade=19;
    student2->next=student3;

    //student 3
    student3->Student_ID=2001003;
    student3->Student_year=3;
    student3->Course1_ID=789;
    student3->Course1_grade=14;
    student3->Course2_ID=890;
    student3->Course2_grade=3;
    student3->Course3_ID=901;
    student3->Course3_grade=8;
    student3->next=student4;

    //student 4
    student4->Student_ID=2001004;
    student4->Student_year=4;
    student4->Course1_ID=012;
    student4->Course1_grade=23;
    student4->Course2_ID=213;
    student4->Course2_grade=24;
    student4->Course3_ID=321;
    student4->Course3_grade=29;
    student4->next=NULL_;

	while(1){
		printf("To add entry, enter 1\nTo get used size in database, enter 2\nTo read student data, enter 3\nTo get the list of all student IDs, enter 4\nTo check if ID exists, enter 5\nTo delete student data, enter 6\nTo check if database is full, enter 7\nTo exit, enter 0\n");
		scanf("%d",&choice);
		SDB_action(choice);
	}
}

//Gets user's choice from SDB_APP() and calls a function that fulfills the user's choice appropriately using switch.
void SDB_action(u8 choice){
    u8 count;
    u32 IDlist[10];
	switch(choice){
	case(0):{
		exit(0);
		break;
	}
	case(1):{
	    u8 x=SDB_AddEntry();
		if(x==1) printf("Entry added successfully\n");
		else if(x==0) printf("Database is full. Unable to add entry\n");
		break;
	}
	case(2):{
	    printf("Number of students in database = %d\n",SDB_GetUsedSize());
        break;
	}
    case(3):{
        u32 id;
        printf("Enter student ID\n");
        scanf("%d",&id);
        if(SDB_ReadEntry(id)==0) printf("ID not found in database\n");
		break;
    }
    case(4):{
        SDB_GetList(&count,&IDlist);
        u8 i,j;
        for(i=0;i<count;i++){
            j=i+1;
            printf("Student number %d ID = %d\n",j,IDlist[i]);
        }
        break;
    }
    case(5):{
        u32 id;
        printf("Enter student ID\n");
        scanf("%d",&id);
        if(SDB_IsIdExist(id)==0) printf("ID not found in database\n");
        else printf("ID found in database\n");
        break;
    }
    case(6):{
        u32 id;
        printf("Enter student ID\n");
        scanf("%d",&id);
        SDB_DeleteEntry(id);
        break;
    }
    case(7):{
        if(SDB_IsFull()==1)printf("Database is full\n");
        else printf("Database is not full\n");
        break;
    }
    }
    printf("\n\n");
}
