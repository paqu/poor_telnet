#include "main.h"
#include "func.h"
#include "wrapfunc.h"


int main(int argc, const char *argv[])
{
	int sockfd;
	struct sockaddr_in servaddr;
	
	if (argc != 3)
		err_quit("usage: tcpcli <IPaddress> <Port>");

	sockfd = Socket(AF_INET, SOCK_STREAM,0);

	memset(&servaddr,'\0',sizeof(servaddr));
	servaddr.sin_family = AF_INET;
	servaddr.sin_port   = htons(atoi(argv[2]));
	Inet_pton(AF_INET,argv[1], &servaddr.sin_addr);

	Connect(sockfd, (SA *) &servaddr,sizeof(servaddr));

	welcome_client(argv[1]);
	client_console_handler(stdin,sockfd);

	exit(0);
}
