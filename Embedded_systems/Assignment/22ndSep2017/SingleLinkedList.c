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
void CreateList(int n)
 {
 	int i;
 	struct node data;
 	struct node *temp;

	for(i=0;i<n;i++)
	{	
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
		printf("The list has been created:\n");
	
 }
 void AddNode()
 {
 	
 }
 void DeleteNode()
 {
 	
 }
 void DisplayList()
 {
 	
 }
 void DeleteList()
 {
 	
 }
 void SearchList()
 {
 	
 }
   
       
    int main()
    {
        int flag ;
        int choice ;
        int n;
        flag = 1 ;
        
        while (flag ==1)
        {
             choice = DisplayMenu() ;
             switch(choice)
             {  case 1 :
                { 
                	printf("eneter no.of node to be created:\n");
                	scanf("%d",&n);
                     CreateList(n) ;
                     break ;
                }
                case 2:
                {
                     AddNode();
                     break ;
                }
                case 3:
                {
                     DeleteNode();
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
                    SearchList();
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
 
 
