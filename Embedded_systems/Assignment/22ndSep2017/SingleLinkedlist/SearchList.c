/*program to implement single linked list*/

#include<stdio.h>
#include<malloc.h>
#define TRUE 1
#define FALSE 0
int position=0;
int DisplayMenu();

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
		
		printf("enter the  node %d element:\n",i+1);
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
 	
 }
 void DeleteNode()
 {
 	
 }
 void DisplayList()
 {
 	struct node *temp;
	 if(head==NULL) 
	 {
	 	printf("the Linked list is Empty:\n\n");
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
 void DeleteList()
 {
 	
 }
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
        int n;
        int result;
        flag = 1 ;
        
        while (flag ==1)
        {
             choice = DisplayMenu() ;
             switch(choice)
             {  case 1 :
                { 
                	printf("eneter no.of nodes to be created:\n");
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
                    result=SearchList();
                    if(result==TRUE)
                    	printf("the search element is found in the list at node %d\n",position);
					else
						printf("the search element is not found in the list:\n");
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
