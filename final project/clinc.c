/***********************************************************************************/
/* Author    : Radwa Ayman  & Hashim Sobhy                                        */
/* Title     : C final project  (Clinic Management System)                       */
/* Sub_Title : clinc file                                                       */
/*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "STD_TYPES.h"
#include "CLINC.h"
node *head=NULL;
u32 counter=0; //number of reserved slots
u32 back_flag=0;//to detect which menu to back to;

/*opening window menu for modes*/
void main_menu(void)
{

    printf("\n[1] Admin mode\n");
    printf("[2] user mode\n");
    printf("[3] exis\n");
    printf("\n\n");

    int x=0;
    printf("option:");
    scanf("%d",&x);

    switch(x)
    {
    case 1:
        system("cls");
        check_pass();
        break;
    case 2:
        system("cls");
        user_menu();
        break;
    case 3:
        system("cls");
        printf("Exiting the program....\n");
        exit(0);
        break;
    default:
        system("cls");
        printf("wrong choice , please try again\n\n");
        main_menu();
    }

}
//check admin password
void check_pass(void)
{
    u32 pass;
    u8 count=1;
    printf("\nplease enter password:");
    scanf("%d",&pass);
    system("cls");


    while((pass!=1234)&&(count<3))
    {
        count++;
        printf ("\n wrong password pleas try again:");
        scanf("%d",&pass);

    }
    if(pass==1234)
    {
        count=0;

        system("cls");
        admin_menu();
    }
    if(count==3)
    {
        printf ("\n wrong password,no more trial \n");
    }


}
u32 admin_menu (void)
{
    printf("	/////Admin mode//// \n");
    int x=0;
    u32 y;
    printf("To add new patient record press         [1]\n");
    printf("To edit  patient record press           [2]\n");
    printf("To reserve a slot with the doctor press [3]\n");
    printf("To cancel reservation press             [4]\n");
    printf("To display patient data                 [5]\n");
    printf("To close admin mode press               [0]\n");
    scanf("%d",&x);

    switch(x)
    {
    case 0 :
        system("cls");
        main_menu() ;
        break;
    case 1 :
        system("cls");
        add_patient();
        break;
    case 2 :
        system("cls");
        edit_patient();
        break;
    case 3 :
        system("cls");
        reserve();
        break;
    case 4 :
        system("cls");
        cancel_reservation();
        break;
    case 5 :
        system("cls");
        printf("\nenter user ID: ");
        scanf("%d",&y);
        back_flag=1;
        display(y);
        break;
    default:
        system("cls");
        printf("wrong choice ,try again\n");
        admin_menu();

    }

}

void add_patient(void)
{
    node *temp=(node*)malloc(sizeof(node));
    //first name
    printf("first name : ");
    scanf("%s",&temp->first_name);

    //last name
    printf("last name : ");
    scanf("%s",&temp->last_name);

    //age
    printf("age : ");
    scanf("%d",&temp->age);

    //gender
    printf("gnder ('F':for female / 'M': for male) : ");
    scanf("%s",&temp->gender);

    //id
    u32 id;
    printf("id : ");
    scanf("%d",&id);
    while(search_ID(id)!=0)
    {
        printf("id is exist,try another one");
        printf("\nid : ");
        scanf("%d",&id);
    }
    temp->id=id;
    if(head == NULL)
        head = temp ;
    else
    {
        node *current=head;
        while(current->nx!=NULL)
        {
            current = current -> nx;
        }
        current -> nx =temp;
    }
    system("cls");
    admin_menu();
}

void edit_patient(void)
{
    u32 id;
    u32 count=2;
    node* temp;
    printf("pleas enter patient ID : ");
    scanf("%d",&id);
    temp=search_ID(id);
    while((temp==0)&&(count>0))
    {
        printf("ID is not exist,try another one");
        printf("\nID : ");
        scanf("%d",&id);
        --count;
        printf(" %d trial left\n",count);
    }
    if(count==0)
    {
        system("cls");
        admin_menu();
    }
    printf("\npleas enter the new data for the ID:%d\n",id);
    //first name
    printf("first name : ");
    scanf("%s",&temp->first_name);

    //last name
    printf("last name : ");
    scanf("%s",&temp->last_name);

    //age
    printf("age : ");
    scanf("%d",&temp->age);

    //gender
    printf("gnder ('F':for female / 'M': for male) : ");
    scanf("%s",&temp->gender);
    system("cls");
    admin_menu();

}
//reverse a slot
void reserve(void)
{
    int x;


    if (head == NULL)
    {
        system("cls");
        printf("No patients recorded yet\n");
        printf("\n press 0 to back\npress 1 to exsit :");
        scanf("%d",&x);
        if(x==1)
            exit(0);
        system("cls");
        admin_menu();
    }
    else if(counter==5)
    {
        system("cls");
        printf("All appointments have been booked today");
        printf("\n press 0 to back\npress 1 to exsit : ");

        scanf("%d",&x);
        if(x==1)
            exit(0);
        system("cls");
        admin_menu();
    }
    else
    {
        node *temp=enter_id();
        int slot;

        for(int i=0; i<5; i++)
        {
            if((arr[i].id_1)==(temp ->id))
            {
                printf("This id already has appointment");
                printf("\n press 0 to back\npress 1 to exsit : ");

                scanf("%d",&x);
                if(x==1)
                    exit(0);
                system("cls");
                admin_menu();
            }
        }

        for (int i=0; i<5; i++)
        {
            if ((arr[i].id_1)==0)
            {
                printf("[%d]  %s\n",(i+1),arr[i].appo);
            }
        }

        printf("Any other number to back\n\n");
        printf("slot :");
        scanf("%d",&slot);

        if((slot>0)&&(slot<6)&&(arr[slot-1].id_1 ==0))
        {
            arr[slot-1].id_1=temp->id;
            counter++;
        }

    }
    system("cls");
    admin_menu();
}


