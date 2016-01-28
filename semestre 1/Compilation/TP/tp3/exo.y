%{	
#include <stdio.h>
%}

%token NOMBRE 
%start ligne
%%

ligne : ligne expr '\n'
      | ligne '\n'
      |
      ;
terme : terme '*' facteur
      | terme '/' facteur
      | facteur
      ;
expr : expr '+' terme
     | expr '-' terme
     | terme
     ;
facteur : '-' facteur
        | '(' expr ')'
        | NOMBRE
        ;
%%


int yyerror(char *s) {
	printf("yyerror : %s\n",s);
	return 0;
}

int main(void) {
	yyparse();
	return 0;
}