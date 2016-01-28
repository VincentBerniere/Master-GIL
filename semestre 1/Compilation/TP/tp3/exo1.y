%{	
#include <stdio.h>
#define YYSTYPE double
%}

%token NOMBRE 
%start ligne
%%

ligne : ligne expr '\n' {printf("resultat : %f \n", $2);}
      | ligne '\n'
      |
      ;
terme : terme '*' facteur {$$=$1*$3;}
      | terme '/' facteur {$$=$1/$3;}
      | facteur
      ;
expr : expr '+' terme {$$=$1+$3;}
     | expr '-' terme {$$=$1-$3;}
     | terme
     ;
facteur : '-' facteur {$$=-$2;}
        | '(' expr ')' {$$=($2);}
        | NOMBRE {$$ = $1;}
        ;
%%
#include "lex.yy.c"