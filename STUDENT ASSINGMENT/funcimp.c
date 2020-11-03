/* DEFINATION OF ALL THE FUNCTIONS
   
    Author:              Priyanshu Dugaya
    Registration Number: 201046023
    Department:          Big data and data analytics
	Date:                03/11/2020 
	
LIST OF FUNCTIONS:
manage_seats;------------------------To manage the seats of the program and display them creates a Structure variable and assign values
program_seats;-----------------------To take the values from the admin and stores it in the structure variables
display_seats;-----------------------To display the seats in the Departments
display_total_filled_seats-----------To display total number of filled seats
student_reg;-------------------------To register the details of the students
check_status;------------------------To check if the student is admitted or in waiting list according the marks greater than or less than 5
update_seats;------------------------To update the total filled seats in respective departments
display;-----------------------------To display the details of the students
waiting_students;--------------------To update the status of the students in waiting list
display_waiting_students;------------To display the details of waiting student details
declaration;-------------------------contains the instructions to be accepted before going to acces the program	
*/

#include <string.h>
#include "functions.h"
#include <assert.h>
#include <stdio.h>

/*Program program_seats(int8_t bda, int8_t ml, int8_t es){
	Program prog = {bda,ml,es};      
	return prog;
}*/
//------------------------------------------------------------
void manage_seats(){
	Program pog=program_seats();
	display_seats(pog);
}
//------------------------------------------------------------
//-------------------------------------------------------------
Program program_seats(){
	Program pg;
	printf("\nENTER BDA SEATS:\n");
	scanf("%d",&pg.big_data_seats);
	assert(pg.big_data_seats<=50);             //assert failed if seats of BDA is more than 50
	printf("\nENTER ML SEATS:\n");
	scanf("%d",&pg.machine_learning_seats);
	assert(pg.machine_learning_seats<=25);    //assert failed if seats of ML is more than 25
	printf("\nENTER ES SEATS:\n");
	scanf("%d",&pg.embedded_system_seats);
	assert(pg.embedded_system_seats<=25);    //assert failed if seats of ES is more than 25
	return pg;
}
//-------------------------------------------------------------
//-------------------------------------------------------------
void display_seats(Program pg){
	printf("\nTOTAL SEATS IN PROGRAM:\n");
	printf("\nBDA SEATS = %d\n",pg.big_data_seats);
	
	printf("\nML SEATS = %d\n",pg.machine_learning_seats);
	
	printf("\nES SEATS = %d\n",pg.embedded_system_seats);	
}
//-------------------------------------------------------------
//-------------------------------------------------------------
void display_total_filled_seats(){
	printf("\nTOTAL FILLED SEATS IN RESPECTIVE DEPARTMENTS:\n");
	printf("\nBDA = %d\n",filled_big_data_seats);
	printf("\nML = %d\n",filled_machine_learning_seats);
	printf("\nES = %d\n",filled_embedded_system_seats);
	printf("\nTOTAL = %d\n",total_filled_seats);
}
//-------------------------------------------------------------
//-------------------------------------------------------------
/*	Student student_new(char name[],int32_t reg,char prg[],char email[]){
		Student s;
		s.regnumber=reg;
		strcpy(s.name,name);
		strcpy(s.email,email);
		strcpy(s.program,prg);
		return s;
	}*/
	
	/*int32_t test_admission_status(Student s1){
		Program pg;
			if(!strcmp(s1.program,"BDA")){
				
	        
	            if(pg.filled_big_data_seats==pg.big_data_seats){
	                return 0;
			    }
			    else{
		            pg.filled_big_data_seats+=1;
			        return  pg.filled_big_data_seats;
                }
	        }
	
	        else if(!strcmp(s1.program,"ML")){
	        	 if(pg.filled_big_data_seats==pg.big_data_seats){
	                return 0;
			    }
			    else{
		            pg.filled_machine_learning_seats+=1;
		            return pg.filled_machine_learning_seats;
	            }
	        }
			else if(!strcmp(s1.program,"ES")){
				 if(pg.filled_big_data_seats==pg.big_data_seats){
	                return 0;
			    }
			    else{
		            pg.filled_embedded_system_seats+=1;
		            return pg.filled_embedded_system_seats;
	            }
	        }
	}*/
//-------------------------------------------------------------
//-------------------------------------------------------------
 void student_reg(Student *st){
 	int32_t appnum;
 	int8_t get;
 	printf("\nENTER APPLICATION NUMBER:");
 	scanf("%d",&appnum);
 	printf("\nENTER STUDENT MARKS");
 	scanf("%d",&st[appnum].marks);
 	get=check_status(st[appnum].marks);
 	if(!get){
 		strcpy(st[appnum].status,"ADMITTED");
	 }	
	 else{
	 	strcpy(st[appnum].status,"WAITING");;
	 }
 	printf("\nENTER STUDENT NAME:");
 	scanf("%s",&st[appnum].name);
 	printf("\nENTER REGISTRATION NUMBER:");
 	scanf("%d",&st[appnum].regnumber);
 	printf("\nENTER PROGRAM NAME:");
 	scanf("%s",&st[appnum].program);
 	update_seats(st[appnum].program);
 	printf("\nENTER EMAIL ID:");
 	scanf("%s",&st[appnum].email);
 	
 }
