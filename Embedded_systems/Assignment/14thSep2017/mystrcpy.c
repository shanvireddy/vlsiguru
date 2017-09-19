/* program to find length of the string and copy string from one to another*/

#include<stdio.h>
#include<string.h>

int mystring_length(char ch[]);
void my_strcpy(char dest[],char src[]);

int main()
{
	char source[50];	//holds source string
	char dest[50];		//holds copied string
	int length;			//holds the length of the string

	printf("enter the string:\n");
	scanf("%s",&source);
	printf("the source string is: %s\n",source);
/* using my_strcpy function*/

	my_strcpy(dest,source);
	printf("destination string by my_strcpy is : %s\n",dest);
	
/* copy string from sorce to destination using build in function*/
	strcpy(dest,source);
	printf("destination string using buildin function is : %s\n",dest);
	
/*	computing length of the string using mystring_ length function*/

	length= mystring_length(source);
	printf("the length of string by own function is: %d\n",length);
	
/*	computing length of the string using build in function strlen() */
	length= strlen(source);
	printf("the length of string using buildin function is: %d\n",length);
	
}
/*..................... function to compute string length................*/
int mystring_length(char ch[])
{
	  
	  int str_length;				//  a variable which holds the string length
	  int idx;                		// index to ch array
	  
	  idx=0;                     
	  	
	  scanf("%c",&ch[idx]);       // reading characters into an array called ch[]
	
	   while(ch[idx++]!='\0')
       {
 	      str_length++;
       } 
      return str_length;           // retuning a integer string length to calling function

}

/* function to copy one string into another*/

void my_strcpy(char dest[],char src[])
{
	int idx=0;
	while(src[idx]!='\0')
	{
	   	dest[idx]=src[idx];
	   	idx++;
	}
	dest[idx]='\0';	
}

