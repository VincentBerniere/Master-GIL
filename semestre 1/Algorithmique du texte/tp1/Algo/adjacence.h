#ifndef ADJACENCE_H
#define ADJACENCE_H

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
	int maxNode;      
	int nextNode;    
	List *transition; 
	char *finite;    
};

typedef struct _trie *Trie;

Trie createTrie(int maxNode);

void insertInTrie(Trie trie, unsigned char *w);

int isInTrie(Trie trie, unsigned char *w);

char* x[] = { "ataa", "attat", "taa" };

int noeudCourant = 0; 
 
 #endif
