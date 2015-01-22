%{
    #include <stdio.h>
    #include <stdlib.h>
    #include "lex.yy.c"
    #include "exptree.h"
    
   int yylex(void);    
%}

%union{
    int ival;
    char name;
    struct tree_node *nptr;
};

%token <ival> DIGIT EQUAL
%token <name> ID
%token <nptr> READ WRITE IF THEN ENDIF WHILE DO ENDWHILE
%type <nptr> slist stmt E

%left EQUALITY
%left '>' '<'
%left '+' '-'
%left '*' '/' '%'
%right '='

%%

start : slist '\n'  {evaluate($1);exit(0);}
      ;

slist : stmt    {$$ = $1;}
        | slist stmt  {$$ = mkstmtNode(CSLIST,$1,$2);}
      ;

stmt : ID '=' E ';'   {$$ = mkstmtNode(ASSG,mkID($1),$3);}
     | READ '(' ID ')'';'  {$$ = mkstmtNode(CREAD,mkID($3), NULL);}
     | WRITE '(' E ')'';'  {$$ = mkstmtNode(CWRITE,$3, NULL);}
     | IF '(' E ')' THEN slist ENDIF ';' {$$ = mkstmtNode(CIF,$3,$6);}
     | WHILE '(' E ')' DO slist ENDWHILE ';' {$$ = mkstmtNode(CWHILE,$3,$6);}
     ;
E : E '+' E   {$$ = mkOpNode('+',$1,$3);}
  | E '-' E   {$$ = mkOpNode('-',$1,$3);}
  | E '*' E   {$$ = mkOpNode('*',$1,$3);}
  | E '/' E   {$$ = mkOpNode('/',$1,$3);}
  | E '>' E   {$$ = mkOpNode('>',$1,$3);}
  | E '<' E   {$$ = mkOpNode('<',$1,$3);}
  | E EQUALITY E {$$ = mkOpNode(ISEQUAL,$1,$3);}
  | '('E')'     {$$ = $2;}
  | DIGIT     {$$ = mkNUM($1);}
  | ID      {$$ = mkID($1);}
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
