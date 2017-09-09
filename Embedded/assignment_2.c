#include<stdio.h>
int calmaxtemparature(int a[],int initial,int final);
int calmintemparature(int a[], int initial,int final);
float calculateaverage(int a[],int initial,int final);
int get_temparature( int x );


int main()
{
	int idx;             // index to temparature
	int temparature[20];  // which holds the temparature readings
	int mintemp;          //it holds minimimum temparature
	int maxtemp;          //it holds maximum temparature
    int initial_5minutewindow;  // initial band to 5 minute display
    int final_5minutewindow;    // final band to 5 minute display
    int initial_10minutewindow; // initial band to 10 minute display
    int final_10minutewindow;   // final band to 10 minute display
    int initial_15minutewindow; // initial band to 15 minute display
    int final_15minutewindow;   // final band to 15 minute display
    int currentwindow;          // it always holds initial band of 5 minute display
    float avg;
	
	/* Assigning initial and final band to windows*/
	
	initial_5minutewindow=0;
	final_5minutewindow=4;
	initial_10minutewindow=0;
    final_10minutewindow=9;
    initial_15minutewindow=0;
    final_15minutewindow=14;
    
	
	while(1)
	{
	   currentwindow=initial_5minutewindow;
	   
	   printf("read 5 temparature readings from the keyboard:\n");
	   
	/*....... Displaying  minimum ,maximum and average temarature radings ........*/
	
	
	
	 /*.......... 5 minute window display..........*/
	   
	   while((currentwindow>=initial_5minutewindow) && (currentwindow<=final_5minutewindow))
	   {
	   	    temparature[currentwindow]=get_temparature(currentwindow);
	   	    currentwindow++;
	   }
	   
	   	mintemp= calmintemparature(temparature,initial_5minutewindow,final_5minutewindow);
		maxtemp= calmaxtemparature(temparature,initial_5minutewindow,final_5minutewindow);
	   	avg= calculateaverage(temparature,initial_5minutewindow,final_5minutewindow);
	   	initial_5minutewindow+=5;
	   	final_5minutewindow+=5;
	   	    
        printf("the 5 minute window dislay:\n");
	    printf("minimum temparature: %d\n",mintemp);
	    printf("maximum temparature: %d\n",maxtemp);
	    printf("average temparature: %f\n",avg);
	    
	    /*.......... 10 minute window display..........*/
	    
	    if((final_5minutewindow>9) && ((final_5minutewindow+1)%15==0 ))
	    {
	        mintemp= calmintemparature(temparature,initial_10minutewindow,final_10minutewindow);
			maxtemp= calmaxtemparature(temparature,initial_10minutewindow,final_10minutewindow);
	   	    avg= calculateaverage(temparature,initial_10minutewindow,final_10minutewindow);
	   	    
			initial_10minutewindow+=10;
	   	    final_10minutewindow+=10;
	   	    
	   	    printf("the 10 minute window dislay:\n");
			printf("minimum temparature: %d\n",mintemp);
	        printf("maximum temparature: %d\n",maxtemp);
	        printf("average temparature: %f\n",avg);	
		}
		
		
		 /*.......... 15 minute window display..........*/
		
		if((final_5minutewindow>9) && ((final_5minutewindow+1)%20==0 ))
	    {
	        mintemp= calmintemparature(temparature,initial_15minutewindow,final_15minutewindow);
			maxtemp= calmaxtemparature(temparature,initial_15minutewindow,final_15minutewindow);
	   	    avg= calculateaverage(temparature,initial_15minutewindow,final_15minutewindow);
	   	    
		    initial_15minutewindow+=15;
	   	    final_15minutewindow+=15;
	   	    
	   	    printf("the 15 minute window display \n");
			printf("minimum temparature: %d\n",mintemp);
	        printf("maximum temparature: %d\n",maxtemp);
	        printf("average temparature: %f\n",avg);	
		}
		
		
    }
	
}

/*............reading  temparature values.................*/

int get_temparature( int x )
{
	int reading;
	scanf("%d",&reading);
	return reading;
}

/*............calculating minimum temparature.................*/

int calmintemparature(int a[], int initial,int final)
{
	int idx;
	int smallElement;
	  smallElement=a[initial];
	
	idx=initial;
	
	while(idx >= initial && idx < final)
	{
	 	if(smallElement>=a[idx+1]  )
     	{
	       smallElement = a[idx+1];
	    }
	    idx++;				   
	}
	return smallElement;
 
}
/*............calculating maximum temparature.................*/

int calmaxtemparature(int a[],int initial,int final)
{
	int idx;
	int largeElement;
	
	idx=initial;
	largeElement=a[idx];    
	
	while((idx>=initial) && (idx<= final))
	{
	 	if(a[idx+1]>largeElement)
     	{
	       largeElement=a[idx+1];
	    }
	    idx++;
	    				   
	}
	return largeElement;		
}
/*............calculating average temparature.................*/

float calculateaverage(int a[],int initial,int final)
{

    float sum;
    float avg;
    int idx;
    
	idx=initial;
	sum=0;
    
		while(idx >= initial && idx <= final)
	    {

	         sum+=a[idx];
			 idx++;   
	    }	
	 
	avg=sum/(final-initial+1);	
	return avg;		
	
}
