%{

#include <stdio.h>
#include <stdlib.h>

%}

REF \\cite\{[a-zA-Z]+:[0-9]+:?[0-9]*\}

%%

%%

int main(int argc, char * argv[]) {

	if (argc == 1) {
    	exit(0);
	}

  	int option;

	while ((option = getopt (argc, argv, "b:c:e:k:s:t:u:o:")) != -1) {
    	switch (c) {
     
			case 'b':
				yyin = fopen(optarg, "r");
				BEGIN(BOPTION);
				yylex();
			break;

	    	case 'c':
	        break;

			case 'e':
			break;

			case 'k':
			break;

			case 's':
			break;

			case 't':
			break;

			case 'u':
			break;

			case 'o':
			break;

			default:
				return 0;
    	}
	}

	return EXIT_SUCCESS;
}

