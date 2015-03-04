#ifndef MAIN_H
#define MAIN_H 

#include	<winsock2.h>
#include	<sys/time.h>	/* ??? timeval{} for select() */
#include	<time.h>		/* ??? timespec{} for pselect() */
#include	<arpa/inet.h>	/* ??? inet(3) functions */
#include	<errno.h>
#include	<signal.h>
#include	<stdio.h>
#include	<stdlib.h>
#include	<string.h>
#include	<unistd.h>	// ???
#include	<sys/wait.h>// ???

#define LISTENQ	1024
#define MAXLINE 65536
#define	SA	struct sockaddr

typedef	void	Sigfunc(int);	/* for signal handlers */
void	 err_quit(const char *, ...);
void	 err_sys(const char *, ...);

#endif
