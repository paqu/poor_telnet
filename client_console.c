/*
 * client_console application for WINDOWS system 
 */

#include "main.h"
#include "func.h"
#include "wrapfunc.h"


int main(int argc, const char *argv[])
{
	SOCKET sockfd;
	WORD WRequiredVersion;
	WSADATA WData;

	struct sockaddr_in servaddr;
	
	if (argc != 3)
		err_quit("usage: tcpcli <IPaddress> <Port>");

	/* initialize winsock */
	WRequiredVersion = MAKEWORD(2,0);
	if (WSAStartup(WRequiredVersion, &WData) != 0) {
		fprintf(stderr,"WSAStartup failed !");
		exit(1);
	}

	sockfd = Socket(AF_INET, SOCK_STREAM,0);

	memset(&servaddr,'\0',sizeof(servaddr));
	servaddr.sin_family = AF_INET;
	servaddr.sin_port   = htons(atoi(argv[2]));
	Inet_pton(AF_INET,argv[1], &servaddr.sin_addr);

	Connect(sockfd, (SA *) &servaddr,sizeof(servaddr));

	welcome_client(argv[1]);
	client_console_handler(stdin,sockfd);

	/* terminate use of the winsock */
	WSACleanup();
	exit(0);
}
