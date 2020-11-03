/*  THIS PROGRAM IS FOR STUDENT REGISTRATION BASED ON THEIR MARKS AND AVAILABLE SEATS IN THE PERTICULAR DEPARTMENTS
    
    It provides the admin to store the admission details of students based on their marks that are between 1 to 10 
	Also provides option to manage students data who are in waiting list
	Contains a declaration form having instructions to be followed by the admin to use the program.
	  
    
    Author:        PRIYANSHU DUGAYA
	Reg Number:    201046023 
    Department:    Big data and data analytics
    Date:          03/11/2020
    
*/

#include <stdio.h>
#include <stdlib.h>
#include "functions.h"
#include <assert.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int choice;
	int accept;
	Student stu[TOTAL_STUDENT];
	accept=declaration();
	assert(accept==1);

	printf("\n\n\n\n\n\n\n\n\n\n\n--------------------------------------ADMISSION PROCESS---------------------------------------------\n\n");
	printf("1. DECLARE TOTAL SEATS IN RESPECTIVE PROGRAM\n\n");
    printf("2. STUDENT REGISTRATION\n\n");
    printf("3. TOTAL FILLED SEATS IN PROGRAM\n\n");
	printf("4. STUDENT INFORMATION\n\n");
	printf("5. WAITING STUDENTS DETAILS\n\n");
	printf("6. UPDATE WAITING STUDENT DETAILS\n\n");
	printf("0. TO EXIT\n\n");
	do{
	    printf("\nCHOOSE FROM ABOVE OPTIONS:\n");
	    scanf("%d",&choice);
	    switch(choice){
	    	
	    	case 1: manage_seats();
			break;
			
			case 2:	student_reg(stu);
		    break;
			
			case 3: display_total_filled_seats();
			break;
			    
			case 4: display(stu);
			break;    
			
			case 5: display_waiting_students(stu);
			break;
			
			case 6: waiting_students(stu);
			break;
			
			default: assert(choice<7);                    //assert failed if we give wrong choice
			    
			}
		
		
	}while(choice!=0);
	
	return 0;
}
