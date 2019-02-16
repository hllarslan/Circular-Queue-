
CC     = gcc
LINK   = gcc
CFLAGS = -c -Wall

.PHONY: all
all: application

application: main.o CircularQueue.o
	$(LINK) -o application main.o CircularQueue.o
	
main.o: main.c
	$(CC) $(CFLAGS) main.c
	
CircularQueue.o: CircularQueue.h CircularQueue.c 
	$(CC) $(CFLAGS) CircularQueue.c

.PHONY: clean
clean:
	rm *.o application
	

	

