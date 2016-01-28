#include "transition.h"

int main(int args, char* argv[])
{
	int nbNode = 0;
	int i,j;
	
	for (i=0; i<strlen(*x)-1; i++) {
		for (j=0; j<strlen(x[i]); j++) {
			nbNode++;
		}
	}
	printf("\nNombre de noeuds maximal : %d \n", nbNode);
	
	Trie trie = createTrie(nbNode);
	trie->nextNode = 0;
	noeudCourant = 1;
	for (i=0; i<strlen(*x)-1; i++) {
		for (j=0; j<strlen(x[i]); j++) {
			isInTrie(trie, (unsigned char*)&x[i][j]);
		}
		trie->nextNode = 0;
		printf("----\n");
	}	
	
	return EXIT_SUCCESS;
}

Trie createTrie(int maxNode) {
	printf("Creation du Trie \n");
	
	Trie trie = (Trie)malloc(sizeof(Trie));
	trie->maxNode = maxNode;
	trie->nextNode = 0;
	
    trie->transition = malloc( maxNode * sizeof(int) );
	int l;
    for (l = 0; l < maxNode; l++) {
        trie->transition[l] = malloc( 256 * sizeof(int) );
	}
	trie->finite = (char*) malloc(maxNode+1 * sizeof(char));
	for (l=0; l <= maxNode; l++) {
		trie->finite[l] = ' ';
	}
	
	int i,j;
	for (i=0; i < maxNode;i++) {
		for (j=0; j < 256; j++) {
			trie->transition[i][j] = 0;
		}
	}
	
	for (i=0; i<strlen(*x)-1; i++) {
		for (j=0; j<strlen(x[i]); j++) {
			insertInTrie(trie, (unsigned char*)&x[i][j]);
		}
		trie->finite[noeudCourant] = 'v';
		trie->nextNode = 0;
	}
	printf("Trie construit avec %d noeuds\n\n", noeudCourant);
	return trie;
}

void insertInTrie(Trie trie, unsigned char *w) {
	int castW = *w;
	
	if (trie->transition[trie->nextNode][castW] == 0) {
		noeudCourant++;
		trie->transition[trie->nextNode][castW] = noeudCourant;
		printf("insertion du mot %c dans le trie, Noeud Courant : %d\n", (char)*w, noeudCourant);
		trie->nextNode = noeudCourant;
	} else 
	{
		trie->nextNode++;
	}
}

int isInTrie(Trie trie, unsigned char *w) {
	int castW = *w;
	
	if (trie->transition[trie->nextNode][castW] != 0) {
		printf("Le mot %c\t est dans le tri \n", (char)castW);
		trie->nextNode = trie->transition[trie->nextNode][castW];
	}
	else {
		printf("Le mot %c\t n'est pas dans le tri \n", (char)castW);
	}
	
	return 1;
}



