#include "main.h"

#define LONGUEUR 500000
#define NB_MOTS 100

int main(int args, char* argv[])
{
	srand(time(NULL));
	char* nom_fic = "generateur";
	int taille_gram[4] = { 2, 4, 20, 70 };

	int i;
	for(i=0; i<4; i++) {
		createGenerateur(nom_fic, taille_gram[i]);
	}

	char const x[] = "ta";
	char const y[] = "tatataa";

	naif1(x,y);
	naif1Rapide(x,y);
	naif1SentinelleRapide(x,y);
	naif2(x,y);
	naif2Rapide(x,y);
	naif2SentinelleRapide(x,y);
	mp(x,y);
	kmp(x,y);

	return EXIT_SUCCESS;
}

int createGenerateur (char* str, int t) {
	char nom_fic[256];
	strcpy(nom_fic, str);

	char taille[10];
	sprintf(taille, "%d", t);
	strcat(nom_fic, taille);
	strcat(nom_fic, ".txt");

	// ouverture du fichier
	FILE *fic = fopen(nom_fic, "w"); // ouvrir en ecriture
	if(fic == NULL){
	  printf("Impossible d'ouvrir le fichier %s\n", nom_fic);
	  return 0;
	}
	printf("... Ouverture du fichier %s\n", nom_fic);
	
	texteAlea(fic, t+1);

	fclose(fic); 

	return 1;
}

