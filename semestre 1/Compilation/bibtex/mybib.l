%{

#include "mybib.h"

%}

BIBLIOGRAPHIE \\bibliography\{[A-Za-z]+\}
CITE [a-zA-Z]+:[0-9]+:?[0-9]*
TEXT [éè:'\-0-9.A-Z\wa-z,\{\\\"\$\^ \}]*
ENTREE @[A-Za-z]+\{{CITE},({TYPE}?[,]*[\n\t ]*)*\}
TYPE [ \n\t]*[a-zA-Z]*[ \t]*=[ \t]*[a-zA-Z]*?(\{{TEXT}\})
DOUBLON (type|author|year|title)[ \t]*=[ \t]*[a-zA-Z]*?(\{{TEXT}\})

%s B_OPTION
%s B_OPTION_BIBLIO
%s B_OPTION_BIBTEX
%s C_OPTION
%s T_OPTION
%s U_OPTION
%%
					
<B_OPTION>\\cite\{{CITE}\}  			{ generateTab(yytext); }
<B_OPTION_BIBLIO>{BIBLIOGRAPHIE}		{ searchBibliography(yytext); }	
<B_OPTION_BIBTEX>{ENTREE}  				{ generateBib(yytext); }
<C_OPTION>{CITE}						{ checkKey(yytext); }
<T_OPTION>{TYPE}						{ checkType(type,yytext); }
<U_OPTION>{DOUBLON}						{ doublon(yytext); }
[\t\n\r ]+								;
.										;

%%

int main(int argc, char * argv[]) {

	if (argc == 1) {
    	return -1;
	}

  	int option;

	while ((option = getopt (argc, argv, "b:c:e:k:s:t:u:o:")) != -1) {
    	switch (option) {
     
			case 'b':
				cites = (char**) malloc(255 * sizeof(char*));

				yyin = fopen(argv[2], "r");;
				BEGIN(B_OPTION);
				yylex();
				fclose(yyin);

				yyin = fopen(argv[2], "r");
				BEGIN(B_OPTION_BIBLIO);
				yylex();
				fclose(yyin);

				FILE *mybib = fopen("mybib.bib", "w");
				fclose(mybib);
 
				yyin = fopen(bibliography, "r");
				BEGIN(B_OPTION_BIBTEX);
				yylex();
				fclose(yyin);
				free(cites);
				
				break;

	    	case 'c':
	    		keys = (char**) malloc(255 * sizeof(char*));
	    		
	    		yyin = fopen(argv[2], "r");
				BEGIN(C_OPTION);
				yylex();
				fclose(yyin);
				free(keys);
				
	       		break;

			case 'e':
				break;

			case 'k':
				break;

			case 's':
				break;

			case 't':
				type = (char*) malloc(sizeof(argv[2]));
				strcpy(type,argv[2]);
				
				yyin = fopen(argv[3], "r");
				BEGIN(T_OPTION);
				yylex();
				fclose(yyin);
				free(type);
				
				break;

			case 'u':
				doublons.tab_doublons = (Doublon*)malloc(255*sizeof(Doublon));
				nbDoublon=0;
				
				yyin = fopen(argv[2], "r");
				BEGIN(U_OPTION);
				yylex();
				fclose(yyin);
				
				char* title = malloc(sizeof(argv[2]));
				strcpy(title,argv[2]);
				strcat(title,".doublons");
				FILE *fp = fopen(title, "w");
				verifDoublon(fp);
				//fclose(fp);
				
				break;

			case 'o':
				break;

			default:
				return 0;
    	}
	}

	return EXIT_SUCCESS;
}


void generateTab(char* cite) {

	char* tmp;
	tmp = malloc(strlen(cite)+1);
	strcpy(tmp,cite+6);
	char* cite2;
	cite2 = strtok(tmp,"}");
	
	cites[nbCite] = (char*) malloc(sizeof(cite));
	strcpy(cites[nbCite],cite2);
	nbCite++;
}

void searchBibliography(char* text) {
	char* tmp;
	tmp = malloc(strlen(text)+1);
	strcpy(tmp,text+14);
	
	bibliography = malloc(sizeof(tmp));
	strcpy(bibliography, tmp);
	bibliography = strtok(bibliography,"}");
	
	strcat(bibliography, ".bib");
}

void generateBib(char* cite) {
	FILE *mybib = fopen("mybib.bib", "a");
	
	char* citeBib = malloc(sizeof(cite));;
	int iterateur=0;
	int k = 0;
	while(cite[iterateur] != '{') {
		iterateur++;
	}
	iterateur++;
	while(cite[iterateur] != ',') {
		citeBib[k] = cite[iterateur];
		k++;
		iterateur++;
	}
	
	int i,j;
	for (i=0; i<nbCite; i++){
		if (strcmp(cites[i],citeBib) == 0) {
			fprintf(mybib, "%s\n\n", cite);
		}
	}
	
	fclose(mybib);
}

void checkKey(char* key) {
	
	int i;
	for(i=0;i<nbKey;i++) {
		if (strcmp(key, keys[i]) == 0) {
			printf("Cle en doublon dans le fichier .bib : %s\n", key);
		} 
	}	
	keys[nbKey] = (char*) malloc((sizeof(key)+1));
	strcpy(keys[nbKey], key);
	nbKey++;
}

void checkType(char* type, char* text) {
	char* display = malloc(sizeof(text));
	strcpy(display,text);
	deleteChar(display,'\t');
	deleteChar(display,'\n');
	deleteChar(display,' ');
	
	char* tmp = strtok(text,"=");
	deleteChar(tmp,' ');
	deleteChar(tmp,'\n');
	
	if (strcmp(type,tmp) == 0) {
		printf("%s\n",display);
	}
}

void upperCase(char *chaine) {
    int i = 0;
    for (i = 0; chaine[i] != '\0'; i ++)
    {
        if (chaine[i]  >= 'a' &&  chaine[i] <= 'z')
         chaine[i] -=  'a' - 'A';
    }
}

void deleteChar(char *str, char garbage) {

    char *src, *dst;
    for (src = dst = str; *src != '\0'; src++) {
        *dst = *src;
        if (*dst != garbage) dst++;
    }
    *dst = '\0';
}

void doublon(char* text) {
	deleteChar(text,'\t');
	deleteChar(text,'\n');
	//deleteChar(text,' ');
	
	char* tmp = malloc(sizeof(text));
	strcpy(tmp,text);
	char* cle = strtok(tmp,"=");
	char* valeur = strtok(NULL,"=");
	deleteChar(valeur, '{');
	deleteChar(valeur, '}');
	
	if (strcmp(cle,"title") == 0) {
		doublons.tab_doublons[nbDoublon].title = malloc(sizeof(valeur));
		strcpy(doublons.tab_doublons[nbDoublon].title,valeur);
		nbDoublon++;
	} else if (strcmp(cle,"author") == 0) {
		doublons.tab_doublons[nbDoublon].title = malloc(sizeof(valeur));
		strcpy(doublons.tab_doublons[nbDoublon].title,valeur);
		nbDoublon++;
	} else if (strcmp(cle,"year") == 0) {
		doublons.tab_doublons[nbDoublon].title = malloc(sizeof(valeur));
		strcpy(doublons.tab_doublons[nbDoublon].title,valeur);
		nbDoublon++;
	} else if (strcmp(cle,"type") == 0) {
		doublons.tab_doublons[nbDoublon].title = malloc(sizeof(valeur));
		strcpy(doublons.tab_doublons[nbDoublon].title,valeur);
		nbDoublon++;
	}

	printf("%s\n",cle);
	printf("%s\n",valeur);
}

void verifDoublon(FILE *fp) {
	int i,k;
	for (k=0;k<nbDoublon; k++) {
		for (i=0;i<nbDoublon; i++) {
			if (k!=i) {
				if (strcmp(doublons.tab_doublons[k].title,doublons.tab_doublons[i].title) == 0) {
					fprintf(fp,"%s\n",doublons.tab_doublons[i].title);
				} else if (strcmp(doublons.tab_doublons[k].author,doublons.tab_doublons[i].author) == 0) {
					fprintf(fp,"%s\n",doublons.tab_doublons[i].author);
				} else if (strcmp(doublons.tab_doublons[k].year,doublons.tab_doublons[i].year) == 0) {
					fprintf(fp,"%s\n",doublons.tab_doublons[i].year);
				} else if (strcmp(doublons.tab_doublons[k].type,doublons.tab_doublons[i].type) == 0) {
					fprintf(fp,"%s\n",doublons.tab_doublons[i].type);
				}
			}
		}
	}
}
