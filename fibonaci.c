#include<stdio.h>
int main()
{
    int t1=0,t2=1,nextterm=0,n;
    printf("enter no of terms:\n");
    scanf("%d",&n);
    printf("the fibonacci series is:%d\t%d\t",t1,t2);
    nextterm=t1+t2;
    while(nextterm<=n)
    {
        printf("%d\t",nextterm);
        t1=t2;
        t2=nextterm;
        nextterm=t1+t2;
    }
}
