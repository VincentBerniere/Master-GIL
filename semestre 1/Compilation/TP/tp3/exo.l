%{
#include <stdio.h>
#include "exo.tab.h"
%}

%%
[ \t\n]+ { /* ignore */ }
[0-9]+	return(NOMBRE);
\+		return('+');
\-		return('-');
\*		return('*');
\/		return('/');

.		;

%%
