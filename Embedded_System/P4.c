/* program to generate 1000 random numbers and write into a file*/

#include<stdio.h>
#include<stdlib.h>
int main()
{

	int number;            // holds random number
	int random_number;    // holds random number
	FILE *ptr;           // pointer to a file
	char outfilename[5]; // holds output file name
	int idx1;           // iteration to first for loop
	int idx2;          // iteration to second for loop
	
	printf("enter the output filename:\n");
	scanf("%s",outfilename);
	
	ptr=fopen(outfilename,"w");
	
	if(ptr==NULL)
	{
		printf("the error while oening file is:%d\n",errno);
		printf("%s",strerror(errno));
		exit(0);
	}
	
	srand(1001);
	printf("The generated random numbers are:\n");
	
	for(idx1=0;idx1<50;idx1++)
	{
		for(idx2=0;idx2<20;idx2++)
		{
		     number=rand();
		     random_number=number/100;
		     printf("%d\n",random_number);
		   	 fprintf(ptr,"%d\n",random_number);
	    }
	}

	fclose(ptr);
}

