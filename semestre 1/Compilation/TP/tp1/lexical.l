%{
#include <stdio.h> 
#include <stdlib.h>
#include <string.h>

typedef struct element element;
struct element{
    char* mot;
    char* type;
	struct element *next;
};

typedef struct liste liste;
struct liste{
    element *premier;
};

liste *ma_liste;

void ajouter(char* ntype, char* chaine);
int analyser(char* chaine);
int trouver(char* chaine);
%}
LETTRE		[a-zA-Zéàè'êù]
MOT			{LETTRE}+
CHAINE	 	[ ]*{MOT}[ ]*
PHRASE		{MOT}([ ]+{MOT}[ ]*)*
TYPE		"verbe"|"pronom"|"nom"|"adj"	

%%
[ ]*{TYPE}[ ]+{PHRASE}		{ analyser(yytext); }
{PHRASE} 					{ trouver(yytext);	}
.							printf("Unrecognized character: %s\n", yytext);
%%

void ajouter(char* ntype, char* chaine) {

	element	*nouvelElement = malloc(sizeof(element));
	nouvelElement->mot = chaine;
	nouvelElement->type = ntype;
	nouvelElement->next = NULL;
	
	if(ma_liste == NULL)
	{
		ma_liste = malloc(sizeof(liste));
		ma_liste->premier = nouvelElement;
	}
	else
	{
		nouvelElement->next = ma_liste->premier;
		ma_liste->premier = nouvelElement;
	}
}
int analyser(char* chaine) {
	char* type = strtok(chaine, " ");
	char* typeDest = malloc(sizeof(*type));
	strcpy(typeDest, type);
	
	chaine = chaine + strlen(type) + 1;
	
	while (chaine[0]!='\0') {
		while(chaine[0]==' ') {
			chaine = chaine+1;
			if (chaine[0] == 0 || chaine[0] == '\0' ) { 
				return 0; 
			}
		}
		char* premierMot = strtok(chaine, " ");
		chaine = chaine + strlen(premierMot)+1;
		char* motDest = malloc(strlen(premierMot)*sizeof(char));
		strcpy(motDest,premierMot);
		ajouter(typeDest, motDest);
	}
	return 1;
}
int trouver(char* chaine)
{
	if (ma_liste == NULL) { 
		printf("Liste vide"); 
		return 0; 
	}
    element *temp = ma_liste->premier;
	int i=0;
	
	while(chaine[0] != '\0')
	{
		while(chaine[0] == ' ') {
			chaine = chaine+1;
		}
		char* premierMot = strtok(chaine, " ");
		chaine = chaine + strlen(premierMot)+1;
		temp = ma_liste->premier;
		int trouve = 0;
		while(temp != NULL) {
			char* mot = temp->mot;
			char* type = temp->type;
			
			int nbChar = 0;
			for(i=0; i<strlen(premierMot); i++) {
				if (mot[i] == premierMot[i] && premierMot != " ") {
					nbChar++;
				}
			} 
			if (nbChar == strlen(premierMot)) { 
				printf("%s : %s\n",mot, type);
				trouve = 1;
			} 
			temp = temp->next;
		}
		if (trouve == 0) {
			printf("%s : non reconnu\n", premierMot);
		}
	}
	
	return 1;
}

int main(int argc,char ** argv)
{
	
	++argv, --argc;
	if (argc>0)
		yyin = fopen(argv[0], "r");
	else
		yyin = stdin;
	yylex();
	return 0;
}
