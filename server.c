#include "main.h"
#include "wrapfunc.h"
#include "func.h"


		
int main(int argc, const char *argv[])
{
	int listenfd,connfd;
	char address[MAXLINE];
	struct sockaddr_in cliaddr,servaddr;
	pid_t childpid;
	socklen_t clilen;

	listenfd = Socket(AF_INET,SOCK_STREAM,0);
	
	memset(&servaddr,'\0',sizeof(servaddr));
	
	servaddr.sin_family = AF_INET;
	servaddr.sin_port   = htons(atoi(argv[1]));
	servaddr.sin_addr.s_addr = htonl(INADDR_ANY);

	Bind(listenfd,(SA *) &servaddr, sizeof(servaddr));

	Listen(listenfd,LISTENQ);

	Signal(SIGCHLD,sig_chld); 

	for ( ; ; ) {
		clilen = sizeof(cliaddr);
		if ( (connfd = accept(listenfd,(SA *) &cliaddr, &clilen)) < 0 ) {
			if (errno == EINTR)
				continue;
			else
				err_sys("accept error");
		}
		printf("connection from %s, port %d \n",
				Inet_ntop(AF_INET,&cliaddr.sin_addr,address,sizeof(address)),
				ntohs(cliaddr.sin_port));
		
		if ( 0 == (childpid = Fork())) {
			Close(listenfd);
			server_handler(connfd);
			exit(0);
		}
		Close(connfd);
	}
}
