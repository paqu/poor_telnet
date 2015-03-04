#ifndef WRAP_FUNC
#define WRAP_FUNC 

#include "main.h"

char	*Fgets(char *, int, FILE *);
void	 Fputs(char *,  FILE *);
int		 Socket(int, int, int);
void	 Bind(int ,const SA *, socklen_t);
void	 Connect(int, const SA *, socklen_t);
void	 Close(int);
void	 Dup2(int, int);
pid_t	 Fork(void);
void	 Listen(int, int);
void	 Inet_pton(int, const char *, void *);
const char		*Inet_ntop(int, const void *, char *, size_t);
Sigfunc *Signal(int, Sigfunc *);

#endif
