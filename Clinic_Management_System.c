/********************************************
 *      Clinic_Management_System.c
 *
 *      Created on: Aug 17, 2023
 *      Author: Zeyad Mostafa
 ********************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#define MAX_LIMIT 30

struct list_node * head = NULL;

int res[6]={0};
char res_str[6][20]={ " ","2pm to 2:30pm","2:30pm to 3pm","3pm to 3:30pm",
		"4pm to 4:30pm","4:30pm to 5pm" };

typedef struct list_node
{
	char name[MAX_LIMIT];
	int age ;
	char gender;
	int id;
	int res_no;
	struct list_node *next;
}ListNode;

void AddNewPatient(char name[],int age,char gender,int id);
int CheckID(int id);
void EditPatientRecord(int id);
void Reserve_Slot_With_Doctor(int id);
void CancelReservation(int id);
void ViewPatientRecord(int id);
void ViewTodayReservations(void);
void delete_list(void);

int main (void)
{
	//used For printing messages before scanf in eclipse terminal
			setvbuf(stdout, NULL, _IONBF, 0);
			setvbuf(stderr, NULL, _IONBF, 0);

	printf("\n|-----------------------------------------------------------------|\n");
	printf("|-------------------- Welcome to our clinic ----------------------|\n");
	printf("|-----------------------------------------------------------------|\n\n");

	unsigned int password ,choice1,count=0,u_input;
	while(1)
	{
		/* THE MAIN MENU */
	count=1;
	printf("\n*******************************************************************\n");
	printf("\n1. admin mode\n");
	printf("\n2. user mode\n");
	printf("\n3. Quit the system\n\n");
	printf("\n*******************************************************************\n");
	scanf("%d",&choice1);



	if(choice1==1)
	{
		    char g;
		    int ii, a,c2=0;
		    char string[MAX_LIMIT];
		    printf("\n*******************************************************************\n");
			printf("\nEnter Password : ");
			scanf("%d",&password);
			/* CHECK THE PASSWORD */
			if(password !=1234)
			{
			while(count<3)
			{
				printf("\n*******************************************************************\n");
				printf("\nIncorrect password, enter the password again :");
				scanf("%d",&password);
				if(password==1234)
				{
					break;
				}
				count++;
				printf("\n*******************************************************************\n");
			}
			if(count>=3)
			{
				printf("\n*******************************************************************\n");
			    printf("\nYou have entered the wrong password several times, so the system will be closed..\n");
			    printf("\n*******************************************************************\n");
				delete_list();
				return 0;
			}
			}
			while(c2!=5)
			{

			printf("\n*******************************************************************\n");
			printf("1. Add new patient record\n");
			printf("\n2. Edit patient record\n");
			printf("\n3. Reserve a slot with the doctor\n");
			printf("\n4. Cancel reservation.\n");
			printf("\n5. Back to the main menu.\n\n");
			printf("\n*******************************************************************\n");
			scanf("%d",&c2);

			if(c2==1)
			{
				        printf("\n*******************************************************************\n");
						printf("\nEnter Patient name : ");
						scanf(" %[^\n]s", string);
						printf("\nEnter Patient Age : ");
						scanf("%d",&a);
						printf("\nEnter Patient Gender (M/F) : ");
						scanf(" %c",&g);
						while(1)
						{
						printf("\nEnter Patient ID : ");
						scanf("%d",&ii);
						if(!CheckID(ii))
						{
							break;
						}
						else
						{
							printf("\n###############################################\n");
							printf("\nThis ID is already exist..!\n");
							printf("\nPlease enter another ID..!\n");
							printf("\n###############################################\n");
						}
						}

						printf("\n*******************************************************************\n");
						printf("=> The patient data has been recorded successfully <=");
						printf("\n*******************************************************************\n");
						AddNewPatient(string,a,g,ii);
			}

			else if(c2==2)
	        {
				        printf("\n*******************************************************************\n");
						printf("Enter Patient ID : ");
						scanf("%d",&ii);
						printf("*******************************************************************\n");
						EditPatientRecord(ii);

			}


			else if(c2==3)
			{
						printf("\n*******************************************************************\n");
						printf("Enter Patient ID : ");
						scanf("%d",&ii);
						printf("*******************************************************************\n");
						Reserve_Slot_With_Doctor(ii);

			}


			else if(c2==4)
			{
						printf("\n*******************************************************************\n");
				        printf("Enter Patient ID : ");
						scanf("%d",&ii);
						printf("*******************************************************************\n");
						CancelReservation(ii);

			}

			}



	}


	else if(choice1==2)
	{
		    int zz;
			u_input=0;
		    while(u_input !=3)
		    {
		    printf("*******************************************************************\n");
			printf("\n1. View patient record.\n");
			printf("\n2. View today’s reservations.\n");
			printf("\n3. Back to the main menu.\n\n");
			printf("\n*******************************************************************\n");
			scanf("%d",&u_input);

			switch(u_input)
			{
					case 1:
						printf("\n*******************************************************************\n");
						printf("Enter Patient ID : ");
						scanf("%d",&zz);
						printf("*******************************************************************\n");
						ViewPatientRecord(zz);
						break;
					case 2:
						printf("\n*******************************************************************\n");
						ViewTodayReservations();
						break;

			}
		    }

	}


	else if(choice1==3)
	{
		delete_list();
			return 0;
	}


	else
	{
			printf("\nInvalid choice..!\n");
	}





   }






	return 0;
}





