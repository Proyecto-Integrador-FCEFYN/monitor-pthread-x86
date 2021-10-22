CC = gcc
EXEC = ./bin/monitor
CFLAGS = -pthread

all:
	mkdir -p bin
	$(CC) monitor_main.c procesador_petri.c lector_de_matriz.c politica.c monitor.c -o ./bin/politica -g -pthread

main.o:	
	mkdir -p bin
	$(CC) -c main.c -o ./bin/main.o $(CFLAGS)

build: main.o
	$(CC) ./bin/main.o -o $(EXEC) $(CFLAGS)

run:
	./$(EXEC)

clean:
	rm -f $(EXEC) *.o
	rm -f -r bin