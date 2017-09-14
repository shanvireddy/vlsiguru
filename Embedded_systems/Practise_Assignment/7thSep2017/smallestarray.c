/* program to find smallest element in an array */

#include<stdio.h>

 int main()
{
	int idx;                // declaring index of an array 
	int size; 			   //declaring size of an arrary
	int small_element;     // declaring smallest element variable
	int array[100];       //declaring an array which can hold 100 elements 
	
    printf("enter the size of an array\n");
    scanf("%d",&size);
    
	printf("enter the elements of an array:\n");
	
	/* loop for getting array elemnts */
	
	for (idx=0;idx<size;idx++)
	{	
		scanf("%d",&array[idx]);		
	}
	
	small_element=array[0];    /* assigning 0th element of array is the smallest element of all initially*/
	
	/* loop for finding smallest element in an array*/
	
	for (idx=1;idx<size;idx++)
	{
	 	if(array[idx]<small_element)
     	{
	       small_element=array[idx];
	    }				   
	}
	
	printf("the smallest element of an array is:%d\n",small_element);
}
