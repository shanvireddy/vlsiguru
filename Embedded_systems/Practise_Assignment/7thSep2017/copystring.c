#include<stdio.h>

int main()
{
 char firstName[10];
 char lastName[10];	
 char name[20];
 int idx;
 int idx1;
 
 idx=0;
 idx1=0;

 

 printf("enter the first name:\n");
 scanf("%s",&firstName);

 printf("enter the second name:\n");
 scanf("%s",&lastName);

 while(firstName[idx]!='\0')
 {
 	name[idx]=firstName[idx];
 	idx++;
 }
 		
 while(lastName[idx1]!='\0')
 {
  name[idx+idx1]=lastName[idx1];
  idx1++;	
 }
	
 printf("the concatenated string is: %s",name);
}
