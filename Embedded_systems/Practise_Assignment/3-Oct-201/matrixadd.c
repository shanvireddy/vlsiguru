/* program to add two matrices*/

#include<stdio.h>
int main()
{
	int row;        // holds the row value of matrix
	int col;       // holds the row value of matrix
	int A[2][2];   // declaring a matrix
	int B[2][2];
	int C[2][2];
	int D[2][2];
	
	row=0;
	col=0;
	
	printf("enter the matrix  A elements:\n\n");
	for(row=0;row<2;row++)
	{
		for(col=0;col<2;col++)
		{
			scanf("%d",&A[row][col]);
		}
	}
	for(row=0;row<2;row++)
	{
		for(col=0;col<2;col++)
		{
			printf("%d ",A[row][col]);
		}
		printf("\n");
	}
	printf("\n");
	
	printf("enter the matrix  B elements:\n\n");
	for(row=0;row<2;row++)
	{
		for(col=0;col<2;col++)
		{
			scanf("%d",&B[row][col]);
		}
	}
	for(row=0;row<2;row++)
	{
		for(col=0;col<2;col++)
		{
			printf("%d ",B[row][col]);
		}
		printf("\n");
	}
	printf("\n");
	for(row=0;row<2;row++)
	{
		for(col=0;col<2;col++)
		{
			C[row][col]= A[row][col]+B[row][col];
			D[row][col]= A[row][col]-B[row][col];
		}
	}
	for(row=0;row<2;row++)
	{
		for(col=0;col<2;col++)
		{
			printf("%d ",C[row][col]);
		}
		printf("\n");
	}
	printf("the matrix D is:\n");
	for(row=0;row<2;row++)
	{
		for(col=0;col<2;col++)
		{
			printf("%d ",D[row][col]);
		}
		printf("\n");
	}
	
	
	
	
	
	
	
}
