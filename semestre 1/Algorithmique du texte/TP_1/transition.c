#include "transition.h"

/**
 * Fonction permettant la création d'une trie.
 * @param  maxNode Nombre maximum de noeuds du trie
 * @return         Pointeur sur la nouvelle structure Trie.
 */
TransitionalTrie createTrie(int maxNode, int tailleAlphabet) {
    int i;
    TransitionalTrie trie = malloc( sizeof(trie) );
    trie->maxNode  = maxNode;
    trie->nextNode = 1;

    // Allocation du tableau de transition
    trie->transition = malloc( maxNode * sizeof(trie->transition) );
    int *sousTableau = calloc( maxNode * tailleAlphabet, sizeof(*sousTableau));

    for (i = 0; i < maxNode; ++i)
        trie->transition[i] = &sousTableau[i*tailleAlphabet];

    // Tableau des etats finaux.
    trie->finite = calloc( maxNode, sizeof(trie->finite) );
    return trie;
}

// Insert le mot w dans le trie
void insertInTrie(TransitionalTrie trie, char *w) {
    int i = 0;
    int curseur = 0;

    // Tant qu'on a pas placé tout les caractères
    while (i < trie->maxNode) {
        int currentLetter = (int) w[curseur];

        if (trie->transition[i][currentLetter] == NULL) {
            trie->transition[i][currentLetter] = trie->nextNode;

            printf("\tInsertion de '%c' indice [%d]->%d\n",
                currentLetter,
                i,
                trie->transition[i][currentLetter]);

            i = trie->nextNode;
            trie->nextNode++;
        } else {
            i = trie->transition[i][currentLetter];
        }

        curseur++;

        if (curseur >= strlen(w)) {
            trie->finite[i] = 't';
            printf("\tFin de l'insertion (etat final [%d])\n", i);
            return;
        }
    }
}

// Regarde si un mot est dans un trie
int isInTrie(TransitionalTrie trie, char *w) {
    int i = 0;
    int curseur = 0;

    while (i < trie->maxNode) {
        int currentLetter = w[curseur];
        if (trie->transition[i][currentLetter] != NULL) {
            i = trie->transition[i][currentLetter];
            curseur++;
        } else {
            if (trie->finite[i] == 't' && curseur == strlen(w)) {
                return 1;
            } else {
                return 0;
            }
        }
    }
    return 0;
}