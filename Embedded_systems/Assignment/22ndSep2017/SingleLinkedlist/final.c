/*program to implement single linked list*/

#include<stdio.h>
#include<malloc.h>
#define TRUE 1
#define FALSE 0
int position=0;	//a global variable which holds the position of node in the list
/* function prototypes*/

int DisplayMenu();
void CreateList(int n);
void AddNode();
void DeleteNode(int element);
void DisplayList();
void DeleteList();
int SearchList();

typedef struct node 
    {
       int data ;
       struct node *next ;
    } NODE ;
    
/* Declare head of the list as a Global Variable */ 
	struct node  *head ;	// head pointer points to the address of starting node
   	struct node *scanPtr ;
   	
/* Creating a linked list*/ 
void CreateList()
 {
 		int i;
 	struct node data;
 	struct node *temp;
 	
		temp = (NODE*) malloc(sizeof(NODE)); // creation of a new node
		
		printf("the element into node:\n");
		scanf("%d",&temp->data);
	 	temp->next=NULL;
	 	
     	if (head == NULL)
        {	
			head = temp ;	
		}
		else
		{
			scanPtr=head;
			while(scanPtr->next!=NULL)
			{
				scanPtr = scanPtr->next;
			}
				scanPtr -> next = temp;		
		}
	
	}
		printf("The list has been created:\n\n");
 }
void AddNode()
{
 	struct node *temp;
 	temp=(NODE*)malloc(sizeof(NODE));
 	printf("enter the node to add at the begining:\n");
 	scanf("%d",&temp->data);
 	temp->next=NULL;
 	printf("the temp is:%x\n",temp);
 		temp->next=head;
 		head=temp;
}

void DeleteNode(int element)
{
	struct node *temp;
	struct node *prev;
	temp=head;
	
	if(temp==NULL)
		printf("there are no elements to delete:\n");
	/* if the element to delete is found at the beginning(head) of the list*/
	if(temp->data==element)
	{
		head=temp->next;
		free(temp);
	}
	/*scanning for the node to delete*/
	
	while(temp!=NULL && temp->data!=element)
	{
			prev=temp;
			temp=temp->next;
	}
	/* if the element to delete is found somewhere in the list*/	
	if(temp->data==element)
	{
			prev->next=temp->next;
			free(temp);
			printf("the node with %d element is deleted\n",element);
	}
	else
	{
		printf("the node with %d element is not found in the list\n",element);
	}	
}
/*function to display the contents of the linked list*/

 void DisplayList()
 {
 	struct node *temp;
	 if(head==NULL) 
	 {
	 	printf("the Linked list is Empty\n\n");
	 }
	 else
	 {
	 	temp=head;
	 	printf("the Linked list is :\n");
	 	for(temp=head;temp!=NULL;temp=temp->next)
	 	{
			printf("%d ",temp->data);
		}
		printf("\n..............\n");
	 }
	 
 }
 /*function to delete the whole contents of the linked list*/
 
void DeleteList()
{
 	int flag;
 	flag=1;
 	 if(head==NULL) 
	 {
		return;
	 }
	scanPtr=head;
 	while(scanPtr != NULL)
 	{
 		head = scanPtr->next;
		free(scanPtr);
		return scanPtr->data;
		scanPtr = scanPtr->next;
	} 
	free(scanPtr);	
 }
/* function to search a node in the linked list*/

 int SearchList()
 {
 	int search_element;
 	printf("entr the element to be searched :-\n");
 	scanf("%d",&search_element);
 	
 	scanPtr=head;				//assigning starting node address to scanPtr
 	
 	/* seraching for an given element in the linked list till the last node in the list*/	
 	while(scanPtr!=NULL)
 	{
 		position++;
 		if(scanPtr->data==search_element)
 			return TRUE;
		scanPtr=scanPtr->next;
	}
	return FALSE;	
 }
      
int main()
{
    int flag ;
    int choice ;
    int no_ofnodes;
    int element;
    int result;
    flag = 1 ;
        
        while (flag ==1)
        {
             choice = DisplayMenu() ;
             switch(choice)
             {  case 1 :
                { 
                	
                    CreateList() ;
                     break ;
                }
                case 2:
                {
                     AddNode();
                     break ;
                }
                case 3:
                {
                	printf("enter the node to be delete:\n");
                	scanf("%d",&element);
                    DeleteNode(element);
                     break ;
                }
                case 4:
                {
                    DisplayList() ;
                    break ;
                }
                case 5:
                {
                     DeleteList() ; /* travese through the list and remove each element by element */
                     break ;
                }
                case 6:
                {
                    result=SearchList();
                    if(result==TRUE)
                    	printf("the search element is found in the list at node %d\n",position);
					else
						printf("the search element is not found in the list\n");
                    break ;
                }
                case 7:
                {
                    flag = 0 ;
                    break ;
                }
                default:
                {
                   break ;
                }
             }
        }
    }
int DisplayMenu()
{
	int choice;
	printf("enter your choice:\n\n");
	printf("1.Createlist\n");
	printf("2.Addind a node\n");
	printf("3.Delete node\n");
	printf("4.Dislay the list\n");
	printf("5.deletelist\n");
	printf("6.searchlist\n");
	printf("7.Exit\n\n");
	printf("......................\n");
	scanf("%d",&choice);
	printf("......................\n");
	return choice;
}
