/* program to implement Double Linked List*/

#include<stdio.h>
#include<malloc.h>
#define TRUE 1
#define FALSE 0
int position=0;	//a global variable which holds the position of node in the list

/* Function Prototyes*/
void CreateList();
void AddNode();
void DeleteNode();
void DisplayForward();
void DisplayBackward();
int DeleteList();
int SearchList();
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
        int result;
        
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
                    if(result==TRUE)
                    {
                    	printf("the searched element is found at node %d\n\n",position+1);
					}
					else
					{
						printf("the searched element is not found in the List\n\n");
					}
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
		   printf("the list is Empty\n\n");
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
   struct node *temp;
   temp=scanPtr;
	while(temp!=NULL)
	{
		printf("%d\n",temp->data);
		temp=temp->left;
	}
	printf("\n........................\n");
	
}
int DeleteList()
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
 		head = scanPtr->right;
 		scanPtr->left=NULL;
		free(scanPtr);
		return scanPtr->data;
		scanPtr = scanPtr->right;
		
	} 
	free(scanPtr);
}
int SearchList()
{
	int element;
	printf("enter element to be searched \n");
	scanf("%d",&element);
	
	if(head==NULL)
	{
		DisplayForward();
	}
	else
	{
		scanPtr=head;
		while(scanPtr!=NULL)
		{
			if(scanPtr->data==element)
			{
				return TRUE;
			
			}
			position++;
			scanPtr=scanPtr->right;	
		}
		return FALSE;
	}
	
}
