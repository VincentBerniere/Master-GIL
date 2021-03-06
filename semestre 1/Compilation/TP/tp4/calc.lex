%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <math.h>
#include "yystype.h"
#include "calc.tab.h"
%}

NOMBRE ^[0-9]*\.[0-9]*$ 

%%
{NOMBRE} {
	double l;
	char *end;
	printf("NOMBRE: Analyse de %s=", yytext);
	l = strtod(yytext, &end);
	if ( *end != '\0' ) {
	  fprintf(stderr, "Erreur dans l'analyse de %s comme entier (%lf)\n", yytext, l);
	  exit(EXIT_FAILURE);
	}
	if ( (l==HUGE_VAL ||l==-HUGE_VAL||l==0.) && errno==ERANGE ) {
	 fprintf(stderr, "Dépassement de capacité dans l'analyse de %s comme entier\n", yytext);
	 exit(EXIT_FAILURE);
	}
	printf("%f\n", l);
	yylval = 1;
	return NOMBRE;
}

\+ return '+';
\- return '-';
\* return '*';
\/ return '/';
\( return '(';
\) return ')';
\n return '\n';
. ;
%%