/* program to do linearsearch and outut is observed in html format*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
main(int argc, char *argv[])
{
   FILE *htmlPtr ;
   char fileName[10];
        FILE *inptr;  //pointer to input file
        int Rnumber[1000]; // holds 1000 random numbers
        char in_Filename[10];//input filename
        int retVal;    //holds value returned by scanf()
        int search_element; //number to be searched
        int flag;
        int idx;  // index to Rnumber array
        int x;    // holds read number from fscanf
        int index;    // holds value returned by binary search function
        idx=0;
        flag = 1;

    printf("enter file name:\n");
	scanf("%s",in_Filename);
	printf("enter the value to be searched is:\n");
	scanf("%d",&search_element);
   strcpy(fileName, "shanvi.html");
   htmlPtr = fopen(fileName, "w");

   if (htmlPtr == NULL)
   {
      printf("Unable to too open the file %s \n", fileName);
      exit(1);
   }

   fprintf(htmlPtr,"<HTML>\n");
   fprintf(htmlPtr,"<H1> Result </H1>\n");
   inptr = fopen(in_Filename,"r");

   if(inptr == NULL)
   {
        fprintf(htmlPtr,"<p>the error with file open is %d</p>\n",errno);
        fprintf(htmlPtr,"%s\n",strerror(errno));
        fprintf(htmlPtr,"</HTML>\n");
        fclose(htmlPtr);
        exit(0);
    }

    while(flag)
    {
                retVal = fscanf(inptr,"%d",&x);

                if(retVal == EOF)
                {
                        flag = 0;
                }
                else
                {
                  Rnumber[idx] = x;
                  idx++;
            }
    }
    fclose(inptr);
    index =linear_search(Rnumber,idx,search_element);
    if(index == -1)
    {
        fprintf(htmlPtr,"<p>Element %d Not Found</P>\n", search_element);
    }
    else
    {
       fprintf(htmlPtr,
               "<p>Element %d Found at Position %d</P>\n",
               search_element, index + 1);
    }
   fprintf(htmlPtr,"</HTML>\n");
   fclose(htmlPtr);
}
int linear_search(int a[],int size,int search_element)
{
	int No_oftimes;
	int idx;
	
	idx = 0;
	
	for(idx = 0;idx<size;idx++)
   {
	    if(a[idx] == search_element)
	    {
	    	return idx;
		}
		
    }
		if(idx == size)
		{
			return -1;	
		}
		
}