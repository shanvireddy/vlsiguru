/* program to find number of even numbers and number of odd numbers in an array*/

#include <stdio.h>
int main()
{
	int size;                      // declaring size of an arrary
 int array[100];               // declaring an array which can hold 100 elements 
 int idx;                     // declaring a variable index of an array 
 int search_element;         // declaring a variable to ear
 int even_Count;           // declaring a variable which has the count of elements above the search element
 int odd_Count;          // declaring a variable which has the count of elements below the search element
 
 
 /* ...........Initializing above and below count valuesto zero...........*/
 
 even_Count=0;
 odd_Count=0;
 
 /* ........reading  the size of an array from the keyboard........ */
 
 printf("enter the size of an array:\n");
 scanf("%d",&size);
 
 /* reading elements of an array from the keyboard */
 
 printf("enter the elemnts of an array:\n");
 
   for(idx = 0;idx < size;idx++)
   {
 	scanf("%d",&array[idx]);
   } 
   
   idx=0;                       // overiding the previous value of the idx to 0
    
    while(idx < size)
   {
	  if(array[idx] % 2==0)
	
	      even_Count++;
	  
	   else
	       
	    odd_Count++;
	    idx++;
	
   } 
   
    printf("number of even elements are : %d\n",even_Count);
    printf("number of odd elements are : %d\n",odd_Count);
 
}


    
