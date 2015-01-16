%{
	#include <stdio.h>
	#include "y.tab.h"
	extern YYSTYPE yylval;
 
%}

%%

[0-9]+	{yylval.ival = atoi(yytext);return DIGIT;}

[()*+-/%\n]	{return *yytext;}
.	{}
%%

yywrap()
{
	return 0;
}
