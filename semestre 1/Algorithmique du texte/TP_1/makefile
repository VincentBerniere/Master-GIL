# definition du compilateur
CC = gcc
# definition des options de compilation pour obtenir un fichier .o
PRODUCTFLAGS = -Wall -c -O3
# definition des options de compilation pour obtenir un fichier .do
DEBUGFLAGS = -c -g -O3

# Fichier executable prod
prod: adjacence.o main.o
	$(CC) -o exo1 adjacence.o main.o
main.o: main.c adjacence.h
	$(CC) $(PRODUCTFLAGS) main.c
adjacence.o: adjacence.c  adjacence.h
	$(CC) $(PRODUCTFLAGS)  adjacence.c