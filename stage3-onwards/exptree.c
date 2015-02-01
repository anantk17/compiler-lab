#include "exptree.h"
#include "symboltable.h"
#include <stdio.h>
#include <stdlib.h>

//extern struct SymbolTable st;

//Create operator nodes
struct tree_node* mkOpNode(int op, struct tree_node* ptr1, struct tree_node* ptr2)
{
    struct tree_node *node = (struct tree_node*) malloc(sizeof(struct tree_node));
    if(!node)
        printf("malloc failed");
    node->type = op;
    node->value = 0;
    //node->name = 0;
    node->arglist = NULL;
    node->ptr1 = ptr1;
    node->ptr2 = ptr2;

    return node;
}

//Create statement nodes
struct tree_node* mkstmtNode(int stmt, struct tree_node* ptr1, struct tree_node* ptr2)
{

    struct tree_node *node = (struct tree_node*) malloc(sizeof(struct tree_node));
    if(!node)
        printf("malloc failed");
    node->type = stmt;
    node->value = 0;
    //node->name = 0;
    if(stmt == CREAD||stmt == CWRITE)
    {
        node->arglist = NULL;
        node->ptr1 = ptr1;
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

//Create leaf nodes for IDENTIFIERS
struct tree_node* mkID(char* name,struct tree_node* offset_expr)
{
    struct Gsymbol* symbol;
    symbol = Glookup(name);
    if(symbol != NULL)
    {
        struct tree_node *node = (struct tree_node*)malloc(sizeof(struct tree_node));
        if(!node)  
            printf("malloc failed");
        node->type = 1;
        node->value = 0;
        node->arglist = NULL;
        node->offset = offset_expr;
        node->symbol = symbol;
        node->ptr1 = NULL;
        node->ptr2 = NULL;
    
        return node;
    }
    else
    {
        printf("Identifier not declared %s!!\n",name);
        exit(1);
    }
}

//Create leaf nodes for NUMBERS
struct tree_node* mkNUM(int val)
{
    struct tree_node* node = (struct tree_node*)malloc(sizeof(struct tree_node));
    if(!node)
        printf("malloc failed");
    node->type = 0;
    node->value = val;
    //node->name = 0;
    node->arglist = NULL;
    node->symbol = NULL;
    node->ptr1 = NULL;
    node->ptr2 = NULL;
    
    return node;
}

//Evaluates expression nodes
int exp_evaluate(struct tree_node* node)
{
    if(node == NULL)
        return 0;

    switch(node->type)
    {
        case CNUMBER:
            return node->value;
            break;
        case CID:
            return *(node->symbol->binding + exp_evaluate(node->offset));
            break;
        case '+':
            return exp_evaluate(node->ptr1) + exp_evaluate(node->ptr2);
            break;
        case '-':
            return exp_evaluate(node->ptr1) - exp_evaluate(node->ptr2);
            break;
        case '/':
            return exp_evaluate(node->ptr1) / exp_evaluate(node->ptr2);
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

//Evaluates abstract syntax tree
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
        *(node->ptr1->symbol->binding + exp_evaluate(node->ptr1->offset)) = rhs;
        //variables[node->ptr1->name -'a'] = rhs;
        //initialized[node->ptr1->name-'a'] = 1;
    }
    else if(node->type == CREAD)
    {
        /*if(Glookup(node->ptr1->symbol->binding) == NULL)
            printf("Undeclared variable %s used!!\n",name*/
        scanf("%d",node->ptr1->symbol->binding + exp_evaluate(node->ptr1->offset));
        //initialized[node->arglist->name-'a'] = 1;
    }
    else if(node->type == CWRITE)
    {
        int rhs = exp_evaluate(node->ptr1);
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
        while(ret)
        {
            evaluate(node->ptr2);               
            ret = exp_evaluate(node->ptr1);
        }
    }
        return;
}

struct tree_node* mkDeclNode(int decl_type,struct tree_node* ptr1, struct tree_node* ptr2)
{
    struct tree_node* Node = (struct tree_node*) malloc(sizeof(struct tree_node));
    Node->type = decl_type;
    Node->ptr1 = ptr1;
    Node->ptr2 = ptr2;
}

struct tree_node* mkDeclNode1(int decl_type,int data_type,struct tree_node* ptr1)
{
    struct tree_node* Node = (struct tree_node*) malloc(sizeof(struct tree_node));
    struct tree_node* LeftNode = (struct tree_node*)malloc(sizeof(struct tree_node));
    LeftNode->type = DATA_TYPE;
    LeftNode->data_type = INT;

    Node->type = CIDLIST;
    Node->ptr1 = LeftNode;
    Node->ptr2 = ptr1;
}

void declare_type(struct tree_node* root, int data_type)
{
    if(root-type == CIDLIST)
    {
        declare_type(root->ptr1);
        declare_type(root->ptr2,data_type);
    }
    else if(root->type == DID)
    {
       if(Glookup(root->name))
       {
            printf("Error!!!. Identifier %s already declared previously.",root->name);
            exit(1);
       }
       else
       {
            Ginstall(root->name,root->date_type,root->size);
       }
    }
}

void declare(struct tree_node* root)
{
    if(root->type == CDECLIST)
    {
        declare(root->left);
        declare(root->right);
    }
    else if(root->type == CDECL)
    {
        if(root->data_type == INT)
        {
            declare_type(root->ptr1,INT);
            declare(root->ptr2);
        }        
    }
}
