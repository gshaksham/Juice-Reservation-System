#include<stdlib.h>
#include<string.h>
#include<stdio.h>
#include<conio.h>
struct JUICE_CENTRE
{
    int Order_no;
    char Type_of_Juice[100];
    char Customer_Name[100];
    char customer_no[20];
    char Added_Sugar_Percentage[20];
    struct JUICE_CENTRE *next;


};
typedef struct JUICE_CENTRE node ;
node *head,*new1;
void insert(int Order_no, char* Type_of_Juice, char* Customer_Name,char* customer_no, char * Added_Sugar_Percentage)
{

  new1= (node *) malloc(sizeof(node));
    new1->Order_no = Order_no;
    strcpy(new1->Type_of_Juice, Type_of_Juice);
    strcpy(new1->Customer_Name, Customer_Name);
   strcpy( new1->customer_no, customer_no);
   strcpy( new1->Added_Sugar_Percentage , Added_Sugar_Percentage);
    new1->next = NULL;
    if(head==NULL){
	// if head is NULL
	// set new1 as the new head
	head = new1;
    }
    else{
	// if list is not empty
	// insert new1 in beginning of head
	new1->next = head;
	head = new1;
    }

}
void search(int Order_no)
{
    node * temp = head;
    while(temp!=NULL){
	if(temp->Order_no==Order_no){
	    printf("\t\t\tOrder_no: %d\n", temp->Order_no);
	    printf("\t\t\tType_of_Juice: %s\n", temp->Type_of_Juice);
	    printf("\t\t\tCustomer_Name: %s\n", temp->Customer_Name);
	    printf("\t\t\tCustomer_no : %s\n",temp->customer_no);
	    printf("\t\t\tAdded_Sugar_Percentage: %s\n", temp->Added_Sugar_Percentage);

	    return;
	}
	temp = temp->next;
    }
    printf("\n\t     Juice_Centre with Order_no %d is not found !!!\n", Order_no);
}
void update(int Order_no)
{

    node * temp = head;
    while(temp!=NULL){

	if(temp->Order_no==Order_no){
	    printf("\t\t\tRecord with Order_no %d Found !!!\n", Order_no);
	    printf("\t\t\tEnter new Type_of_Juice: ");
	    scanf("%s", temp->Type_of_Juice);
	    printf("\t\t\tEnter new Customer_Name : ");
	    scanf("%s", temp->Customer_Name);
	    printf("\t\t\tEnter new Number :");
	    scanf("%s",temp->customer_no);
	    printf("\t\t\tEnter new Added_Sugar_Percentage: ");
	    scanf("%s",temp->Added_Sugar_Percentage);

	    printf("\t\t\tUpdation Successful!!!\n");
	    return;
	}
	temp = temp->next;

    }
    printf("\n\t     Juice_Centre with Order_no %d is not found !!!\n", Order_no);

}
void Delete(int Order_no)
{
    node * temp1 = head;
    node * temp2 = head;
    while(temp1!=NULL){

	if(temp1->Order_no==Order_no){

	    printf("\t\t\tRecord with Order_no %d Found !!!\n", Order_no);

	    if(temp1==temp2){
		// this condition will run if
		// the record that we need to delete is the first node
		// of the linked list
		head = head->next;
		free(temp1);
	    }
	    else{
		// temp1 is the node we need to delete
		// temp2 is the node previous to temp1
		temp2->next = temp1->next;
		free(temp1);
	    }

	    printf("\t\t\tRecord Successfully Deleted !!!\n");
	    return;

	}
	temp2 = temp1;
	temp1 = temp1->next;

    }
    printf("\n\t     Juice_Centre with Order_no %d is not found !!!\n", Order_no);

}
void display()
{
if(head!=NULL)
{
    node * temp = head;
    while(temp!=NULL){

	printf("\t\t\tOrder_no: %d\n", temp->Order_no);
	printf("\t\t\tType_of_Juice: %s\n", temp->Type_of_Juice);
	printf("\t\t\tCustomer_Name: %s\n", temp->Customer_Name);
	printf("\t\t\tCustomer_number : %s\n",temp->customer_no);
	printf("\t\t\tAdded_Sugar_Percentage: %s%\n\n", temp->Added_Sugar_Percentage);
	temp = temp->next;
 }
 }
 else
 {
 printf("\t\t\tNo order to show...\n");
 }
    }

int main()
{

    int choice;
    int b,c,d;
    char Type_of_Juice[100];
    char Customer_Name[100];
    char customer_no[20];
    int Order_no=0;
    char u[20],p[20];
    char Added_Sugar_Percentage[20];
    head = NULL;
    clrscr();
    printf("\t\t\t*********************");
    printf("\n\t\t\t|\tLogin       |\n");
    printf("\t\t\t*********************\n");
    printf("\n\tEnter Username :");
    scanf("%s",u);
    printf("\n\tEnter your password :  ");
    scanf("%s",p);
    if(strcmp(u,"SHAKSHAM")==0)
    {
    if(strcmp(p,"12345")==0)
    {
    printf("\n\t!!!! LOGIN SUCCESSFULL !!!\n\n\tPress Enter to continue...\n");
    }
    else
    {
    printf("\n\n\t\t!!! WRONG PASSWORD !!!");
    }
    }
    else
    {
    printf("\n\n\t\t!!! INVALID USERNAME !!!");
    }
    getch();
    if(strcmp(u,"SHAKSHAM")==0&&strcmp(p,"12345")==0)
    {


    do
    {
    clrscr();
     printf("*********************************************\n");
    printf("|                JUICE CORNER               |\n");
    printf("*********************************************\n");
    printf("\t\t\tEnter\n\t\t\t1 to insert order and customer details\n\t\t\t2 to search for order details of customer\n\t\t\t3 to delete order details of customer\n\t\t\t4 to update order details of customer\n\t\t\t5 to display all order  details of customer\n\t\t\t6 Exit\n");

	printf("\nEnter Choice: ");
	scanf("%d", &choice);
	switch (choice)
	{
	    case 1:
	    clrscr();
	       Order_no++;
		printf("\t\t\t Order_no is : %d\n",Order_no);


		printf("\t\t\tEnter Type_of_Juice: ");
		fflush(stdin);
		scanf("%[^\n]s", Type_of_Juice);
		printf("\t\t\tEnter Customer_Name: ");
		fflush(stdin);
		scanf("%[^\n]s", Customer_Name);
		printf("\t\t\tEnter customer_phone_no: ");
		scanf("%s",customer_no);
		printf("\t\t\tHow much Sugar_Percentage you want to add: ");
		scanf("%s", Added_Sugar_Percentage);
		insert(Order_no, Type_of_Juice, Customer_Name,customer_no, Added_Sugar_Percentage);
		getch();
		break;
	    case 2:
	    clrscr();
		printf("\t\t\tEnter Order_no to search: ");
		scanf("%d", &b);
		search(b);
		getch();
		break;
	    case 3:
	    clrscr();
		printf("\t\t\tEnter Order_no to delete: ");
		scanf("%d", &c);
		Delete(c);
		getch();
		break;
	    case 4:
	    clrscr();
		printf("\t\t\tEnter Order_no to update: ");
		scanf("%d", &d);
		update(d);
		getch();
		break;
	    case 6:
	      printf("\t\t\tYou are exitting now\n");
	      goto end;


	    case 5:
	    clrscr();
		display();
		getch();
		break;
		default :
		printf("\t\t\tYou entered the wrong option\n");
		getch();
		break;
	}

    } while (choice <= 6||choice>0);
    end:
    }
    getch();
    return 0;
}
