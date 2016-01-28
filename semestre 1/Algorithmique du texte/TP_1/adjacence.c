#include "adjacence.h"

AdjacenceTrie createTrie(int maxNode, int tailleAlphabet) {

    AdjacenceTrie atrie = malloc(sizeof(atrie));
    atrie->maxNode = maxNode;
    atrie->nextNode = 1;

    // Initialisation du tableau de listes d'ajacence
    atrie->transition = calloc(maxNode, sizeof(atrie->transition));

    // Initialisation du tableau d'états finaux
    atrie->finite = calloc(maxNode, sizeof(atrie->finite));
    return atrie;
}

void insertInTrie(AdjacenceTrie atrie, char *w) {
    int i = 0;
    int curseur = 0;

    while (i < atrie->maxNode) {
        int currentLetter = (int) w[curseur];

        List node = malloc(sizeof(node));
        if (node == NULL) {
            printf("Erreur lors de l'insertion (malloc de node) !!!\n");
            return;
        }

        // Initialisation des valeurs du noeud
        node->targetNode = atrie->nextNode;
        node->letter     = currentLetter;
        node->next       = NULL;

        if (atrie->transition[i] == NULL) {
            atrie->transition[i] = node;
            i = atrie->nextNode;
        } else {
            List tmpNode = atrie->transition[i];
            while(tmpNode->next != NULL) {
                if (tmpNode->letter == node->letter) {
                    i = tmpNode->targetNode;
                    break;
                }
                tmpNode = tmpNode->next;
            }
            tmpNode->next = node;
        }

        if ()

        atrie->nextNode ++;
    }
}

int isInTrie(AdjacenceTrie atrie, char *w) {
    return 0;
}