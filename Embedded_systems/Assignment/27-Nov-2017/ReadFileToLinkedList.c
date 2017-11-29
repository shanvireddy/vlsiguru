#include<stdio.h>
#include<malloc.h>
#include<malloc.h>
#include<stdlib.h>
void createlist(char *buff);
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
 	
 	printf("enter the filename\n");
 	scanf("%s",filename);
 	 ptr=fopen(filename,"r");
 	if(ptr==NULL)
 	{
 		printf("error with file open\n");	
	}
	printf("................................................................................\n\n");
	printf("The Linked List is:\n\n");
	
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
	printf("\n................................................................................\n");
	printf("The List has been created\n");
	fclose(ptr);
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
	printf("%s => ",temp->data);
 }
