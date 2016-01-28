/**
 * Fonction permettant la création d'une trie.
 * @param  maxNode Nombre maximum de noeuds du trie
 * @return         Pointeur sur la nouvelle structure Trie.
 */
Trie createTrie(int maxNode) {
    // Allocation de la structure Trie
    Trie trie = (Trie)malloc(sizeof(Trie));
    trie->maxNode  = maxNode;
    trie->nextNode = 0; // Temporaire

    // Allocation du tableau de transition
    trie->transition = malloc(maxNode*sizeof(int));
    int i;
    for (i = 0; i < maxNode; ++i) {
        // Pour chaque ligne du tableau, on crée un sous-tableau de TAILLE
        trie->transition[i] = malloc(TAILLE_ALPHABET*sizeof(int));
    }

    // Etats finaux.
    trie->finite = NULL;

    return trie;
}

void insertInTrie(Trie trie, unsigned char *w) {

}

int isInTrie(Trie trie, unsigned char *w) {
    return 0;
}