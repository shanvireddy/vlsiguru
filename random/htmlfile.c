#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<errno.h>
int main(int argc,char *argv[])
{
	char filename[10];
	FILE *ptr;
	FILE *htmlptr;
	char htmlfile[10];
	int random[10];
	int idx;
	int x;
	int flag;
	int retval;
	
	printf("enter file name:\n");
	scanf("%s",filename);
	
   	strcpy(htmlfile, "randomnumber.html");
	
	htmlptr=fopen(htmlfile,"w");
	
	if (htmlptr == NULL)
   {
      printf("Unable to too open the file %s \n", htmlfile);
      exit(1);
   }
   		fprintf(htmlptr,"<HTML>\n");
   		fprintf(htmlptr,"<H1> the numbers are </H1>\n");
   		
		   ptr=fopen(filename,"r");
	
	if(ptr == NULL)
   {
        fprintf(htmlptr,"<p>the error with file open is %d</p>\n",errno);
        fprintf(htmlptr,"%s\n",strerror(errno));
        fprintf(htmlptr,"</HTML>\n");
        fclose(htmlptr);
        exit(0);
    }	
   
    flag=1;
	while(flag)
	{
		retval=fscanf(ptr,"%d",x);
			if(retval==EOF)
			{
				flag=0;
			}
			else
			{
				random[idx]=x;
				idx++;
			}
	}
		fclose(ptr);a
	fprintf(htmlptr,"%d",random[idx]);
	
   fprintf(htmlptr,"</HTML>\n");
   fclose(htmlptr);
   
}
