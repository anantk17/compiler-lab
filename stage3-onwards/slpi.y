%{
    #include <stdio.h>
    #include <stdlib.h>
    #include "lex.yy.c"
    #include "exptree.h"
    #include "symboltable.h"

   int yylex(void); 
   extern struct SymbolTable st;
   extern struct LocalTable lt;
   extern struct arg_list alist;
   int type;
   int func_type;
%}

%union{
    int ival;
    char* name;
    struct tree_node *nptr;
    struct arg_node *args;
};

%token <ival> DIGIT EQUAL BOL
%token <name> ID
%token <nptr> READ WRITE IF THEN ELSE ENDIF WHILE DO ENDWHILE INTEGER DECL ENDDECL BOOLEAN FBEGIN
%token <nptr> RETURN
%token <nptr> END MAIN
%type <nptr> slist stmt gdecl idlist E IDT declid decllist decl dtype start mainblock 
%type <nptr> carglist RetStmt fdef fdeflist Body
%type <args> defarglist

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

start : gdecl fdeflist mainblock
      {/*$$ = mkstmtNode(CPGM,$2,NULL,NULL);gen_code($$);exit(0);*/}
      ;

gdecl   :   DECL decllist ENDDECL {clear_args();}
        ;

decllist : decl decllist {}
         |      {}
         ;

decl : dtype idlist ';' {}
     ;

dtype : INTEGER {type = INT;}
      | BOOLEAN {type = BOOL;}
      ;

idlist : declid ',' idlist {}  
       | declid {}
       ;

declid : ID { Ginstall($1,type,1);}
       | ID '[' DIGIT ']' {Ginstall($1,type,$3);}
       | ID {func_type = type;} '(' decarglist ')' {Ginstall($1,func_type,0);clear_args();type =
       func_type;}
       ;

decarglist : decargentry decarglist{}
        | dtype decargidlist {} 
        | {}
        ;

decargentry : dtype decargidlist ';' {} 
            ;

decargidlist: ID ',' decargidlist {addArgs($1,type);}
            |ID {addArgs($1,type);} 
            ;

defarglist : defargentry defarglist{}
            | dtype defargidlist   {}
            | {}
        ;

defargentry : dtype defargidlist ';' {}

            ;

defargidlist: ID ',' defargidlist {addArgs($1,type);}
            |ID {addArgs($1,type);} 
            ;

fdeflist : fdeflist fdef{}
          | {}
          ;

fdef: dtype {func_type = type;} ID '(' defarglist ')' {installArgs($3);} '{' LDefblock Body '}'{gen_code($10);clear_args();clear_local();type = func_type;}
    ;

mainblock : INTEGER {func_type = INT;}MAIN '(' ')' '{' LDefblock Body '}'{gen_code($8);clear_args();clear_local(); type = func_type;}
          ;

LDefblock : DECL ldecllist ENDDECL { }
          ;

ldecllist : ldecl ldecllist {}
          | {}
          ;

ldecl:  dtype lidlist ';' {}
     ;

lidlist : ID ',' lidlist {Linstall($1,type);}
        | ID {Linstall($1,type);}
        ;

Body : FBEGIN slist RetStmt END {$$ = mkstmtNode(CFUNC,$2,$3,NULL);}
     ;

slist : stmt slist   {$$ = mkstmtNode(CSLIST,$1,$2,NULL);}
        | {}
    ;

stmt : IDT '=' E ';'   {$$ = mkstmtNode(ASSG,$1,$3,NULL);}
     | ID '=' E ';'    {$$ = mkstmtNode(ASSG,mkID($1,NULL),$3,NULL);}
     | READ '(' IDT ')'';'  {$$ = mkstmtNode(CREAD,$3, NULL,NULL);}
     | READ '(' ID ')' ';'  {$$ = mkstmtNode(CREAD,mkID($3,NULL),NULL,NULL);}
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
  | ID      {$$ = mkID($1,NULL);}
  | IDT      {$$ = $1;}
  | ID '(' carglist ')'{$$ = mkFunc($1,$3);}
  | BOL     {$$ = mkBool($1);} 
  ;

carglist : carglist ',' E {$$ = mkArgNode(CARG,$1,$3);}
         | E    {$$ = mkArgNode(CARG,NULL,$1);}
         |  {$$ = NULL;}
         ;

IDT :ID '[' E ']'  {$$ = mkID($1,$3);}
    ;

RetStmt : RETURN E ';' {$$ = mkstmtNode(CRET,$2,NULL,NULL);}
        ;
%%

yyerror()
{
    printf("error");
    return ;
}

int main(int argc, char *argv[])
{
    int curr_line = 0;
    yyin = fopen(argv[1],"r");
    st.head = NULL;
    st.tail = NULL;
    st.memory = 0;
    lt.head = NULL;
    lt.tail = NULL;
    lt.memory = 1;
    lt.argmem = -3;
    alist.head = NULL;
    yyparse();
    fclose(yyin);
    return 1;
}
