#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <sys/wait.h>
#include <signal.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <fcntl.h>


#define PORT "5000"  // the port users will be connecting to
#define MAXDATASIZE 100 // max number of bytes we can get at once
#define BACKLOG 10     // how many pending connections queue will hold


void sigchld_handler(int s)
{
    // waitpid() might overwrite errno, so we save and restore it:
    int saved_errno = errno;

    while(waitpid(-1, NULL, WNOHANG) > 0);

    errno = saved_errno;
}


// get sockaddr, IPv4 or IPv6:
void *get_in_addr(struct sockaddr *sa)
{
    if (sa->sa_family == AF_INET) {
        return &(((struct sockaddr_in*)sa)->sin_addr);
    }
return &(((struct sockaddr_in6*)sa)->sin6_addr);
}


int main(void)
{
    int sockfd, clientToken ;  // listen on sock_fd, new connection on clientToken
    struct addrinfo hints, *servinfo, *p;
    struct sockaddr_storage their_addr; // connector's address information
    socklen_t sin_size;
    struct sigaction sa;
    char message[30];
    int yes=1;
    char s[INET6_ADDRSTRLEN];
    int rv;
    int idx ;
    int flag;
    int retVal ;
    int numbytes ;
    unsigned char rasp[1024];
    FILE *ptr;



    memset(&hints, 0, sizeof hints);
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_flags = AI_PASSIVE; // use my IP

    if ((rv = getaddrinfo(NULL, PORT, &hints, &servinfo)) != 0)
    {
        fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(rv));
        return 1;
    }

    // loop through all the results and bind to the first we can
    for(p = servinfo; p != NULL; p = p->ai_next)
    {
        if ((sockfd = socket(p->ai_family, p->ai_socktype,
                p->ai_protocol)) == -1)
        {
            perror("server: socket");
            continue;
 }

        if (setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &yes,
                sizeof(int)) == -1)
        {
            perror("setsockopt");
            exit(1);
        }

        if (bind(sockfd, p->ai_addr, p->ai_addrlen) == -1)
        {
            close(sockfd);
            perror("server: bind");
            continue;
        }

        break;
    }

    freeaddrinfo(servinfo); // all done with this structure

    if (p == NULL)
    {
        fprintf(stderr, "server: failed to bind\n");
        exit(1);
    }

    retVal = listen(sockfd, BACKLOG);
    if (retVal == -1)
    {
        perror("listen");
        exit(1);
    }

    sa.sa_handler = sigchld_handler; // reap all dead processes
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = SA_RESTART;
    retVal = sigaction(SIGCHLD, &sa, NULL);

    if (retVal == -1)
    {
        perror("sigaction");
        exit(1);
    }

    printf("server: waiting for connections...\n");

    while(1)
    {
       // main accept() loop
        sin_size = sizeof their_addr;
        clientToken = accept(sockfd, (struct sockaddr *)&their_addr, &sin_size);
        if (clientToken == -1)
        {
            perror("accept");
        //    continue;
              break;
        }
        write(clientToken, "HTTP/1.1 200 OK\n", 16); 
		write(clientToken, "Content-length: 46\n", 19); 
		write(clientToken, "Content-Type: text/html\n\n", 25);
		write(clientToken, "Content-Type:image/jpg\n\n,23);
        inet_ntop(their_addr.ss_family,get_in_addr((struct sockaddr *)&their_addr),s, sizeof s);
        printf("server: got connection from %s\n", s);

        retVal = fork();
        if (retVal == 0)
        {
            numbytes = recv(clientToken, message, strlen(message) , 0);//Welcome
            if (numbytes == 0)
            {
                perror("receive failed");
            }
            printf("numbyetes received is :%d\n",numbytes);
            message[numbytes]='\0';
            printf("receivd message from webbrowser :%s\n",message);
            if(strcmp(message,"GET / HTTP/1")==0)
            {
              ptr=fopen("/var/www/html/index.html","w");
               if(ptr==NULL)
               {
                 perror("error with file open:");
               }
               fprintf(ptr,"<html>\n");
               fprintf(ptr,"<body>\n");
               fprintf(ptr,"<h2>Embedded Institute</h2>\n");
               fprintf(ptr,"<p> <a href = https://www.vlsiguru.com/\n>Refer Institute website</a></p>");
               fprintf(ptr,"<p>contactnumber 9086446341</p>");
               fprintf(ptr,"<p> <img src=screen.jpg> width=500 height=377</p>");
               fprintf(ptr,"</body>\n");
               fprintf(ptr,"</html>\n");
               fclose(ptr);
            }
            memset(message,0,strlen(message));
            strcpy(message,"index.html");
            retVal==send(clientToken,message,strlen(message),0);
            if(retVal==-1)
            {
               perror("send failed");
            }
        }
        else if (retVal < 0)
        {
             printf("fork failed \n");
        }
        // The following is in parent code this happens only whe retVal > 0.
        close(clientToken);  // parent doesn't need this
   }
    return 0;
}


