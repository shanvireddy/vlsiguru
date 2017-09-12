#include<stdio.h>
 int main()
{
    int x,y,z;
    printf("enter x and y,z\n");
    scanf("%d %d %d",&x,&y,&z);
    if(x<y)
    {
        if(x<z)
            printf("x is smallest number :%d",x);
        else
            printf("z is smallest number:%d",z);
    }
    else
    {
         if(y<=z)
        printf("y is smallest number:%d",y);
        else
            printf("z is smallest number:%d",z);


    }
  return 0;
}
