#include<stdio.h>
int main()
{
    int x,y,z,i=0,k=0;
    printf("enter the sides of a RA traingle:\n");
    scanf("%d %d %d",&x,&y,&z);
    i=z*z;
    k=(x*x)+(y*y);
    if(i==k)
       printf("thease lenths forms RA traingle:");
       else
        printf("thease lenths will not forms RA traingle:");


}



