#include<stdio.h>
 int main()
{
    int num1,num2;
    printf("enter num1 and num2\n");
    scanf("%d %d",&num1,&num2);
    if(num1%num2==0)

            printf("num1 is divisible by num2");
        else
            printf("num1 is not divisible by num2");

}
