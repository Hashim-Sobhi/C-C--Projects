/***********************************************************************************/
/* Author    : Radwa Ayman  & Hashim Sobhy                                        */
/* Title     : C final project  (Clinic Management System)                       */
/* Sub_Title : clinc file                                                       */
/*******************************************************************************/

#ifndef  CLINC_H
#define  CLINC_H

typedef unsigned long  int   u32; 
/*use linked list to save patient data */
typedef struct node
{
	char first_name[10];
	char last_name[10];
	int  age;
	char gender;
    int  id;
	struct node *nx;
}node;
/*structure to save appointment*/
typedef struct Appointment
{
	char appo[18];
	int id_1;
	
}Appointment;
Appointment arr[5];/*struct of array of size 5 for the 5 slots*/


void main_menu(void)         ;
u32  admin_menu(void)        ;
void check_pass(void)        ;
void add_patient(void)       ;
void edit_patient(void)      ;
void display(u32 user_id)    ;
u32  search_ID(u32 user_id)  ;
void reserve(void)           ;
void cancel_reservation(void);
void show_reservations(void) ;
void user_menu(void)         ;
node *enter_id(void)         ;
#endif