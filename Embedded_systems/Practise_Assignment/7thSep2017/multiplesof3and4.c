/* program to find numbers which are divisible by 3 and divisible by 4*/

#include<stdio.h>

int main()
{
	signed int number[100]; // declaring an array which can hold 100 elements
	int idx;         // declaring a  index which has the index of an array
	int no_ofelements; // declaring a variable to hold how many elements we need to eneter
	
	idx=0;
	
	printf("enter the size of an array:\n");
	scanf("%d",&no_ofelements);
	
	printf("enter the elements:\n");
	
	while(idx<no_ofelements)
	{
		scanf("%d",&number[idx]);
		
		if((number[idx] %3 ==0) && (number[idx] % 4 ==0))
		{
			printf("the numbers which are multiples of 3 and 4 is : %d \n",number[idx]);
	   }  
			
	idx++;		
	}
		
}
