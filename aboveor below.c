/* program to find how many numbers are there in the array which are above a given number and how many are below a given number*/
#include<stdio.h>

int main()
{
 int size;                      // declaring size of an arrary
 int array[100];               // declaring an array which can hold 100 elements 
 int idx;                     // declaring a variable index of an array 
 int search_element;         // declaring a variable to ear
 int above_Count;           // declaring a variable which has the count of elements above the search element
 int below_Count;          // declaring a variable which has the count of elements below the search element
 
 
 /* ...........Initializing above and below count valuesto zero...........*/
 
 above_Count=0;
 below_Count=0;
 
 /* ........reading  the size of an array from the keyboard........ */
 
 printf("enter the size of an array:\n");
 scanf("%d",&size);
 
 /* reading elements of an array from the keyboard */
 
 printf("enter the elemnts of an array:\n");
 
   for(idx = 0;idx < size;idx++)
   {
 	scanf("%d",&array[idx]);
   } 
 /*....... reading the searching number ........*/
 
   printf("enter a searching element:\n");
   scanf("%d",&search_element);
 
    idx=0;                       // overiding the previous value of the idx to 0
    
    while(idx < size)
   {
	  if(array[idx] >search_element)
	
	      above_Count++;
	  
	   else
	       
	    below_Count++;
	    idx++;
	
   } 
   
    printf("number of elements above the given number are: %d\n",above_Count);
    printf("number of elements below the given number are: %d\n",below_Count);
 
}

