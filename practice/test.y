%{
	#include <stdio.h>
	#include <stdlib.h>
	#include "lex.yy.c"

	int yylex(void);
%}

%token DIGIT
%left '+' '-' 
%left '*' '/' '%'

%%

start : expr '\n'	{printf("%d",$1);exit(1);}
	;

expr : expr '+' expr	{$$ = $1 + $3;}
	|expr '-' expr 	{$$ = $1 - $3;}
	| expr '*' expr {$$ = $1 * $3;}
	| expr '/' expr {$$ = $1 / $3;}
	| expr '%' expr {$$ = $1 % $3;}
	| '(' expr ')'  {$$ = $2;} 
	| DIGIT {$$ = $1;}
	;

%%

yyerror()
{
	printf("error");
	return ;
}


int main()
{
	yyparse();
	return 1;
}


