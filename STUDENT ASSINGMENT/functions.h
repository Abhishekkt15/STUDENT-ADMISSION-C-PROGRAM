/*DECLARATION OF ALL THE FUNCTIONS , STRUCTURES, AND STATIC VARIABLES
  
   Author:              Priyanshu Dugaya
   Registration Number: 201046023
   Department:          Big data and data analytics
   Date:                03/11/2020

*/

#include <stdint.h>
#include "appconst.h"
#ifndef STUDENT_H_INCLUDED
#define STUDENT_H_INCLUDED


//--------------------------------------------------------
// STATIC VARIABLES DECLARATION
	static int8_t filled_big_data_seats=0;
	static int8_t filled_machine_learning_seats=0;
	static int8_t filled_embedded_system_seats=0;
	static int8_t total_filled_seats=0;
//---------------------------------------------------------


//---------------------------------------------------------	
// STRUCTUCTRE DEFINING STUDENT ATRRIBUTES
struct _student_{
	char name[STUDENT_NAME_LEN];
	int32_t regnumber;
	char program[PROGRAM_NAME_LEN];
	char email[STUDENT_EMAIL_LEN];
	int32_t marks;
	char status[STATUS_LEN];
};
//----------------------------------------------------------
// CHANGING THE NAME OF STRUCTURE 
typedef struct _student_ Student;
//----------------------------------------------------------


//----------------------------------------------------------

//STRUCTURE DEFINING PROGRAM ATTRIBUTES
struct _program_{
	int8_t big_data_seats;
	int8_t machine_learning_seats;
	int8_t embedded_system_seats;
	
};
//----------------------------------------------------------
// CHANGING THE NAME OF STRUCTURE
typedef struct _program_ Program;


//-----------------------------------------------------------




//-----------------------------------------------------------
// FUNCTIONS DECLARATIONS

Program program_seats();
Student student_new(char name[],int32_t reg, char prg[], char email[]);
int8_t check_status(int32_t marks);
void update_seats(char *program);
void student_reg(Student *st);
void display(Student *st);
void fill_seats(Program pg);
void display_seats(Program pg);
void display_total_filled_seats();
void manage_seats();
void waiting_student(Student *st);
void display_waiting_students(Student *st);
int8_t declaration();
//-----------------------------------------------------------










#endif

