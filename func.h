#ifndef FUNC_H
#define FUNC_H

#include "main.h"

void sig_chld(int signo);
void server_handler(int sockfd);
void client_console_handler(FILE *ft, int sockfd);

#endif
