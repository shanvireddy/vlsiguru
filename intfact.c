#include<stdio.h>
int main()
{
    int n,i=1;
        printf("enter the number below 100:");
        scanf("%d",&n);
        while(i<=n)
        {
            if(n%i==0)
            {
              printf("%d\t",i);
            }
            i++;
        }


}
