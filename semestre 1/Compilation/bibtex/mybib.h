#ifndef MY_BIB_H
#define MY_BIB_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void generateBib(char *cite);
void generateTab(char *cite);
void searchBibliography(char* text);
void checkKey(char* key);
void checkType(char* type, char* text);
void upperCase(char *chaine);
void deleteChar(char *str, char garbage);
void doublon(char* text);
void verifDoublon(FILE *file);

char** cites;
char** keys;
char* bibliography;
char* type;
int nbCite = 0, nbKey = 0, nbDoublon = 0;

typedef struct Doublon Doublon;
typedef struct Doublons Doublons;
struct Doublon
{
	char* type;
    char* title;
    char* author;
    char* year;
};
struct Doublons 
{
	Doublon *tab_doublons;
};
struct Doublons doublons;

#endif