void AddNewPatient(char name[],int age,char gender,int id)
{

	ListNode * NewNode=(ListNode *)malloc(sizeof(ListNode));

	strcpy(NewNode->name, name);
	NewNode->age=age;
	NewNode->gender=gender;
	NewNode->id=id;
	NewNode->res_no=0;
	NewNode->next=NULL;

	if(head==NULL)
	{
		head=NewNode;
	}
	else
	{
		ListNode * curr=head;
		while(curr->next != NULL)
		{
			curr=curr->next;
		}
		curr->next = NewNode;
	}
}
int CheckID(int id)
{
	if(head==NULL)
	{
		return 0;
	}
	int temp=0;
	ListNode* curr=head;
	while(curr != NULL)
	{
		if(curr->id ==id)
		{
			temp=1;
			break;
		}
		curr=curr->next;
	}
	return temp;
}

void EditPatientRecord(int id)
{
		int temp=0,x;
		ListNode * curr=head;
		while(curr !=NULL)
		{
			if(curr-> id == id)
			{
				temp=1;
				break;
			}
			curr=curr->next;
		}
		if(temp)
		{
			printf("\n*******************************************************************\n");
			printf("What do you want to modify in the patient data : \n");
			printf("    \n1. name\n");
			printf("    \n2. age\n");
			printf("    \n3. gender\n");
			printf("\n*******************************************************************\n");
			scanf("%d",&x);
			printf("*******************************************************************\n");
			switch(x)
			{
			case 1:
				printf("\n*******************************************************************\n");
				char str[MAX_LIMIT];
				printf("\nEnter the new name : ");
				scanf(" %[^\n]s", str);
				strcpy(curr->name, str);
				printf("\n*******************************************************************\n");
				printf("\n*******************************************************************\n");
				printf("=> The patient data has been modified successfully <=");
				printf("\n*******************************************************************\n");
				break;

			case 2:
				printf("\n*******************************************************************\n");
				printf("\nEnter the new age : ");
			    scanf("%d", &curr->age);
			    printf("\n*******************************************************************\n");
			    printf("\n*******************************************************************\n");
				printf("=> The patient data has been modified successfully <=");
				printf("\n*******************************************************************\n");
				break;

			case 3:
				printf("\n*******************************************************************\n");
				printf("\nEnter the new age : ");
				scanf(" %c", &curr->gender);
				printf("\n*******************************************************************\n");
			    printf("\n*******************************************************************\n");
				printf("=> The patient data has been modified successfully <=");
				printf("\n*******************************************************************\n");
				break;

			default:
				printf("\nInvalid choice...!\n");
			}
		}
		else
		{
			printf("\nThis ID  does not exist..!\n");
			return;
		}
}



void Reserve_Slot_With_Doctor(int id)
{
	ListNode * curr=head;
	while(curr !=NULL)
	{
		if(curr-> id == id)
		{
			break;
		}
		curr=curr->next;
	}
	if(curr==NULL)
	{
		printf("\nThis ID  does not exist..!\n");
		return;
	}
	if(curr->res_no !=0)
	{
		printf("\nThis patient already booked an appointment..\n");
		return;
	}


	int slot;
	printf("Available appointments :  \n\n");
	for(int i=1;i<=5;i++)
	{
		if(res[i]==0)
		{
			printf("%d- ( %s )\n",i,res_str[i]);
		}
		else
		{
			printf("%d- ( booked up )\n",i);
		}
	}
    printf("\n*******************************************************************\n");
	scanf("%d" ,&slot );
    printf("*******************************************************************\n");
    printf("=> The appointment has been booked  successfully<=");




	curr->res_no=slot;
	res[slot]=1;
}


void CancelReservation(int id)
{
	        ListNode * curr=head;
			while(curr !=NULL)
			{
				if(curr-> id == id)
				{
					break;
				}
				curr=curr->next;
			}
		   if(curr==NULL)
		   {
			   printf("\nThis ID  does not exist..!\n");
			   return;
		   }

			res[curr->res_no]=0;
			curr->res_no=0;
			 printf("=> The appointment has been cancelled successfully<=");

}


void ViewPatientRecord(int id)
{
	char temp = 0;
	ListNode * curr=head;
	while(curr !=NULL)
	{
		if(curr-> id == id)
		{
			temp =1;
			break;
		}
		curr=curr->next;
	}
   if(curr==NULL)
   {
	   printf("\nThis ID  does not exist..!\n");
	   return;
   }

	if(temp)
	{
		printf("\n*******************************************************************\n");
		printf("NAME : %s \n",curr->name);
		printf("ID : %d\n",curr->id);
		printf("AGE : %d\n",curr->age);
		printf("GENDER : %c\n",curr->gender);
		if(curr->res_no !=0)
		{
			printf("appointment : %s\n",res_str[curr->res_no]);
		}
		else
		{
			printf("appointment : Not booked yet\n");
		}
		printf("\n*******************************************************************\n");



	}
	else
	{
		printf("\nThis ID  does not exist..!\n");

	}

}


void ViewTodayReservations(void)
{
	ListNode * curr=head;

	while(curr !=NULL)
	{
		if(curr->res_no !=0)
		{
			break;
		}
		curr=curr->next;
	}
   if(curr==NULL)
   {
	   printf("\nThere are no appointments booked yet..!\n");
	   return;
   }
	if(head==NULL)
	{
		printf("\nThere are no appointments booked yet..!\n");
		return;
	}
	while(curr!=NULL)
	{
		if(curr->res_no !=0)
		{
			printf("\n*******************************************************************\n");
			printf("Name : %s  \n",curr->name);
			printf("Id : %d  \n",curr->id);
			printf("Appointment : %s",res_str[curr->res_no]);
			printf("\n*******************************************************************\n");
		}
	    curr=curr->next;
	}
}


void delete_list(void)
{
	if(head==NULL)
	{
		return;
	}
	ListNode * curr=head;
	ListNode * next;
	while(curr!=NULL)
	{
		next=curr->next;
		free(curr);
		curr=next;
	}
	head=NULL;
}










