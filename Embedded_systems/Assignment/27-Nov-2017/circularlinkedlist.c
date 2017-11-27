/*program to implement single linked list and Covert it to Circular Linkd list*/

#include<stdio.h>
#include<malloc.h>

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
		printf("The list has been created:\n\n");
 }
 void ConvertToCircular(struct node *head)
 {
 	struct node *temp;
 	scanPtr=head;
 	/*scaning whether the last node next feild is NUll or not*/
	/* if NULL making the pointer points to the head then list becomes circular*/ 
 	while(scanPtr->next!=NULL)
 	{
 		scanPtr=scanPtr->next;	
	}
	scanPtr->next=head;
	printf("The conversion from linked list to circular has been done\n\n");	
 }
 /* function to dislay the circular list*/
 
void DisplayList()
{
    scanPtr=head;
    while (scanPtr->next != head) {
        printf("%d-> ", scanPtr->data);
        scanPtr = scanPtr->next; 
    }
     
    // Display the last node of circular linked list.
    printf("%d\n", scanPtr->data);
}
void IsCircular()
{
	scanPtr=head;
	while(scanPtr->next!=head && scanPtr->next!=NULL)
	{
	    scanPtr=scanPtr->next;
    }
    if(scanPtr->next==head)
	    printf("the given list is circular\n\n");
	else if(scanPtr->next==NULL)
	   printf("the given list is not circular\n\n");
}

int main()
{
    int flag ;
    int choice ;
   
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
                     ConvertToCircular(head);
                     break ;
                }
                
                case 3:
                {
                    DisplayList() ;
                    break ;
                }
                case 4:
                {
                	IsCircular();
                	break;
				}
                
                case 5:
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
	printf("2.Convert to CircularList\n");
	printf("3.Dislay the list\n");
	printf("4.list circular or not\n");
	printf("5.Exit\n\n");
	printf("......................\n");
	scanf("%d",&choice);
	printf("......................\n");
	return choice;
}
