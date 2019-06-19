OPT=-O3
CFLAGS=-Wall -Wextra
CC=g++ --std=c++11

build: Monty_Hall.o Monty_Hall_Automated.o
	$(CC) Monty_Hall.o -o Monty_Hall $(CFLAGS) $(OPT)
	$(CC) Monty_Hall_Automated.o -o Monty_Hall_Automated $(CFLAGS) $(OPT)
	

Monty_Hall.o: Monty_Hall.cpp
	$(CC) Monty_Hall.cpp -c $(CFLAGS) $(OPT)

Monty_Hall_Automated.o: Monty_Hall_Automated.cpp
	$(CC) Monty_Hall_Automated.cpp -c $(CFLAGS) $(OPT)

clean:
	rm -rf *.o Monty_Hall Monty_Hall_Automated

