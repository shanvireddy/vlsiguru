/* program to find number of vowel in a sentense*/

#include<stdio.h>
int main()
{
	char sentense[150];
	int vowelcount=0;
	int idx=0;
	
	printf("read the sentense from the keyboard:\n");
	scanf("%[^\n]s",&sentense);
	
	   while(sentense[idx]!='\0')
	   {
		   if(sentense[idx]=='a' || sentense[idx]=='e' || sentense[idx]=='i' ||sentense[idx]=='o' ||sentense[idx]=='u' )
		   
		    	vowelcount++;
		    	
		    if(sentense[idx]=='A' ||sentense[idx]=='E' || sentense[idx]=='I' ||sentense[idx]=='O' ||sentense[idx]=='U' )
		    {
				vowelcount++;
		    }
			idx++;	
	    }
     		
	printf("the number of vowels in a sentense is : %d\n",vowelcount);
}
