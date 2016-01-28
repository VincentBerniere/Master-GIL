#include "main.h"

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
	
	do  {
			
		// Si la lettre de Y = première lettre de X
		if(y[j] == x[0]){
		
			for(i = 0 ; i < tailleX ; i++){
				
				if(x[i] != y[j+i]){
					find = 0;
				}
				
			}
			
			if(find == 1){
				nbX++;
			}
		}
		find = 1;
		j++;

	} while (j > tailleY-tailleX);
	
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

	do  {
		
		// Si la lettre de Y = première lettre de X
		if(y[j] == x[0]){
			
			if(strncmp(x, y+j, tailleX) == 0){
				nbX++;				
			}
		}
		
		j++;

	} while (j < tailleY-tailleX-1);
	
	printf("[NAIF2-SENTINELLE-RAPIDE] Nombre de X dans Y = %d\n\n",nbX-1);
	
}


// algorithme de Morris-Pratt


// algorithme de Knuth-Morris-Pratt


// algorithme de Boyer-Moore


// algorithme de Horspool


// algorithme Quick Search