void cancel_reservation(void)
{
    u32 x;
    if (head == NULL)
    {
        printf("No patients recorded yet\n");
        printf("\n press 0 to back\npress 1 to exsit : ");
        scanf("%d",&x);
        if(x==1)
            exit(0);
        system("cls");
        admin_menu();
    }
    else if(counter==0)
    {
        printf("No reservations yet");
        printf("\n press 0 to back\npress 1 to exsit : ");
        scanf("%d",&x);
        if(x==1)
            exit(0);
        system("cls");
        admin_menu();
    }
    else
    {
        node *temp=enter_id();

        for(int i=0; i<5; i++)
        {
            if((arr[i].id_1)==(temp ->id))
            {
                arr[i].id_1=0;
                counter--;
                admin_menu();
            }
        }
        printf("This id has no appointment");
    }
    system("cls");
    admin_menu();
}

void user_menu(void)
{
    printf("	/////user mode//// \n");

    printf("[1] Show data of patient\n");
    printf("[2] View today's reservations\n");
    printf("[3] back\n");
    printf("\n\n");

    int x=0;
    int z;
    printf("option:");
    scanf("%d",&x);

    switch(x)
    {
    case 1:
        system("cls");
        printf("\nenter user ID:");
        scanf("%d",&z);
        display(z);
        break;
    case 2:
        system("cls");
        show_reservations();
        break;
    case 3:
        system("cls");
        main_menu();
        break;
    default:
        system("cls");
        printf("wrong choice , please try again");
        user_menu();
    }
}


void show_reservations(void)
{
    u32 x;
    if (head == NULL)
        printf("No patients recorded yet\n");

    else if(counter==0)
        printf("No reservations yet");

    else
    {
        for (int i=0; i<5; i++)
        {
            if ((arr[i].id_1)!=0)
            {
                printf("id:%d    %s\n",arr[i].id_1,arr[i].appo);
            }
        }
    }
    printf("\npress any key to back : ");
    scanf("%d",&x);
    if(x)
    {
        system("cls");
        user_menu();
    }

}




//display patient data
void display(u32 user_id)
{
    int x;
    node *temp;
    temp=search_ID(user_id);
    if(temp!=0)
    {

        printf("\n-------------------------------------------\n");
        printf("name : %s ",temp->first_name);
        printf("%s\n",temp->last_name);
        printf("age : %d\n",temp->age);
        printf("gender : %c\n",temp->gender);
        printf("id : %d\n",temp->id);
        printf("\n press 0 to back\npress 1 to exsit : ");
        scanf("%d",&x);
        printf("\n-------------------------------------------\n");

        if(x)
            exit(0);

        if(back_flag==1)
        {
            back_flag=0;
            system("cls");
            admin_menu();
        }
        if(back_flag==0)
        {
            system("cls");
            user_menu();
        }

    }
    else
        printf("id not exist");
    printf("\npress 0 to back\npress 1 to exsit : ");
    scanf("%d",&x);

    if(x)
        exit(0);
    if(back_flag==1)
    {
        back_flag=0;
        system("cls");
        admin_menu();
    }
    if(back_flag==0)
    {
        system("cls");
        user_menu();
    }


}

node *enter_id(void)
{
    int id_patient;
    int x;
    printf("please enter id :");
scan:
    scanf("%d",&id_patient);

    node *ptr=head;
    while(id_patient!=ptr ->id)
    {
        ptr = ptr -> nx;
        if (ptr==NULL)
        {
            printf("-----------------------------------------------------\n");
            printf("incorrect ID,pleas try again \n");
            printf("OR \n press 0 to back\n");
            printf("-----------------------------------------------------\n");

            if(!id_patient)
            {
                system("cls");
                admin_menu();

            }
            goto scan;
        }
    }
    return ptr;
}

u32 search_ID(u32 user_id)
{
    node *current;
    current=head;
    while((current!=NULL)&&(current->id!=user_id))
    {

        current = current->nx;
    }
    return (current != NULL) ? current:0 ;

}
