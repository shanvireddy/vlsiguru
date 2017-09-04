#include<stdio.h>

int calmaxpollution(int a[],int size);
int calminpollution(int a[],int size);
int getinut();


int main()
{
	int idx;
	int data1[30];
	int data[10];
	int no_Ofsamples;
	int i;
	int overallmaximum;
	int overallminimum;
	
	i=0;
	while(i<30)
	{
	   no_Ofsamples= getinput();
	       for(idx=0;idx < no_Ofsamples;idx++)
	
		     scanf("%d",&data[idx]);
		
             data1[i]=calmaxpollution(data,no_Ofsamples);
       
             printf("the max pollution in %d th element is:%d\n",i,data1[i]);
             i++;	
	}
    overallmaximum=calmaxpollution(data1,no_Ofsamples);
    printf("the overall max pollution is element is :%d \n",overallmaximum);
    
}

int calminpollution(int b[],int size)
{
	int idx;
	int smallElement;
	
    smallElement=b[0];    /* assigning 0th element of array is the largest of all initially*/
	
		/* loop for finding largest element in an array*/
	
	for (idx=1;idx<size;idx++)
	{
	 	if(b[idx]<smallElement)
     	
	       smallElement=b[idx];
	    				   
	}
	return smallElement;
}

int calmaxpollution(int a[],int size)
{
	int idx;
	int largeElement;
	
    largeElement=a[0];    /* assigning 0th element of array is the largest of all initially*/
	
		/* loop for finding largest element in an array*/
	
	for (idx=1;idx<size;idx++)
	{
	 	if(a[idx]>largeElement)
     	
	       largeElement=a[idx];
	    				   
	}
	return largeElement;		
}
int getinput()
{
	int no_Ofsamples;
	printf("enter the no.of samles:\n");
	scanf("%d",&no_Ofsamples);
	
	printf("enter the atmoshere values:\n");
	return no_Ofsamples;
}
	
	
	
	
