/* program to generate 1000 random numbers and write into a html file*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{

	FILE *htmlptr;
	char htmlfilename[10];
	int number;            // holds random number
	int random_number;    // holds random number
	FILE *ptr;           // pointer to a file
	char outfilename[5]; // holds output file name
	int idx1;           // iteration to first for loop
	int idx2;
	int n;          // iteration to second for loop
	
	//printf("enter the output filename:\n");
	//scanf("%s",outfilename);
	strcpy(htmlfilename,"shanvi.html");
	htmlptr=fopen(htmlfilename,"w");
	
	
	ptr=fopen(outfilename,"w");
	
	if(htmlptr==NULL)
	{
		printf("Unable to open the file %s \n", htmlfilename);
        exit(1);
	}
	
	fprintf(htmlptr,"<HTML>\n");
    fprintf(htmlptr,"<H1> the random numbers are </H1>\n");
	
	srand(1002);
	//printf("The generated random numbers are:\n");
	n=1;
	
	for(idx1=0;idx1<50;idx1++)
	{
		for(idx2=0;idx2<20;idx2++)
		{
		     number=rand();
		     random_number=number/100;
		     //printf("%d\n",random_number);
		   	 fprintf(htmlptr,"<p>%d. the random number is: %d</p>",n,random_number);
		   	 n++;
	    }
	}

	fclose(ptr);
	fprintf(htmlptr,"</HTML>\n");
    fclose(htmlptr);
}