int texteAlea(FILE *file, size_t size)
{
    const char charset[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789$. :;,?!";
    char alphabet[size];
    if (size) {
        --size;
        size_t n;
        for (n = 0; n < size; n++) {
            int key = rand() % (int) (sizeof charset - 1);
            alphabet[n] = charset[key];
        }
    }
    int i;
    for (i=0; i<LONGUEUR; i++) {
    	int key = rand() % size;
    	putc(alphabet[key], file);
    }

    return 1;
}


// algorithme naif, avec boucle interne, sans boucle rapide, sans sentinelle
void naif1(char const x[],char const y[]){

	int i,j;
	int tailleY = strlen(y);
	int tailleX = strlen(x);
	int nbX = 0;
	int find = 1;
	
	for(j = 0 ; j <= tailleY-tailleX ; j++ )  {
			
		for(i = 0 ; i < tailleX ; i++){
			
			if(x[i] != y[j+i]){
				find = 0;
			}
			
		}
		
		if(find == 1){
			nbX++;
		}

		find = 1;
			
	}

	printf("[NAIF1] Nombre de X dans Y = %d\n\n",nbX);

}


// algorithme naif, avec boucle interne, avec boucle rapide, sans sentinelle
void naif1Rapide(char const x[],char const y[]){

	int i,j;
	int tailleY = strlen(y);
	int tailleX = strlen(x);
	int nbX = 0;
	int find = 1;
	
	// Parcours du mot Y
	for(j = 0 ; j <= tailleY-tailleX ; j++ )  {
			
		// Si la lettre de Y = première lettre de X
		if(y[j] == x[0]){
			
			// Parcours du mot X
			for(i = 0 ; i < tailleX ; i++){
			
				// Si la lettre n'est pas égale
				if(x[i] != y[j+i]){
					find = 0;
				}
				
			}
			
			if(find == 1){
				nbX++;
			}

			find = 1;
			
		}
			
	}

	printf("[NAIF1-RAPIDE] Nombre de X dans Y = %d\n\n",nbX);

}



// algorithme naif, avec boucle interne, avec boucle rapide, avec sentinelle
void naif1SentinelleRapide(char const x[],char const y[]){

	int i;
	int j = 0;
	int tailleY = strlen(y);
	int tailleX = strlen(x);
	char* yx = malloc(sizeof(y));
	strcpy(yx,y);
	strncat(yx, x, tailleX);
	int nbX = 0;
	int find = 1;
	
	while(1)  {
			
		// Si la lettre de Y = première lettre de X
		if(y[j] == x[0]){
		
			for(i = 0 ; i < tailleX; i++){
				
				if(x[i] != y[j+i]){
					find = 0;
				}
				
			}
			
			if(find == 1){
				nbX++;
				
				if(j > tailleY-tailleX){
					break;
				}
				
			}

		}
		find = 1;
		j++;
	}
	
	printf("[NAIF1-SENTINELLE-RAPIDE] Nombre de X dans Y = %d\n\n",nbX-1);
	
}


// algorithme naif, avec strncmp, sans boucle rapide, sans sentinelle
void naif2(char const x[],char const y[]){

	int j;
	int tailleY = strlen(y);
	int tailleX = strlen(x);
	int nbX = 0;
	
	for(j = 0 ; j <= tailleY-tailleX; j++ )  {
			
		if(strncmp(x, y+j, tailleX) == 0){
			nbX++;
		}
		
	}

	printf("[NAIF2] Nombre de X dans Y = %d\n\n",nbX);

}


// algorithme naif, avec strncmp, avec boucle rapide, sans sentinelle
void naif2Rapide(char const x[],char const y[]){

	int j;
	int tailleY = strlen(y);
	int tailleX = strlen(x);
	int nbX = 0;
	
	for(j = 0 ; j <= tailleY-tailleX; j++)  {
			
		// Si la lettre de Y = première lettre de X
		if(y[j] == x[0]){
			
			if(strncmp(x, y+j, tailleX) == 0){
				nbX++;
			}
			
		}
			
	}

	printf("[NAIF2] Nombre de X dans Y = %d\n\n",nbX);

}


// algorithme naif, avec strncmp, avec boucle rapide, avec sentinelle
void naif2SentinelleRapide(char const x[],char const y[]){

	int j = 0;
	int tailleY = strlen(y);
	int tailleX = strlen(x);
	char* yx = malloc(sizeof(y));
	strcpy(yx, y);
	strncat(yx, x, tailleX);
	int nbX = 0;

	while(1)  {
		
		// Si la lettre de Y = première lettre de X
		if(y[j] == x[0]){
			
			if(strncmp(x, y+j, tailleX) == 0){
				nbX++;
				
				if(j > tailleY-tailleX){
					break;
				}
				
			}
		}
		
		j++;
	}
	
	printf("[NAIF2-SENTINELLE-RAPIDE] Nombre de X dans Y = %d\n\n",nbX-1);
	
}

void preMp(const char *x, int mpNext[]) {
   int i, j;
   int tailleX = strlen(x);

   i = 0;
   j = mpNext[0] = -1;

   while (i < tailleX) {
      while (j > -1 && x[i] != x[j])
         j = mpNext[j];
      mpNext[++i] = ++j;
   }
}


void mp(const char *x, const char *y) {
   int tailleX = strlen(x); 
   int i, j, mpNext[tailleX];	
   int tailleY = strlen(y);
   int nbX = 0;

   /* Preprocessing */
   preMp(x, mpNext);

   /* Searching */
   i = j = 0;
   while (j < tailleY) {
      while (i > -1 && x[i] != y[j])
         i = mpNext[i];
      i++;
      j++;
      if (i >= tailleX) {
         nbX++;
         i = mpNext[i];
      }
   }
   printf("[Morris-Pratt] Nombre de X dans Y = %d\n\n",nbX);
}

// algorithme de Knuth-Morris-Pratt
void preKmp(const char *x, int kmpNext[]) {
   int i, j;
   int tailleX = strlen(x);
   i = 0;
   j = kmpNext[0] = -1;

   while (i < tailleX) {
      while (j > -1 && x[i] != x[j])
         j = kmpNext[j];
      i++;
      j++;
      if (x[i] == x[j])
         kmpNext[i] = kmpNext[j];
      else
         kmpNext[i] = j;
   }
}


void kmp(const char *x, const char *y) {
	int tailleY = strlen(y);
   int tailleX = strlen(x);
   int i, j, kmpNext[tailleX];
   int nbX=0;

   /* Preprocessing */
   preKmp(x, kmpNext);

   /* Searching */
   i = j = 0;
   while (j < tailleY) {
      while (i > -1 && x[i] != y[j])
         i = kmpNext[i];
      i++;
      j++;
      if (i >= tailleX) {
         nbX++;
         i = kmpNext[i];
      }
   }
   printf("[Knuth-Morris-Pratt] Nombre de X dans Y = %d\n\n",nbX);
}


// algorithme de Boyer-Moore


// algorithme de Horspool


// algorithme Quick Search

