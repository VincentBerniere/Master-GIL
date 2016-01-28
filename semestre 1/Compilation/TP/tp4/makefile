LEX=flex
YACC=bison
CC=gcc
CFLAGS=-std=c99 -pedantic -Wall
LDFLAGS=-lfl

calc: lex.yy.o calc.tab.o
	$(CC) $+ -o $@ $(LDFLAGS)

lex.yy.c: calc.lex calc.tab.h
	$(LEX) -D_POSIX_SOURCE $<

lex.yy.h: calc.lex
	$(LEX) --header-file=$@ -D_POSIX_SOURCE $<

calc.tab.c calc.tab.h: calc.y lex.yy.h
	$(YACC) $< -d

%.o: %.c
	$(CC) $(CFLAGS) $< -c

clean:
	-rm calc *.o lex.yy.* calc.tab.*