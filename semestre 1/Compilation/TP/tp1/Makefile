# Nom du traducteur LEX utilisé
LEX=flex
#LFLAGS=-D_POSIX_SOURCE -o $@ -DYY_NO_INPUT --nounput
LFLAGS=-w -o$@

# Nom du compilateur C à utiliser
CC=gcc
CFLAGS=-Wall
LDFLAGS=-lfl

%: %.o
	$(CC) -o$@ $< $(LDFLAGS)

# gcc   -std=c99 -pedantic -Wall -c exec.c
%.o: %.c
	$(CC) $(CFLAGS) -c $<


# flex -D_POSIX_SOURCE -o exec.c exec.l
%.c: %.l
	$(LEX) $(LFLAGS) $<

clean:
	-rm *.o *.c