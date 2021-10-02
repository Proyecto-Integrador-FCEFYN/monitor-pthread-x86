CC = gcc
EXEC = ./bin/monitor
CFLAGS = -pthread

main.o:	
	mkdir bin
	$(CC) -c main.c -o ./bin/main.o $(CFLAGS)

build: main.o
	$(CC) ./bin/main.o -o $(EXEC) $(CFLAGS)

run:
	./$(EXEC)

clean:
	rm -f $(EXEC) *.o
	rm -f -r bin