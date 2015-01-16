%{
#include "lex.yy.c"
%}

%token NUM

%%

start: expr '\n'	{exit(1);}
	;

expr:	expr '+' expr
	| expr '*' expr
	| '(' expr ')'
	| NUM
	;

%%

int main(void)
{
	return yyparse();
}
