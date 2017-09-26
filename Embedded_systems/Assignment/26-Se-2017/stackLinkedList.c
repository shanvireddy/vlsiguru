/* Program to Implement stack using Single Linked List*/

#include<stdio.h>
#include<malloc.h>

typedef struct node
{
	int data;
	struct node *next;
	
}NODE;
/* Declare top of the stack as a Global Variable */ 
struct node *top=NULL;   //top pointer points to the address of starting node    
int DisplayMenu()
{
	int choice;
	printf("enter the choice:\n\n");
	printf("1.Push\n");
	printf("2.Pop\n");
	printf("3.Display\n");
	printf("4.exit\n");
	printf("\n..................\n");
	scanf("%d",&choice);
	printf("..................\n");
	return choice;
}
void PushNode()
{
	struct node *temp;
	struct node *scanPtr;
	/*creating a new node*/
	temp=(NODE*)malloc(sizeof(NODE));
	printf("enter the node to add at the begining:\n");
 	scanf("%d",&temp->data);
	temp->next=NULL;
	if(top==NULL)
	{
		top=temp;
		return;
	}
	else
	{
		temp->next=top;
 		top=temp;
	}
	
}
void PopNode()
{
	
}
void DisplayList()
{
	struct node *temp;
	if(top==NULL)
	{
		printf("the Stack is Empty\n");
	}
	else
	{
		temp=top;
		printf("the stack is:\n");
		while(temp!=NULL)
		{
			printf("%d\n",temp->data);
			temp=temp->next;
		}
		printf("..................\n");
	}
}
int main()
{
	int choice;
	int flag;
	flag=1;
	while(flag)
	{
		choice=DisplayMenu();
		switch(choice)
		{
			case 1:
				{
					PushNode();
					break;
				}
			case 2:
				{
					PopNode();
					break;
				}
			case 3:
				{
					DisplayList();
					break;
				}
			case 4:
				{
					flag=0;
					break;
				}
			default:
				{
					printf("Wrong entry try again\n\n");
					break;
				}
		}
	}
}

