#include<stdio.h>
int main()
{
    int i;
    printf("even number between 1 to100:\n");
    i=2;
    while(i<100)
    {
        if(i%2==0)
            printf("%d\t",i);
             i=i+2;

    }

}
