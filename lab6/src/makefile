CC=gcc
CFLAGS=-I.

all : server client

server : server.c
	$(CC)  -o server server.c -L. -lmultmod -lpthread $(CFLAGS)

client : client.c
	$(CC) -o client client.c -L. -lmultmod $(CFLAGS)

clean :
	rm -f client server