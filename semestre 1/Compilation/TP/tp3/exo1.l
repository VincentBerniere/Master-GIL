%{
#include <string.h>
#include "exo1.tab.h"
%}

num (^[0-9]*\.[0-9]+$)
%%
{num}   {yylval=atof(yytext); return(NOMBRE);}
[0-9]+  return(NOMBRE);
\+      return('+');
\-      return('-');
\*      return('*');
\/      return('/');
\(      return('(');
\)      return(')');
\n      return('\n');

.       ;

%%
