/* program to search an element in an array using pointers*/

#include<stdio.h>

int main()
{
	int idx;			//index to for loop
	int no_ofelements;			// max number of elements
	int search_element;			//element to be searched
	int *ptr;					//integer pointer 
	int No_oftimes;				// holds no.of occurance of searched element
	int element;				//holds the element
	
	No_oftimes=0;
	
	printf("enter the number of elements:\n");
	scanf("%d",&no_ofelements);
	printf("enter the elements:\n");

		for(idx = 0;idx < no_ofelements;idx++)
   		{
 			scanf("%d",&element);
 			ptr=&element;
 			ptr++;
   		} 	
 /*....... reading the searching number ........*/
 
   	printf("enter a searching element:\n");
   	scanf("%d",&search_element);
 
    idx=0;                       // overiding the previous value of the idx to 0
    
    while(idx < no_ofelements)
   {
	    if(*(ptr+idx) ==search_element)
	    {
	    	printf("the searched element %d is in an array at %d location\n",search_element,ptr+1);
	        No_oftimes++; 
		}
		idx++;
		
    }
		if(No_oftimes==0)
		{
			printf("the search element is not there in an array:\n");	
		}
		else
		  printf("%d present %d times in an array \n",search_element,No_oftimes);
   
}

