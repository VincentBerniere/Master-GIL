# Cibleprincipale
all : executable
 
executable : transition.o adjacence.o mixte.o
	gcc -o transition.exe transition.o
	gcc -o adjacence.exe adjacence.o
	gcc -o mixte.exe mixte.o

transition.o : transition.c transition.h
	gcc -c transition.c

adjacence.o : adjacence.c adjacence.h
	gcc -c adjacence.c
	
mixte.o : mixte.c mixte.h
	gcc -c mixte.c

clean :
	rm transition.o
	rm adjacence.o
	rm mixte.o



	

