CC	= gcc
CFLGS	= -std=c99 -Wall -Wextra -Werror

all: server client_console

server:server.o func.o wrapfunc.o error.o
	$(CC) -o server server.o func.o wrapfunc.o error.o

server.o:server.c main.h func.h wrapfunc.h
	$(CC) -o server.o  -c server.c  $(CFLAGS)

client_console:client_console.o func.o wrapfunc.o error.o
	$(CC) -o client_console  client_console.o func.o wrapfunc.o error.o

client_console.o:client_console.c main.h func.h wrapfunc.h
	$(CC) -o client_console.o  -c client_console.c  $(CFLAGS)

func.o:func.c func.h main.h wrapfunc.h
	$(CC) -o func.o -c func.c  $(CFLAGS)

wrapfunc.o:wrapfunc.c wrapfunc.h main.h
	$(CC) -o wrapfunc.o -c wrapfunc.c   $(CFLAGS)

error.o: error.c main.h
	$(CC) -o error.o -c error.c $(CFLAGS)

clean:
	rm -f *.o server client_console
