%{
	#include <stdio.h>
	#include "y.tab.h"
%}

%%

[0-9]+	{return NUM;}
'+'	{return *yytext;}
'*'	{return *yytext;}
'('	{return *yytext;}
')'	{return *yytext;}

%%

yywrap()
{
	return 1;
}


