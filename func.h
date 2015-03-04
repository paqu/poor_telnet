#ifndef FUNC_H
#define FUNC_H

#include "main.h"

void sig_chld(int signo);
void welcome_client(const char * address);
void server_handler(int sockfd);
void client_console_handler(FILE *ft, int sockfd);
void show_prompt();

#endif
