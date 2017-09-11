/* program to implement linear search */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<errno.h>
int main()
{
	FILE *ptr;       // pointer to a file
	char in_fileName[5];    // holds input file name
	int random_number[1000]; // holds 1000 random numbers
	int search_element;      //number to be searched
	int retval;         // holds value returned by fscanf
	int idx;          // index to random_number array
	int flag;
	int index;      // holds value returned by linear search function
	int x;        // holds random number
	
	idx = 0;
	flag = 1;
	
	printf("enter the inut file name:\n ");
	scanf("%s",in_fileName);
	printf("enter the search element:\n");
	scanf("%d",&search_element);
	
	ptr = fopen(in_fileName,"r");
	
	if(ptr == NULL)
	{
		printf("the error returned is %d\n",errno);
		printf("%s\n",strerror(errno));
		exit(0);
	}
	while(flag)
	{
		retval = fscanf(ptr,"%d",&x);
		if(retval == EOF)
		{
			flag=0;
		}
		else
		random_number[idx] = x;
		idx++;
	
	}
	fclose(ptr);
	
	index=linear_search(array,idx,search_element);
	 if(index == -1)
	{
		printf("Element %d Not Found\n", search_element);
    }
    else
    {
    printf("Element %d Found at Position %d\n", search_element, index + 1);
    }
	
}
/* .....function to do linear search.......*/

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
