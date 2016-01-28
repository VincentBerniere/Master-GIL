#include "main.h"
#include "search.h"

int main(int argc, char const *argv[])
{
    int i = 0;

    srand(time(NULL));

    for (i = 0; i < NB_FILES; ++i) {
        char *filepath = filepathsText[i];
        if (filepath != NULL) {
            if (genFileText(filepath, (int)sizes[i]) < 0) {
                printf("-- FATAL -- Erreur lors de la génération du fichier [%s]\n", filepath);
                exit(EXIT_FAILURE);
            }
        }
    }

    // Lecture et recherche dans les fichiers
    char *word = "ba";
    int occurrences = algoNaifSansBoucleSansSentinelle("./seeds/test.txt", 6, word);
    printf("Trouves %d occurrences du mot '%s'\n", occurrences, word);

    printf("Done.\n");

    return EXIT_SUCCESS;
}

int genFileText(const char *filepath, int tailleAlphabet)
{
    int i = 0;

    FILE *file = fopen(filepath, "w");
    if (file == NULL) return -1;

    printf("Début de l'insertion du texte (alphabet de taille [%d]) ... ", tailleAlphabet);
    for(i = 0; i < FILE_LENGTH; ++i) {
        int letter = alphabet[rand() % tailleAlphabet];
        fputc(letter, file);
    }
    printf("Done.\n");

    fclose(file);
    return 0;
}
/*
int genFileWords(const char *filepath, int tailleAlphabet, int longueurMots)
{
    int i = 0;

    FILE *file = fopen(filepath, "w");
    if (file == NULL) return -1;

    printf("Début de l'insertion des mots (alphabet de taille [%d]) ...\n", tailleAlphabet);
    for (i = 0; i < FILE_LENGTH; ++i) {

    }

    return 0;
}
*/