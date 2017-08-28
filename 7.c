#include<stdio.h>
#include<conio.h>
int main()
{
    int g,x,y;
    int sum1=0,sum2,sum3,res;
    printf("guess any no of ur choice:\n");
    scanf("%d",&g);
     printf("enter x:\n");
    scanf("%d",&x);
    printf(" enter y:\n");
    scanf("%d",&y);
    printf("add x to the guessed no:\n");
    sum1=sum1+x+g;
    //printf("sum1 is:%d",sum1);
    printf("add  y to the resultant:\n");
    sum2=sum1+y;
    //printf("sum2 is:%d",sum2);
    printf("subtract the guessed number from sum2:\n");
    sum3=sum2-g;
    //printf("sum3 is:%d",sum3);
    printf("add number 2 to the result\n");
    res=sum3+2;
    //printf("result is:%d",res);
    printf("the relust of the calculation is:%d\n",x+y+2);


}
