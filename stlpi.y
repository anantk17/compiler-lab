%{
    #include <stdio.h>
    #include <stdlib.h>
    #include "lex.yy.c"
    
    #define CSLIST 2
    #define ASSG 3
    #define CREAD 4
    #define CWRITE 5
    #define CWHILE 6
    #define CIF 7
    #define ISEQUAL 8

    int yylex(void);
    
    int variables[26];

    struct tree_node{
        //type : 0 - NUMBER, 1 - ID ,2 - SLIST, 3 - ASSG, 4 - READ, 5 - WRITE, '+' - Addition, '*'
        //-Multiplication, '-' - Subtraction
        int type;
        //if type is 1, name defines identifier name
        char name;
        //integer value of number at node, valid only if type is 0
        int value;
        //argument name
        struct tree_node *arglist;
        //ptr1 and ptr2 are NULL for leaf nodes
        struct tree_node *ptr1, *ptr2;
    };

    struct tree_node* mkOpNode(int op, struct tree_node* ptr1, struct tree_node* ptr2)
    {
        struct tree_node *node = (struct tree_node*) malloc(sizeof(struct tree_node));
        if(!node)
            printf("malloc failed");
        node->type = op;
        node->value = 0;
        node->name = 0;
        node->arglist = NULL;
        node->ptr1 = ptr1;
        node->ptr2 = ptr2;

        return node;
    }

    struct tree_node* mkstmtNode(int stmt, struct tree_node* ptr1, struct tree_node* ptr2)
    {

        struct tree_node *node = (struct tree_node*) malloc(sizeof(struct tree_node));
        if(!node)
            printf("malloc failed");
        node->type = stmt;
        node->value = 0;
        node->name = 0;
        if(stmt == CREAD||stmt == CWRITE)
        {
            node->arglist = ptr1;
            node->ptr1 = NULL;
            node->ptr2 = NULL;
        }
        else
        {
            node->arglist = NULL;
            node->ptr1 = ptr1;
            node->ptr2 = ptr2;
        }
       
        return node;
    }

    struct tree_node* mkID(char name)
    {
        struct tree_node *node = (struct tree_node*)malloc(sizeof(struct tree_node));
        if(!node)  
            printf("malloc failed");
        node->type = 1;
        node->value = 0;
        node->name = name;
        node->arglist = NULL;
        node->ptr1 = NULL;
        node->ptr2 = NULL;
        
        return node;
    }

    struct tree_node* mkNUM(int val)
    {
        struct tree_node* node = (struct tree_node*)malloc(sizeof(struct tree_node));
        if(!node)
            printf("malloc failed");
        node->type = 0;
        node->value = val;
        node->name = 0;
        node->arglist = NULL;
        node->ptr1 = NULL;
        node->ptr2 = NULL;
        
        return node;
    }
    
    int exp_evaluate(struct tree_node* node)
    {
        switch(node->type)
        {
            case 0:
                return node->value;
                break;
            case 1:
                return variables[node->name-'a'];
                break;
            case '+':
                return exp_evaluate(node->ptr1) + exp_evaluate(node->ptr2);
                break;
            case '-':
                return exp_evaluate(node->ptr1) - exp_evaluate(node->ptr2);
                break;

            case '*':
                return exp_evaluate(node->ptr1) * exp_evaluate(node->ptr2);
                break;
            case '<':
                if(exp_evaluate(node->ptr1) < exp_evaluate(node->ptr2))
                    return 1;
                else
                    return 0;
                break;
            case '>':
                if(exp_evaluate(node->ptr1) > exp_evaluate(node->ptr2))
                    return 1;
                else
                    return 0;
                break;
            case ISEQUAL:
                if(exp_evaluate(node->ptr1) == exp_evaluate(node->ptr2))
                    return 1;
                else
                    return 0;
                break;
        }
    }

    void evaluate(struct tree_node* node)
    {
        if(node->type == CSLIST)
        {
            evaluate(node->ptr1);
            evaluate(node->ptr2);
        }
        else if(node->type == ASSG)
        {
            int rhs = exp_evaluate(node->ptr2);
            variables[node->ptr1->name -'a'] = rhs;
        }
        else if(node->type == CREAD)
        {
            scanf("%d",&variables[node->arglist->name -'a']);
        }
        else if(node->type == CWRITE)
        {
            int rhs = exp_evaluate(node->arglist);
            printf("%d\n",rhs);
        }
        else if(node->type == CIF)
        {
            if(exp_evaluate(node->ptr1))
                evaluate(node->ptr2);
        }
        else if(node->type == CWHILE)
        {
            int ret = exp_evaluate(node->ptr1);
            while(exp_evaluate(node->ptr1))
            {
                evaluate(node->ptr2);
                ret = exp_evaluate(node->ptr1);
             }
        }
            return;
    }

    
%}

%union{
    int ival;
    char name;
    struct tree_node *nptr;
};

%token <ival> DIGIT;
%token <ival> EQUAL
%token <name> ID;
%token <nptr> READ;
%token <nptr> WRITE;
%token <nptr> IF
%token <nptr> THEN
%token <nptr> ENDIF
%token <nptr> WHILE
%token <nptr> DO
%token <nptr> ENDWHILE
%type <nptr> slist;
%type <nptr> stmt;
%type <nptr> E;

%left EQUAL
%left '>' '<'
%left '+' '-'
%left '*' '/' '%'

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
  | E '>' E   {$$ = mkOpNode('>',$1,$3);}
  | E '<' E   {$$ = mkOpNode('<',$1,$3);}
  | E EQUAL E {$$ = mkOpNode(ISEQUAL,$1,$3);}
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
