#include<stdio.h>
#include<stdlib.h>
#include<errno.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>

int main()
{
   int portid;
   int flag;
   FILE *fp;
   int numbytes;
   char RxBuffer[2*1024];

   portid=open("/dev/ttyACM0",O_RDONLY);
   if(portid==-1)
   {
       perror("port open failed\n");
       exit(0);
   }
   fp=fopen("/var/www/html/index.html","w");
    if(fp==NULL)
    {
        perror("html file open failed:\n");
        exit(0);
    }
   flag=1;
   while(flag)
   {
       numbytes=read(portid,RxBuffer,sizeof(RxBuffer));
       if(numbytes<=0)
       {
          perror("read failed\n");
          flag=0;
       }
       RxBuffer[numbytes]='\0';
       printf("%s\n",RxBuffer);
       fprintf(fp,"<html>\n");
       fprintf(fp,"<body>\n");
       fprintf(fp,"%s",RxBuffer);
       fprintf(fp,"<META HTTP-EQUIV=\"refresh\" CONTENT=\"5\">\n");
       fprintf(fp,"</body>\n");
       fprintf(fp,"</html>\n");
    }
    fclose(fp);
    close(portid);
    return 0;
}


