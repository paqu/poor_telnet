#include "func.h"
#include "wrapfunc.h"

void welcome_client(const char *address)
{
	printf("\nConnected to %s ...\n",address);
	printf(" Escape character is '^]'\n\n");
}

void show_prompt()
{
	printf("[gg:hh:mm rrrr:mm:dd][adress][path]:");
}

void client_console_handler(FILE *fp, int sockfd)
{
	char sendline[MAXLINE], recvline[MAXLINE];
	char end[] = "__end_message__";
	int n;
	show_prompt();
	while (Fgets(sendline,MAXLINE,fp) != NULL) {
		send(sockfd,sendline,strlen(sendline),0);
		memset(&recvline,'\0',sizeof(recvline));	

		while(  0 < ( n = recv(sockfd,recvline,MAXLINE,0))) { 
			if ( 0 == strncmp(recvline,end,sizeof(end))) {
				printf("\n \n");
				break;
			}
			Fputs(recvline,stdout);
		}
		show_prompt();
	}
}

void sig_chld(int signo)
{
	pid_t pid;
	int stat;

	while ( (pid = waitpid(-1,&stat,WNOHANG)) > 0) 
		printf("child %d terminated \n",pid);
	
	return;
}

void server_handler(int sockfd)
{

	ssize_t n;
	int rval;
	int status;
	char buf[MAXLINE];
	char end[] = "__end_message__";

	Dup2(sockfd,STDOUT_FILENO);
	Dup2(sockfd,STDERR_FILENO);
again:
	while (1) {
		memset(&buf,'\0',sizeof(buf));
		n = recv(sockfd,buf,MAXLINE,0);
		if (n < 0 && errno == EINTR) 
			goto again; 
		else if (n < 0)	
			err_sys("str_eco: read error");
		system(buf);
		send(sockfd,end,sizeof(end),0);
	}
}
