#include "adjacence.h"

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

	for (i=0; i<strlen(*x)-1; i++) {
		for (j=0; j<strlen(x[i]); j++) {
			isInTrie(trie, (unsigned char*)&x[i][j]);
		}
		printf("----\n");
		trie->nextNode = 0;
	}	
	
	return EXIT_SUCCESS;
}
// Creation du trie 
Trie createTrie(int maxNode) {
	printf("Creation du Trie \n");
	
	Trie trie = (Trie)malloc(sizeof(Trie));
	trie->maxNode = maxNode;	
	trie->nextNode = 0;
    trie->transition = malloc( maxNode * sizeof(List) );
	int l;
	for (l=0; l <= maxNode; l++) {
		trie->transition[l] = malloc(sizeof(List) );
		trie->transition[l]->targetNode = 0;
	}
	trie->finite = (char*) malloc(maxNode+1 * sizeof(char));
	for (l=0; l <= maxNode; l++) {
		trie->finite[l] = ' ';
	}
	
	/* début des insetions */
	int i,j;
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
	/* on insère caractère par caractère */
	List tmp = trie->transition[trie->nextNode];
	int trouve = 0;
	if (tmp->targetNode > 0 && tmp->letter != *w) {
		while (trouve == 0 && tmp->next != NULL) {
			tmp = tmp->next;
			if (tmp->letter == *w) { trouve = 1; }
		}
	}

	if (tmp->targetNode == 0 || tmp->letter != *w) {
		List nouvelleTransition = malloc(sizeof(*nouvelleTransition));
		nouvelleTransition->targetNode = ++noeudCourant;
		nouvelleTransition->letter = *w;
		nouvelleTransition->next = NULL;

		if (tmp->targetNode == 0) {
			trie->transition[trie->nextNode] = nouvelleTransition;
		} else {
			tmp->next = nouvelleTransition;
		}

		trie->nextNode = nouvelleTransition->targetNode;
		printf("insertion du mot %c dans le trie, Noeud Courant : %d\n", (char)*w, noeudCourant);
	} else {
		//printf("--insertion du mot %c dans le trie, Noeud Courant : %d\n", (char)*w, noeudCourant);
		trie->nextNode = trie->transition[trie->nextNode]->targetNode;
	}
}

int isInTrie(Trie trie, unsigned char *w) {
	List tmp = trie->transition[trie->nextNode];

	while (tmp != NULL) {
		if (tmp->letter == *w) {
			printf("Le mot %c\t est dans le tri \n", (char)*w);
			trie->nextNode = tmp->targetNode;
			return 1;
		}
		tmp = tmp->next;
	}
	printf("Le mot %c\t n'est pas dans le tri \n", (char)*w);
	return 0;
}



