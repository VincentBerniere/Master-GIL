# definition du compilateur
CC = gcc
# definition des options de compilation pour obtenir un fichier .o
PRODUCTFLAGS = -Wall -c -O3
# definition des options de compilation pour obtenir un fichier .do
DEBUGFLAGS = -c -g -O3

# Fichier executable prod
prod: search.o main.o
	$(CC) -o exo1 search.o main.o
main.o: main.c search.h
	$(CC) $(PRODUCTFLAGS) main.c
search.o: search.c  search.h
	$(CC) $(PRODUCTFLAGS)  search.c