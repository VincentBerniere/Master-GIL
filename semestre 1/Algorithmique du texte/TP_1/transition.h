#ifndef TRANSITION_H
#define TRANSITION_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// Matrice de transition
struct _transitional_trie {
    int maxNode;        /* Nombre maximal de noeuds du trie    */
    int nextNode;       /* Indice du prochain noeud disponible */
    int **transition;   /* matrice de transition               */
    char *finite;       /* etats terminaux                     */
};
typedef struct _transitional_trie *TransitionalTrie;


/**
 * Permet de créer un trie
 * @param  maxNode nombre maxima de noeuds du trie
 * @return         Une structure représentant le trie.
 */
TransitionalTrie createTrie(int maxNode, int tailleAlphabet);

/**
 * Insère un mot dans un trie
 * @param trie Trie ou le mot doit être insérer
 * @param w    Mot à insérer
 */
void insertInTrie(TransitionalTrie trie, char *w);


/**
 * Teste si un mot est contenu dans un trie
 * @param  trie Trie où effectuer la recherche
 * @param  w    Mot à rechercher
 * @return      Booléen correspondant au résultat de la recherche.
 */
int isInTrie(TransitionalTrie trie, char *w);

#endif