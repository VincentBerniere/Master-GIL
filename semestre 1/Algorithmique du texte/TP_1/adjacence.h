#ifndef ADJACENCE_H
#define ADJACENCE_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// Listes d'adjacence
struct _list {
    int targetNode;         // Cible de la transition
    unsigned char letter;   // Etiquette de la transition
    struct _list *next;     // Maillon suivant
};
typedef struct _list *List;

struct _adjacence_trie {
    int maxNode;        // Nombre maximal de noeuds du trie
    int nextNode;       // Indice du prochain noeud disponible
    List *transition;   // listes d'adjacence
    char *finite;       // etats terminaux
};
typedef struct _adjacence_trie *AdjacenceTrie;

/**
 * Permet de créer un trie
 * @param  maxNode nombre maxima de noeuds du trie
 * @return         Une structure représentant le trie.
 */
AdjacenceTrie createTrie(int maxNode, int tailleAlphabet);

/**
 * Insère un mot dans un trie
 * @param trie Trie ou le mot doit être insérer
 * @param w    Mot à insérer
 */
void insertInTrie(AdjacenceTrie atrie, char *w);

/**
 * Teste si un mot est contenu dans un trie
 * @param  trie Trie où effectuer la recherche
 * @param  w    Mot à rechercher
 * @return      Booléen correspondant au résultat de la recherche.
 */
int isInTrie(AdjacenceTrie atrie, char *w);

#endif