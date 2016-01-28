#include "search.h"

int algoNaifSansBoucleSansSentinelle(const char *path, int fileLength, const char *word)
{
    int i          = 0;
    int counter    = 0; // Sert à valider la reconnaissance du mot.
    int nbReconnus = 0; // Nombre de mots reconnus.

    // Taille du mot à rechercher
    int wordLength = strlen(word);

    // Fichier où effectuer la recherche
    FILE *file = fopen(path, "r");
    if (file == NULL) return -1;

    // On parcours le fichier
    for(i = 0; i < fileLength - strlen(word); ++i) {
        char currentChar = fgetc(file);
        if (currentChar == EOF) return EOF;

        // Si le premier caractère du mot correspond au
        // caractère en cours de lecture, on teste les
        // caractères suivants du mot.
        if (currentChar == word[counter])   counter++;
        else                                counter = 0;

        if (counter == wordLength - 1) {
            nbReconnus++;
            counter = 0;
        }
    }

    fclose(file);

    // On retourne le nombre d'occurences.
    return nbReconnus;
}