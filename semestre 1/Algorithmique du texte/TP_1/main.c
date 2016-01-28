// Inclusions des .h
#include "main.h"
// #include "transition.h"
#include "adjacence.h"

int main(int args, char* argv[])
{
    // TransitionalTrie trie = NULL;
    AdjacenceTrie trie = NULL;
    // MixteTrie trie = NULL;
    int nbNoeuds = 0;
    int i;

    for (i = 0; i < NB_MOTS; ++i) {
        nbNoeuds += strlen(mots[i]);
    }
    nbNoeuds ++;

    printf("\tNombre max de noeuds: %d\n", nbNoeuds);
    printf("\tTaille de l'alphabet: %d\n", TAILLE_ALPHABET);

    if ((trie = createTrie(nbNoeuds, TAILLE_ALPHABET)) == NULL) {
        printf("Error when creating TransitionalTrie struct --\n");
        return EXIT_FAILURE;
    }

    printf("Debut des insertions... \n");
    // On parcours la liste des mots
    for (i = 0; i < NB_MOTS; ++i) {
        printf("Insertion du mot '%s'...\n", mots[i]);
        insertInTrie(trie, mots[i]);
    }

    /* Recherche */
    for (i = 0; i < 5; ++i) {
        if (isInTrie(trie, motsATester[i])) {
            printf("Le mot %s est dans le trie.\n", motsATester[i]);
        } else {
            printf("Le mot %s n\'est pas dans le trie.\n", motsATester[i]);
        }
    }
    return EXIT_SUCCESS;
}