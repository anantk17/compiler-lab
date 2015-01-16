%{
	#include <stdio.h>
	#include <stdlib.h>
	#include "lex.yy.c"

	int yylex(void);
    
    struct tree_node{
        //type : 0 - NUMBER,'+' - Addition, '-' - Subtraction , '*' - Multiply, '/'-Divide,  '%' -
        //Modulo
        int type;
        //integer value of number at node, valid only if type is 0
        int value;
        //ptr1 and ptr2 are NULL for leaf nodes
        struct tree_node *ptr1,*ptr2;
    };

    int evaluate(struct tree_node* root)
    {
        if(root->type == 0)
            return root->value;
        else
        {
            switch(root->type){
                case '+':
                    return evaluate(root->ptr1) + evaluate(root->ptr2);
                    break;
                case '-':
                    return evaluate(root->ptr1) - evaluate(root->ptr2);
                    break;
                case '*':
                    return evaluate(root->ptr1) * evaluate(root->ptr2);
                    break;
                case '/':
                    return evaluate(root->ptr1) / evaluate(root->ptr2);
                    break;
                case '%':
                    return evaluate(root->ptr1) % evaluate(root->ptr2);
                    break;
            }
        }
    }

   struct tree_node* mkOperatorNode(int op, struct tree_node* ptr1, struct tree_node * ptr2)
   {
        struct tree_node *node = (struct tree_node*) malloc(sizeof(struct tree_node));
        node->type = op;
        node->value = 0;
        node->ptr1 = ptr1;
        node->ptr2 = ptr2;

        return node;
   }

    struct tree_node* mkLeafNode(int value)
    {
        struct tree_node *node = (struct tree_node*) malloc(sizeof(struct tree_node));
        node->type = 0;
        node->value = value;
        node->ptr1 = NULL;
        node->ptr2 = NULL;

        return node;
    }
%}

%union{
 int ival;
 struct tree_node *nptr;
};

%token <ival> DIGIT
%type  <nptr> expr

%left '+' '-' 
%left '*' '/' '%'

%%

start : expr '\n'	{printf("%d",evaluate($1));exit(1);}
	;

expr : expr '+' expr	{$$ = mkOperatorNode('+',$1,$3);}
	|expr '-' expr 	{$$ = mkOperatorNode('-',$1,$3);}
	| expr '*' expr {$$ = mkOperatorNode('*',$1,$3);}
	| expr '/' expr {$$ = mkOperatorNode('/',$1,$3);}
	| expr '%' expr {$$ = mkOperatorNode('%',$1,$3);}
	| '(' expr ')'  {$$ = $2;} 
	| DIGIT {$$ = mkLeafNode($1);}
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
