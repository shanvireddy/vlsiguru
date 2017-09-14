/* program to find largest element in an array */

#include<stdio.h>

 int main()
{
	int idx;                   // declaring a variable index of an array 
	int size; 				  // declaring size of an arrary
	int largeElement;		 // declaring largestest element variable
	int array[100];			//declaring an array which can hold 100 elements 
	
    printf("enter the size of an array\n");
    scanf("%d",&size);
    
	printf("enter the elements of an array:\n");
	
	/* loop for getting array elemnts */
	
	for (idx=0;idx<size;idx++)
	{	
		scanf("%d",&array[idx]);		
	}
	
	largeElement=array[0];    /* assigning 0th element of array is the largest of all initially*/
	
		/* loop for finding largest element in an array*/
	
	for (idx=0;idx<size;idx++)
	{
	 	if(largeElement<array[idx+1])
     	{
	       largeElement=array[idx+1];
	    }				   
	}
	
	printf("the largest element of an array is:%d\n",largeElement);
}
