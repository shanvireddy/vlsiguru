/* program to read an array of 1000 numbers from a file*/

#include<stdio.h>
#include<stdlib.h>
#include<errno.h>
#include<string.h>
int main()
{
	FILE *ptr;       //pointer to the input file
	char in_Filename[5];   //input file name
	int R_number[1000];    //array of 1000 random numbers
	int flag;
	int retval;           // return value by the scanf function
	int idx;              //index to the R_number array
	
	idx=0;
	flag=1;
	
	printf("enter inut file name:\n");
	scanf("%s",in_Filename);
	ptr=fopen(in_Filename,"r");  //opening the file to read
	
	if(ptr==NULL)
	{
		printf("the error returned is:%d\n",errno);
		printf("%s",strerror(errno));
		exit(0);
	}
	while(flag)
	{
		
		retval=fscanf(ptr,"%d",&R_number[idx]);
		if(retval==EOF)
		{
			flag=0;
		}
		else
		 printf("%d\n",R_number[idx]);
		 idx++;
	}
}
