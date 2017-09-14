/*.......... program for calculate length of string array.............*/

#include<stdio.h>

int calculatestring_length(char ch[]);                   // declaring a function to calculate length of a string array


int main()
{
	int str_length;                                     // declaring a variale which holds the lenth of string
	char string[100];                                   // declaring a string array which can hold maximum 100 characters
	
	printf("enter characters of an array:\n");
	scanf("%s", string);
	
	str_length = calculatestring_length (string);          // calling a funtion to calculate string length
	
    printf("the lenth of character string is: %d\n",str_length);	
	
 }
 
 /*........defining a function to calculate lenth of string in an array*/

int calculatestring_length(char ch[])
	{
	  int str_length;
	  int idx;                // declaring a variable which holds the string length
	  
	  idx=0;                      // initializing index value to 0
	  	
	  scanf("%c",&ch[idx]);       // reading characters into an array called ch[]
	
	   while(ch[idx]!='\0')
       {
 	      str_length++;
 	      idx++;
       } 
      return str_length;           // retuning a integer string lenth to calling function


	}
