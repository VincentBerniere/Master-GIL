%{
#include <stdio.h>

%}
CHAINE \"[^"]*\"
%%
\"              BEGIN CHAINE;
{CHAINE}\\\"    { chaine[l++] = '"'; }
{CHAINE}\"      BEGIN INITIAL;
{CHAINE}.       { chaine[l++] = yytext[0]; }
. 				printf("");

%%

int main(int argc, char** argv) {
	
	FILE *myfile = fopen("exo5.txt", "r");

	if (!myfile) {
		printf("I can't open exo5.txt!\n");
		return -1;
	}
	// set lex to read from it instead of defaulting to STDIN:
	yyin = myfile;
	
	// lex through the input:
	yylex();
}