//-------------------------------------------------------------
//-------------------------------------------------------------
 int8_t check_status(int32_t marks){
 	if(marks>5){
 		assert(marks<10);                                             //assert failed if marks are more than 10
 		return 0;
	 }
	 else{
	 	return 1;
	 }
 } 
//-------------------------------------------------------------
//------------------------------------------------------------- 
 void update_seats(char program[]){
 	assert(strcmp(program,"\0")!=0);
 	if(!strcmp(program,"BDA")){
 		filled_big_data_seats+=1;
 		total_filled_seats=filled_big_data_seats+filled_machine_learning_seats+filled_embedded_system_seats;
	 }
	 else if(!strcmp(program,"ML")){
	 	filled_machine_learning_seats+=1;
	 	total_filled_seats=filled_big_data_seats+filled_machine_learning_seats+filled_embedded_system_seats;
	 }
	 else if(!strcmp(program,"ES")){
	 	filled_embedded_system_seats+=1;
	 	total_filled_seats=filled_big_data_seats+filled_machine_learning_seats+filled_embedded_system_seats;
	 }
	 else{
	 	printf("PLEASE ENTER CORRECT PROGRAM NAME");
	 }
 	
 }
//-------------------------------------------------------------
//------------------------------------------------------------- 
 void display(Student *st){
 	int iteration;
 	
 	for(iteration=1;iteration<=total_filled_seats;iteration++){
 		printf("\nNAME:%s \n REGISTRATION NUMBER:%d \n PROGRAM:%s \n EMAIL:%s\n MARKS:%d \n STATUS:%s \n",st[iteration].name,st[iteration].regnumber,st[iteration].program,st[iteration].email,st[iteration].marks,st[iteration].status);
	 }
 }
//-------------------------------------------------------------
//------------------------------------------------------------- 
 void waiting_students(Student *st){
 	int iteration;
 	for(iteration=1;iteration<=total_filled_seats;iteration++){
 		if(!strcmp(st[iteration].status,"WAITING")){
 			if(!strcmp(st[iteration].program,"BDA") && filled_big_data_seats!=50){
 				strcpy(st[iteration].status,"ACCEPTED");}
 			else if(!strcmp(st[iteration].program,"ML") && filled_machine_learning_seats!=50){
 				strcpy(st[iteration].status,"ACCEPTED");	
			 }
			else if(!strcmp(st[iteration].program,"ES") && filled_embedded_system_seats!=50){
 				strcpy(st[iteration].status,"ACCEPTED");
 			}
 			else{
 				strcpy(st[iteration].status,"REJECTED");
			 }	
	 }
 	
 	}
}
//-------------------------------------------------------------
//-------------------------------------------------------------
void display_waiting_students(Student *st){
		int iteration;
 	for(iteration=1;iteration<=total_filled_seats;iteration++){
 		if(!strcmp(st[iteration].status,"WAITING")){
 				printf("\nNAME:%s \n REGISTRATION NUMBER:%d \n PROGRAM:%s \n EMAIL:%s\n MARKS:%d \n STATUS:%s \n",st[iteration].name,st[iteration].regnumber,st[iteration].program,st[iteration].email,st[iteration].marks,st[iteration].status);
 			
		 }
 		
	 }
}
//-------------------------------------------------------------
//-------------------------------------------------------------
int8_t declaration(){
	int dec;
	printf("-----------------------------------DECLARATION AND INSTRUCTIONS-----------------------------\n\n\n\n\n");
	printf("############-------------READ THE INSTRUCTIONS CAREFULLY AND PRESS 1 TO ACCEPT 0 TO DECLINE----------##########\n\n\n\n");
	printf("#-----FILLING PROGRAM SEATS-----#\n\n");
	printf("*FILL THE SEATS ACCORDING TO UNIVERSITY SINCE THERE IS TOTAL 100 SEATS*\n\n\n\n");
	printf("#-----STUDENT REGISTRATION-----#\n\n");
	printf("*ALL THE ENTERIES MUST BE IN CAPITAL LETTER*\n\n*GIVE ONLY FIRST NAME*\n\n*APPLICATION STARTS FROM APPLICATION NUMEBR 1*\n\n*MARKS ARE BETWEEN 1 TO 10*\n\n*PROGRAM NAMES TO BE GIVEN AS* \n\n \t\t\tBDA \n \t\t\tML \n \t\t\tED\n \n\n\n");
	printf("#-----FIRST DECLARE THE SEATS AND STUDEN REGISTRATION-----#\n\n");
	printf("#-----UPDATE WAITING STUDENT DETAILS AFTER ALL THE APPLICANTS ARE REGISTERED-----#\n\n\n\n");
	printf("######----------ENTER YOUR CHOOICE------------######\n");
	scanf("%d",&dec);
	return dec;	
}
//-------------------------------------------------------------
//-------------------------------------------------------------
