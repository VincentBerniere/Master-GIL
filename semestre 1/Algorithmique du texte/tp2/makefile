# Cibleprincipale
all : executable

executable : main.o
	gcc -o main.exe main.o

main.o : main.c main.h 
	gcc -c main.c

clean : 
	rm main.o