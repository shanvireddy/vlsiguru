/*To write a program for finding rms values of three phases*/
#include<stdio.h>
#include<math.h>
float rootmean(int a,int b)  // function to find rms
{
    int i=0,x,sum=0;
    int avg;
    float rms;
    while(i<b)
    {
     printf("enter the peakvalue\n");
     scanf("%d",&x);
     sum=sum+(x*x);
     i++;
    }
    //printf("the sum is=%d\n",sum);
    avg=sum/b;
    //printf("the average is=%d\n",avg);
    rms=sqrt(avg);
    return rms;
}
int main()
{
    int phase,n;
    float rmsval,rmsval1,rmsval2;
    printf("enter the phase and no of terms:\n");
    scanf("%d %d",&phase,&n);
    rmsval= rootmean(phase,n);
    printf("the rms value of phase %d is=%f\n",phase,rmsval);
    printf("enter the phase and no of terms:\n");
    scanf("%d %d",&phase,&n);
    rmsval1=rootmean(phase,n);
    printf("the rms value of phase %d is=%f\n",phase,rmsval1);
    printf("enter the phase and no of terms:\n");
    scanf("%d %d",&phase,&n);
    rmsval2=rootmean(phase,n);
    printf("the rms value of phase %d is=%f\n",phase,rmsval1);

}
