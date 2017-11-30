/* Program is to read a paragraph from the file into the linked list and search for a word and replace it with another word */

#include<stdio.h>
#include<malloc.h>
#include<malloc.h>
#include<stdlib.h>
#include<string.h>

void createlist(char *buff);
void DisplayList();
void SearchListReplace();

int DisplayMenu()
{
	int choice;
	printf("enter your choice:\n\n");
	printf("1.Dislay the list\n");
	printf("2.searchlist and Replace\n");
	printf("3.Exit\n\n");
	printf("......................\n");
	scanf("%d",&choice);
	printf("......................\n");
	return choice;
}
typedef struct node 
    {
       char data[30] ;
       struct node *next ;
    } NODE ;
    
/* Declare head of the list as a Global Variable */ 
	struct node  *head ;	// head pointer points to the address of starting node
   	struct node *scanPtr ;
   	
 main()
 {
 	FILE *ptr;       // file pointer
 	char filename[10];
 	int retval;
 	char str[1024];  
 	char *token; 
	 int flag;
	 int choice; 
	  flag=1;   
 	
 	printf("enter the filename\n");
 	scanf("%s",filename);
 	ptr=fopen(filename,"r");
 	
 	if(ptr==NULL)
 	{
 		printf("error with file open\n");	
	}
	
 	while(fgets(str,100,ptr)!=NULL)
 	{
 		fgets(str,100,ptr);
		token=strtok(str," ,\n.");
		while(token!=NULL)
		{
            createlist(token);
			token= strtok(NULL, " ,\n.");
		}
	}
	fclose(ptr);
	while (flag)
        {
             choice = DisplayMenu() ;
             switch(choice)
             {  
                case 1:
                {
                    DisplayList() ;
                    break ;
                }
                case 2:
                {
                    SearchListReplace();
                    break ;
                }
                case 3:
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
 
 void createlist(char *buff)
 {
 	NODE *temp;
 	temp = (NODE*) malloc(sizeof(NODE)); // creation of a new node
 	strcpy(temp->data,buff);
	temp->next=NULL;
 	
	 if(head==NULL)
	 {
		head=temp;
	 }
	else
	{
		scanPtr=head;
		while(scanPtr->next!=NULL)
		{
			scanPtr=scanPtr->next;	 	
		}
		scanPtr->next=temp;
	}
 }
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
	 	printf("................................................................................\n\n");
	    printf("The Linked List is:\n\n");
	 	while(temp!=NULL)
	 	{
			printf("%s => ",temp->data);
			temp=temp->next;
		}
		printf("\n................................................................................\n");
	    printf("The List has been created\n");
	 }
	 
 }
 
/* function to search a node in the linked list*/

 void SearchListReplace()
 {
 	char search_word[30];
 	char replace_word[30];
 	printf("entr the element to be searched :-\n");
 	scanf("%s",search_word);
 	printf("entr the element to be searched :-\n");
 	scanf("%s",replace_word);
 	
 	scanPtr=head;				//assigning starting node address to scanPtr
 	
 	/* seraching for an given element in the linked list till the last node in the list*/	
 	while(scanPtr!=NULL)
 	{
 		if(strcmp(scanPtr->data,search_word)==0)
 		    strcpy(scanPtr->data,replace_word);
		scanPtr=scanPtr->next;
	}
}
