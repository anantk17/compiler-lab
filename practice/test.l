
%{
	#include <stdio.h>
	#include "y.tab.h"
	extern int yylval;
 
%}

plus [+]
star [*]
%%

[0-9]+	{yylval = atoi(yytext);return DIGIT;}

[*+/-%\n]	{return *yytext;}
.	{}
%%

yywrap()
{
	return 0;
}
