#ifndef MAIN_H
#define MAIN_H

// Liste des includes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Taille maximum de l'alphabet à utiliser
#define TAILLE_ALPHABET 256
#define NB_MOTS 3

// Constantes permettant de simuler les booléens
#define TRUE  1
#define FALSE 0

// Définition des mots de manière globale
char *mots[] = {
    "ataa",
    "attat",
    "taa"
};


char *motsATester[] = {
    "aata",
    "ataa",
    "a",
    "attat",
    "taa"
};

#endif