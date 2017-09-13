/* program to read an array of 1000 numbers from a file and print the output in html file*/

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
	int idx; 
	char htmlfilename[10];
	FILE *htmlPtr;             //index to the R_number array
	
	idx=0;
	flag=1;
	
	printf("enter inut file name:\n");
	scanf("%s",in_Filename);
	ptr=fopen(in_Filename,"r");  //opening the file to read
	strcpy(htmlfilename, "shanvi.html");
    htmlPtr = fopen(htmlfilename, "w");

   if (htmlPtr == NULL)
   {
      printf("Unable to open the file %s \n", htmlfilename);
      exit(1);
   }

   fprintf(htmlPtr,"<HTML>\n");
   
   fprintf(htmlPtr,"<H1> the random numbers are </H1>\n");
   ptr = fopen(in_Filename,"r");

   if(ptr == NULL)
   {
        fprintf(htmlPtr,"<p>the error with file open is %d</p>\n",errno);
        fprintf(htmlPtr,"%s\n",strerror(errno));
        fprintf(htmlPtr,"</HTML>\n");
        fclose(htmlPtr);
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
		 fprintf(htmlPtr,"|%d\n",R_number[idx]);
		 idx++;
	}
	fclose(ptr);
	//fprintf(htmlPtr,"<p>Elements: %s </P>\n", R_number);
	fprintf(htmlPtr,"</HTML>\n");
    fclose(htmlPtr);
}
