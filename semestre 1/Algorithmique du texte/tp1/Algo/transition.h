#ifndef TRANSITION_H
#define TRANSITION_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct _trie {
	int maxNode;
	int nextNode;
	int **transition;
	char *finite;
};

typedef struct _trie *Trie;

Trie createTrie(int maxNode);

void insertInTrie(Trie trie, unsigned char *w);

int isInTrie(Trie trie, unsigned char *w);

char* x[] = { "ataa", "attat", "taa" };

int noeudCourant = 0; 
 
 #endif
