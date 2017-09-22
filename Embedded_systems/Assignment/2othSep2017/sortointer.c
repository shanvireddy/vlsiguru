/* program to sort array of integer elements using ointers*/

#include<stdio.h>
int main()
{
	int *ptr;		//pointer to array elements
	int no_ofelements;	//no.of elements to be enetered
	int i;	//index to outer loop
	int j;	// index to inner loo
	int temp;	//temparary variable
	int element[10];	//
	
	printf("enter the number of elements:\n");
	scanf("%d",&no_ofelements);

	ptr=element;
	
	printf("enter array elements:\n");
	
	for(i=0;i<no_ofelements;i++)
	{
		
		scanf("%d",ptr+i);
	
	}
	printf("...........The elements before sorting..........\n\n");
	
	for(i=0;i<no_ofelements;i++)
		{
				printf("%d\n",*(ptr+i));
					
		}
			
	for(i=0;i<no_ofelements;i++)
		{
			for(j=i+1;j<no_ofelements;j++)
			{
				if(*(ptr+i) > *(ptr+j))
				{
					temp = *(ptr+i);
					*(ptr+i) = *(ptr+j);
					*(ptr+j) = temp;
				}
			}
		}
		printf(".............The elements after sorting.........\n\n");
		for(i=0;i<no_ofelements;i++)
		{
				printf("%d\n",*(ptr+i));	
		}
}
