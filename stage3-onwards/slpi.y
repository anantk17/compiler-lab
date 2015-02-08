%{
    #include <stdio.h>
    #include <stdlib.h>
    #include "lex.yy.c"
    #include "exptree.h"
    #include "symboltable.h"

   int yylex(void); 
   extern struct SymbolTable st;
%}

%union{
    int ival;
    char* name;
    struct tree_node *nptr;
};

%token <ival> DIGIT EQUAL BOL
%token <name> ID
%token <nptr> READ WRITE IF THEN ELSE ENDIF WHILE DO ENDWHILE INTEGER DECL ENDDECL BOOLEAN
%type <nptr> slist stmt gdecl idlist E IDT DECLID decllist decl

%right '='
%left OR
%left AND
%left EQUALITY NOTEQUAL
%left '>' '<' LTE GTE
%left '+' '-'
%left '*' '/' '%'
%right NOT
%left '(' ')'

%%

start : gdecl slist
      {/*declare($1);*/evaluate($2);exit(0);}
      ;
gdecl   :   DECL decllist ENDDECL {$$ = $2;declare($$);}
        ;

decllist : decl decllist {$$ = mkDeclNode(CDECLIST,$1,$2);}
         | decl {$$=$1;}
         ;

decl :  INTEGER idlist ';'  {$$ = mkIdListNode(CDECL,INT,$2);}
     |  BOOLEAN idlist ';'  {$$ = mkIdListNode(CDECL,BOOL,$2);}
     ;

idlist : DECLID ',' idlist {$$ = mkDeclNode(CIDLIST,$1,$3);}  
       | DECLID {$$ = $1;}
       ;

slist : stmt slist   {$$ = mkstmtNode(CSLIST,$1,$2,NULL);}
        | stmt {$$=$1;}
      ;

stmt : IDT '=' E ';'   {$$ = mkstmtNode(ASSG,$1,$3,NULL);}
     | READ '(' IDT ')'';'  {$$ = mkstmtNode(CREAD,$3, NULL,NULL);}
     | WRITE '(' E ')'';'  {$$ = mkstmtNode(CWRITE,$3, NULL,NULL);}
     | IF '(' E ')' THEN slist ENDIF ';' {$$ = mkstmtNode(CIF,$3,$6,NULL);}
     | IF '(' E ')' THEN slist ELSE slist ENDIF ';' {$$ = mkstmtNode(CIFELSE,$3,$6,$8);}
     | WHILE '(' E ')' DO slist ENDWHILE ';' {$$ = mkstmtNode(CWHILE,$3,$6,NULL);}
     ;

E : E '+' E   {$$ = mkOpNode('+',$1,$3);}
  | E '-' E   {$$ = mkOpNode('-',$1,$3);}
  | E '*' E   {$$ = mkOpNode('*',$1,$3);}
  | E '/' E   {$$ = mkOpNode('/',$1,$3);}
  | E '%' E   {$$ = mkOpNode('%',$1,$3);}
  | E '>' E   {$$ = mkOpNode('>',$1,$3);}
  | E '<' E   {$$ = mkOpNode('<',$1,$3);}
  | E LTE E   {$$ = mkOpNode(CLTE,$1,$3);}
  | E GTE E   {$$ = mkOpNode(CGTE,$1,$3);} 
  | E EQUALITY E {$$ = mkOpNode(ISEQUAL,$1,$3);}
  | E NOTEQUAL E {$$ = mkOpNode(ISNTEQUAL,$1,$3);} 
  | E AND E {$$ = mkOpNode(CAND,$1,$3);}
  | E OR E  {$$ = mkOpNode(COR,$1,$3);}
  | NOT E   {$$ = mkOpNode(CNOT,$2,NULL);}
  | '('E')'     {$$ = $2;}
  | DIGIT     {$$ = mkNUM($1);}
  | IDT      {$$ = $1;}
  | BOL     {$$ = mkBool($1);} 
  ;

DECLID : ID {$$ = mkDeclID(DID,$1,1);}
       | ID '[' DIGIT ']' {$$ = mkDeclID(DID,$1,$3);}
       ;

IDT : ID    {$$ = mkID($1,NULL);}
    | ID '[' E ']'  {$$ = mkID($1,$3);}
    ;
%%

yyerror()
{
    printf("error");
    return ;
}

int main(int argc, char *argv[])
{
    yyin = fopen(argv[1],"r");
    st.head = NULL;
    yyparse();
    fclose(yyin);
    return 1;
}
