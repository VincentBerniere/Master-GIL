#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int args, char* argv[])
{
	int longueur_texte = 0;
	int longueur_alphabet = 0;

	if (args > 2) {
		longueur_texte = atoi(argv[1]);
		longueur_alphabet = atoi(argv[2]);
	} 

	srand(time(NULL));

	if (args > 2 && longueur_texte > 0 & longueur_alphabet > 0 && longueur_alphabet < 70) {
		genereTexte(longueur_texte, longueur_alphabet);
	} 
	else {
		printf("Arguments : [longueur_texte] [longueur_alphabet]\n");
		printf("Arguments : longueurs > 0 et la longueur de l'alphabet < 70");
	}

	return EXIT_SUCCESS;
}

int genereTexte (int t_texte, int t_alph) {

	/*char nom_fic[256];
	strcpy(nom_fic, "texte-");

	char str_texte[256];
	char str_alph[256];
	sprintf(str_texte, "%d", t_texte);
	sprintf(str_alph, "%d", t_alph);

	// Noms des fichiers textes à générer
	strcat(nom_fic, str_texte);
	strcat(nom_fic, "-");
	strcat(nom_fic, str_alph);
	strcat(nom_fic, ".txt");*/

	// ouverture du fichier en ecrituren 0;
	
	const char charset[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789$. :;,?!";
	char alphabet[t_alph];

    int n;
    for (n = 0; n <= t_alph; n++) {
        int key = rand() % (int) (sizeof charset - 1);
        alphabet[n] = charset[key];
    }

    int m;
    for (m=0; m < t_texte; m++) {
    	int key = rand() % t_alph;
    	printf("%c",alphabet[key]);
    }
 

	return 1;
}
