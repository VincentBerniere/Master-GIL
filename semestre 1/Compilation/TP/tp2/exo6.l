%{
#include <stdio.h>

%}

COMMENTAIRE		(\/\/.?*)|(\/\*([^*]|[\r\n]|(\*+([^*/]|[\r\n])))*\*+\/)

%%
{COMMENTAIRE}	{ ECHO; }
. 				printf("");

%%

int main(int argc, char** argv) {
	
	FILE *myfile = fopen("main.c", "r");

	if (!myfile) {
		printf("I can't open main.c!\n");
		return -1;
	}
	// set lex to read from it instead of defaulting to STDIN:
	yyin = myfile;
	
	// lex through the input:
	yylex();
}