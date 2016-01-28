%{
#include <stdio.h>

int acat = 0, atta = 0, cgc = 0, cgcaa = 0;
%}
ATTA 		'ATTA'
ACAT 		'ACAT'
CGC  		'CGC'
CGCAA 		'CGCAA'

%%
ATTA	{ atta++; printf("ATTA = %d\n", atta); REJECT; }
ACAT 	{ acat++; printf("ACAT = %d\n", acat); REJECT; }
CGC 	{ cgc++; printf("CGC = %d\n", cgc); REJECT; }
CGCAA 	{ cgcaa++; printf("CGCAA = %d\n", cgcaa); REJECT; }
. 		printf("");

%%

int main(int argc, char** argv) {
	
	FILE *myfile = fopen("exo4.txt", "r");

	if (!myfile) {
		printf("I can't open exo4.txt!\n");
		return -1;
	}
	// set lex to read from it instead of defaulting to STDIN:
	yyin = myfile;
	
	// lex through the input:
	yylex();
}