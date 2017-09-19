/* program to create own strtok function*/

#include<stdio.h>
#include<stdlib.h>
char  *mystrtok(char * s, char *delimit);
void main()
{
	char string[100];
	char *p;	// pointer to mystrtok function
	char delimit[20];
	int i;
	int length;
	
	i=0;
	length=0;
	
	printf("Enter the input string \n");
	scanf("%s",&string);   
	printf("Enter the delimiter string \n");
	scanf("%s",&delimit); 

	while(length++ != '\0');
	p = mystrtok(string,delimit);
		
	while(p != NULL)
	{
		printf("%s \n", p);
		p = mystrtok(NULL, delimit);			
	}
}
char  *mystrtok(char * str, char *delimit)
{
	static int position;
	static char *s;	
	int initial;
	int i;
	initial = position;

	if(str!=NULL)
		s = str;
	i = 0;
	while(s[position] != '\0')
	{
		i = 0;	
		while(delimit[i] != '\0')
		{		
			
			if(s[position] == delimit[i])
			{
				s[position] = '\0';
				position = position+1;				
				
				if(s[initial] != '\0')
					return (&s[initial]);
				else
				{
					initial = position;
					position--;
					break;
				}
			}
			i++;
		}
		position++;		
	}
	s[position] = '\0';
	if(s[initial] == '\0')
		return NULL;
	else
		return &s[initial];
}
