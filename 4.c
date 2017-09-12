#include<stdio.h>
int main()
{
    int i,n,N,sum=0;
    float avg;
    printf("enter number of elements\n");
    scanf("%d",&n);
    for (i=0;i<n;i++)
    {
        printf("enter the number");
        scanf("%d",&N);
        sum=sum+N;
    }
    printf("the sum is:%d\n",sum);
    avg=sum/n;
    printf("the average is :%f",avg);
    return 0;
}
