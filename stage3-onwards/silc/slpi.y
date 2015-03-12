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
   int sp=0,bp=0;
   FILE* outFile;
   char filename[50];
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

start : {fprintf(outFile,"START\nMOV BP, 0\n");}gdecl fdeflist mainblock   {fprintf(outFile,"end: HALT\n");}
      
      ;

gdecl   :   DECL decllist ENDDECL {clear_args();sp = st.memory;fprintf(outFile,"MOV SP,%d\n",sp);fprintf(outFile,"CALL main\n");fprintf(outFile,"JMP end\n");}
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

decarglist : decargglist {}
           | {}

decargglist :  decargentry decargglist {}
           | dtype decargidlist {}
          ;

decargentry : dtype decargidlist ';' {} 
            ;

decargidlist: decargid ',' decargidlist {}
            | decargid {} 
            ;

decargid : '&'ID    {addArgs($2,type,1);}
         | ID       {addArgs($1,type,0);}
        ;
fdeflist : fdeflist fdef{}
          | {}
          ;

fdef: dtype {func_type = type;} ID '(' decarglist ')' {installArgs($3);} '{' LDefblock Body'}'{$$=mkFuncDefNode($3,$10,func_type);gen_code($$);clear_args();clear_local();type = func_type;}
    ;

mainblock : INTEGER {func_type = INT;}MAIN '(' ')' '{' LDefblock Body'}'{$$=mkMainDefNode($8);gen_code($$);clear_args();clear_local(); type = func_type;}
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
        | stmt      {$$ = $1;}
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
    remove(filename);
    return ;
}

int main(int argc, char *argv[])
{
    int curr_line = 0;
    if(argc != 3)
    {
        printf("Usage: ./slpi input_filename output_filename\n");
        exit(1);
    }
    yyin = fopen(argv[1],"r");
    outFile = fopen(argv[2],"w");
    strcpy(filename,argv[2]);
    st.head = NULL;
    st.tail = NULL;
    st.memory = 1535;
    lt.head = NULL;
    lt.tail = NULL;
    lt.memory = 1;
    lt.argmem = -3;
    alist.head = NULL;
    yyparse();
    fclose(yyin);
    return 1;
}
