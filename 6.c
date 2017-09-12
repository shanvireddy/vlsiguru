#include<stdio.h>
int main()
{
    int i,n,elem,lar,sma;
    int a;

    printf("enter number of elements\n");
    scanf("%d",&elem);
    printf("enter first number:\n");
    scanf("%d",&n);
    lar=n;
    sma=n;
    for (i=0;i<elem-1;i++)
    {
        printf("enter the next number:\n");
        scanf("%d",&n);
        if(n>lar)
        lar=n;
        if(n<sma)
        sma=n;
    }
    printf("the largest number is :%d\n",lar);
    printf("the smallest number is :%d\n",sma);
    printf("do you wanted do more:Y/N if yes press 1 if no press 0\n");
    scanf("%d",&a);
    printf("the pressed key is:%d",a);
    while(a==1)
    {
        printf("enter number of elements\n");
    scanf("%d",&elem);
    printf("enter first number:\n");
    scanf("%d",&n);
    lar=n;
    sma=n;
    for (i=0;i<elem-1;i++)
    {
        printf("enter the next number:\n");
        scanf("%d",&n);
        if(n>lar)
        lar=n;
        if(n<sma)
        sma=n;
    }
    printf("the largest number is :%d\n",lar);
    printf("the smallest number is :%d\n",sma);
    printf("do you wanted do more:Y/N if yes press 1 if no press 0\n");
    scanf("%d",&a);
    printf("the pressed key is:%d",a);
    }

}
