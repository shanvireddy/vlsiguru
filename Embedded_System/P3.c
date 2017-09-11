#include<stdio.h>
#include<stdlib.h>
#include<errno.h>
#include<string.h>
int Binary_search(int a[],int size,int search_element);

int main()
{
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
	
	printf("enter the input file name:\n");
	scanf("%s",in_Filename);
		
	inptr = fopen(in_Filename,"r");
	
	if(inptr == NULL)
	{
		printf("the error with file open is %d\n",errno);
		printf("%s\n",strerror(errno));
		exit(0);		
	}
	printf("enter search element \n");
	scanf("%d",&search_element);
	
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
	index = Binary_search(Rnumber,idx,search_element);
	if(index == -1)
	{
		printf("Element %d Not Found\n", search_element);
    }
    else
    {
    printf("Element %d Found at Position %d\n", search_element, index + 1);
    }
}
/*........function for binary search........*/

int Binary_search(int a[],int size,int search_element)
    {
    	int low_bound;    // lower bound to array
    	int upper_bound; // holds maximum size of array
    	int mid_bound; 
		 
    	low_bound = 0;
    	upper_bound = size-1;
    	
    	 while(low_bound < upper_bound)
		{	
			mid_bound = (low_bound + upper_bound) / 2;
		
			if(a[mid_bound] < search_element)
				low_bound = mid_bound + 1;	
	
			else if(a[mid_bound] > search_element)

				upper_bound = mid_bound - 1;
			
			else
			
			return mid_bound;
		}
		
		return -1;
		
	}
