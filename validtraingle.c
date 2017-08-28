#include<stdio.h>
int main()
{
    int x,y,z;
    printf("enter the sides of a traingle:\n");
    scanf("%d %d %d",&x,&y,&z);
    if((x+y>z)&&(x+z>y)&&(y+z>x))
        printf("trainle is valid\n");
    else
        printf("traingle is not valid\n");
}
