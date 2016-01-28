#ifndef MIXTE_H
#define MIXTE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct _list {
	int targetNode;
	unsigned char letter;
	struct _list *next;
};

typedef struct _list *List;

struct _trie { 
	int maxNode; /* Nombre maximal de noeuds du trie */ 
	int nextNode; /* Indice du prochain noeud disponible */ 
	int *transitionRoot; /* transitions de la racine */ 
	List *transitionOthers; /* transitions des autres noeuds */ 
	char *finite; /* etats terminaux */ 
}; 

typedef struct _trie *Trie;

Trie createTrie(int maxNode);

void insertInTrie(Trie trie, unsigned char *w);

int isInTrie(Trie trie, unsigned char *w);

char* x[] = { "ataa", "attat", "taa" };

int noeudCourant = 0; 
 
 #endif
