#ifndef MIXTE_H
#define MIXTE_H

// Mixte
struct _trie {
    int   maxNode;
    int   nextNode;
    int  *transitionRoot;
    List *transitionOthers;
    char *finite;
};

/**
 * Permet de créer un trie
 * @param  maxNode nombre maxima de noeuds du trie
 * @return         Une structure représentant le trie.
 */
Trie createTrie(int maxNode);

/**
 * Insère un mot dans un trie
 * @param trie Trie ou le mot doit être insérer
 * @param w    Mot à insérer
 */
void insertInTrie(Trie trie, unsigned char *w);

/**
 * Teste si un mot est contenu dans un trie
 * @param  trie Trie où effectuer la recherche
 * @param  w    Mot à rechercher
 * @return      Booléen correspondant au résultat de la recherche.
 */
int isInTrie(Trie trie, unsigned char *w);

#endif