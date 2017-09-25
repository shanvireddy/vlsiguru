/* program to implement Double Linked List*/

#include<stdio.h>
#include<malloc.h>


/* Function Prototyes*/
void CreateList();
void AddNode();
void DeleteNode();
void DisplayForward();
void DisplayBackward();
void DeleteList();
void SearchList();
int DisplayMenu();

typedef struct node 
    {
       int data ;
       struct node *left ;
       struct node *right ;
    } NODE ;
/* Declare head of the list as a Global Variable */
NODE  *head=NULL ;
NODE  *scanPtr=NULL ;
NODE *last=NULL;   
  
    int main()
    {
        int flag ;
        int choice ;
        
        flag = 1 ;
        
        while (flag ==1)
        {
             choice = DisplayMenu();
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
                     DeleteNode();
                     break ;
                }
                case 4:
                {
                    DisplayForward();
                    break ;
                }
                case 5:
                {
                    DisplayBackward();
                    break ;
                }
                case 6:
                {
                     DeleteList(); /* travese through the list and remove each element by element */
                     break ;
                }
                case 7:
                {
                    SearchList();
                    break ;
                }
                case 8:
                {
                    flag=0;
                    break ;
                }
                default:
                {
                	printf("wrong entry try again\n\n");
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
	printf("4.Dislay the list forward\n");
	printf("5.Dislay the list backward\n");
	printf("6.deletelist\n");
	printf("7.searchlist\n");
	printf("8.Exit\n\n");
	printf("......................\n");
	scanf("%d",&choice);
	printf("......................\n");
	return choice;	
}
void CreateList()
{
	struct node data;
 	struct node *temp;
 	struct node *current;
 	
		temp = (NODE*) malloc(sizeof(NODE)); // creation of a new node
		printf("the element into node:\t");
		scanf("%d",&temp->data);
	 	temp->left=NULL;
	 	temp->right=NULL;	
	 	if(head==NULL)
	 	{
	 		head=temp;	
		}
		else
		{
			scanPtr=head;	
			while(scanPtr->right!=NULL)
			{
				scanPtr=scanPtr->right;
			}
			
			scanPtr->right=temp;
			temp->left=scanPtr;			
		}
		printf("the list has been created\n\n");
}
void AddNode()
{
	
}
void DeleteNode()
{
	
}
void DisplayForward()
{
	struct node *temp;
	   if(head==NULL)
	   {
		   printf("the list is Emty\n");
	    }
	   else
	    {
			temp=head;
			printf("the doubly Linked List is:\n");
	    	while(temp!=NULL)
	    	{
		   		printf("%d ",temp->data);
		   		temp=temp->right;
	    	}
	    printf("\n........................\n");
		}
}
void DisplayBackward()
{
   
	
}
void DeleteList()
{
	
}
void SearchList()
{
	
}
