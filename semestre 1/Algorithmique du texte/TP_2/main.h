#ifndef MAIN
#define MAIN

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


#define FILE_LENGTH 500000  // Taille des fichiers
#define NB_FILES 4          // Nombre de fichiers

// Alphabet utilisé pour charger les fichiers
char *alphabet = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789 *$!&?-+";

// Noms des fichiers à générer
char *filepathsText[] = {
    "./seeds/text_2.txt",
    "./seeds/text_4.txt",
    "./seeds/text_20.txt",
    "./seeds/text_70.txt"
};

char *filepathsWords[] = {
    "./seeds/words_2.txt",
    "./seeds/words_4.txt",
    "./seeds/words_20.txt",
    "./seeds/words_70.txt"
};

// Taille de l'alphabet en fonction des fichiers à générer
int sizes[] = { 2, 4, 10, 70 };

int genFileText(const char *filepath, int tailleAlphabet);

#endif