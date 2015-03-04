#include "exptree.h"
#include "symboltable.h"
#include <stdio.h>
#include <stdlib.h>

extern struct SymbolTable st;
extern yylineno;
extern func_type;

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

    if(op == CAND || op == COR)
    {
        if((node->ptr1->data_type != BOOL) || (node->ptr2->data_type != node->ptr1->data_type))
        {
            printf("ERROR: Line Number %d Incorrect data type for %d operator",yylineno,op);
            exit(8);
        }
        node->data_type = BOOL;
    }
    else if(op == CNOT)
    {
        if((node->ptr1->data_type != BOOL))
        {
            printf("ERROR: Line Number %d Incorrect data type for %d operator",yylineno,op);
            exit(8);
        }
        node->data_type = BOOL;
    }
    else
    {
        if((node->ptr1->data_type != INT) || (node->ptr1->data_type != node->ptr2->data_type))
        {
            printf("ERROR: Line Number %d Incorrect data type for %d operator",yylineno,op);
            exit(8);
        }

        if(op == '+' || op == '-' || op == '*' || op == '/' || op == '%')
            node->data_type = INT;
        else
            node->data_type = BOOL;

    }

    return node;
}

//Create statement nodes
struct tree_node* mkstmtNode(int stmt, struct tree_node* ptr1, struct tree_node* ptr2,struct tree_node* ptr3)
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
    else if(stmt == ASSG)
    {
        node->arglist = NULL;
        node->ptr1 = ptr1;
        node->ptr2 = ptr2;

        if(node->ptr1->data_type != node->ptr2->data_type)
        {
            printf("ERROR: Line Number %d type mismatch\n",yylineno);
            exit(5);
        }
    }
    else if(stmt == CIF || stmt == CWHILE || stmt == CIFELSE)
    {
        node->arglist = NULL;
        node->ptr1 = ptr1;
        node->ptr2 = ptr2;
        
        if(node->ptr1->data_type != BOOL)
        {
            printf("ERROR: Line Number %d type mismatch\n",yylineno);
            exit(6);
        }

        if(stmt == CIFELSE)
        {
            node->ptr3 = ptr3;
        }
    }
    else if(stmt == CRET)
    {
        node->arglist = NULL;
        node->ptr1 = ptr1;
        if(func_type != node->ptr1->data_type)
        {
            printf("Return type does not match function definition\n");
            exit(1);
        }
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
        if(offset_expr!= NULL && offset_expr->data_type == BOOL)
        {
            printf("Error: Line Number %d Incorrect type for array index",yylineno);
            exit(7);
        }
        struct Gsymbol* gret = NULL;
        struct Lsymbol* ret = Llookup(name);
        if(ret == NULL)
        {

          //  printf("Global table\n");
            gret = Glookup(name);
            if(gret == NULL)
            {
                printf("Error: Line Number %d Undeclared variable used\n",yylineno);
                exit(3);
            }
        }
        //printf("Local Table\n");
        if(ret == NULL && gret->size > 1 && offset_expr == NULL )
        {
            printf("Error: Line Number %d Array variable used without index",yylineno);
            exit(3);
        }
        if(ret == NULL  && gret->size == 1 && offset_expr != NULL)
        {
            printf("Error: Line Number %d Integer type used with index",yylineno);
            exit(3);
        }
        struct tree_node *node = (struct tree_node*)malloc(sizeof(struct tree_node));
        if(!node)  
            printf("malloc failed");
        node->type = CID;
        node->value = 0;
        node->arglist = NULL;
        node->offset = offset_expr;
        node->name = name;
        if(ret != NULL)
        {   
            node->data_type = ret->type;
            node->lsymbol = ret;
        }
        else
        {
            node->data_type = gret->type;
            node->symbol = gret;
        }
        node->ptr1 = NULL;
        node->ptr2 = NULL;
    
        return node;
}

//Create leaf nodes for NUMBERS
struct tree_node* mkNUM(int val)
{
    struct tree_node* node = (struct tree_node*)malloc(sizeof(struct tree_node));
    if(!node)
        printf("malloc failed");
    node->type = CNUMBER;
    node->value = val;
    node->data_type = INT;
    node->arglist = NULL;
    node->symbol = NULL;
    node->ptr1 = NULL;
    node->ptr2 = NULL;
    
    return node;
}

struct tree_node* mkBool(int val)
{
    struct tree_node* node = (struct tree_node*)malloc(sizeof(struct tree_node));
    if(!node)
        printf("malloc failed");
    node->type = CBOOL;
    node->value = val;
    node->data_type = BOOL;
    node->arglist = NULL;
    node->symbol = NULL;
    node->ptr1 = NULL;
    node->ptr2 = NULL;
    
    return node;
 
}
/*
//Evaluates expression nodes
int exp_evaluate(struct tree_node* node)
{
    struct Gsymbol* ret;
    if(node == NULL)
        return 0;

    switch(node->type)
    {
        case CNUMBER:
            return node->value;
            break;
        case CBOOL:
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
	case '%':
	    return exp_evaluate(node->ptr1) % exp_evaluate(node->ptr2);
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
        case CAND:
            return exp_evaluate(node->ptr1) && exp_evaluate(node->ptr2);
            break;
        case COR:
            return exp_evaluate(node->ptr1) || exp_evaluate(node->ptr2);
            break;
        case CNOT:
            return !(exp_evaluate(node->ptr1));
            break;
    }
}
*/
//Evaluates abstract syntax tree
/*void evaluate(struct tree_node* node)
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
    }
    else if(node->type == CREAD)
    {
            if(node->ptr1->data_type == INT)
                scanf("%d",node->ptr1->symbol->binding + exp_evaluate(node->ptr1->offset));
            else
            {
                char temp[6];
                scanf("%s",temp);
                if(strcmp(temp,"TRUE") == 0)
                    *(node->ptr1->symbol->binding + exp_evaluate(node->ptr1->offset)) = 1;
                else if(strcmp(temp,"FALSE") == 0)
                    *(node->ptr1->symbol->binding + exp_evaluate(node->ptr1->offset)) = 0;
                else
                {
                    printf("Error: Line Number %d Invalid value for boolean identifier %s",yylineno,node->ptr1->name);
                    exit(5);
                }
            }
    }
    else if(node->type == CWRITE)
    {
        int rhs = exp_evaluate(node->ptr1);
        if(node->ptr1->data_type == INT)
            printf("%d\n",rhs);
        else
            if(rhs == 0)
                printf("FALSE\n");
            else
                printf("TRUE\n");
    }
    else if(node->type == CIF)
    {
        if(exp_evaluate(node->ptr1))
            evaluate(node->ptr2);
    }
    else if(node->type == CIFELSE)
    {
        if(exp_evaluate(node->ptr1))
            evaluate(node->ptr2);
        else
            evaluate(node->ptr3);
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
*/
struct tree_node* mkDeclNode(int decl_type,struct tree_node* ptr1, struct tree_node* ptr2)
{
    struct tree_node* Node = (struct tree_node*) malloc(sizeof(struct tree_node));
    Node->type = decl_type;
    Node->ptr1 = ptr1;
    Node->ptr2 = ptr2;

    return Node;
}

struct tree_node* mkIdListNode(int decl_type,int data_type,struct tree_node* ptr1)
{
    struct tree_node* Node = (struct tree_node*) malloc(sizeof(struct tree_node));

    Node->type = decl_type;
    Node->data_type = data_type;
    //Node->ptr1 = LeftNode;
    Node->ptr1 = ptr1;

    return Node;
}

struct tree_node* mkDeclID(int decl_type, char* name, int size)
{
    struct tree_node* Node = (struct tree_node*) malloc(sizeof(struct tree_node));
    Node->type = decl_type;
    Node->size = size;
    Node->name = name;

    return Node;
}

void declare_type(struct tree_node* root, int data_type)
{

    if(root->type == CIDLIST)
    {
        declare_type(root->ptr1,data_type);
        declare_type(root->ptr2,data_type);
    }
    else if(root->type == DID)
    {
       if(Glookup(root->name))
       {
            printf("Error!!!. Line Number %d Identifier %s already declared previously.",yylineno,root->name);
            exit(2);
       }
       else
       {
            Ginstall(root->name,data_type,root->size);
       }
    }
}

void declare(struct tree_node* root)
{   
    if(root->type == CDECLIST)
    {
        declare(root->ptr1);
        declare(root->ptr2);
    }
    else if(root->type == CDECL)
    {
        declare_type(root->ptr1,root->data_type);    
    }
}

struct tree_node* mkFunc(char* name, struct tree_node* arglist)
{
    struct tree_node* node = (struct tree_node*)malloc(sizeof(struct tree_node));
    node->type = CFUNCCALL;
    node->name = name;
    node->arglist = arglist;
    struct Gsymbol* ret = Glookup(name);
    if(ret == NULL)
    {
        printf("Function not declared before use\n");
        exit(1);
    }
    struct tree_node* temp1 = arglist;
    struct arg_node* temp = ret->args;
    while(temp!=NULL && temp1!=NULL)
    {
        if(temp1->type == CARG)
        {
            if(temp1->ptr2->data_type != temp->type)
            {
                printf("Error: Argument types do not match \n");
                exit(1);
            }
        }
        /*else
        {
            if(temp1->data_type != temp->type)
            {
                printf("Error: Argument types do not match \n");
                exit(1);
            }
        }*/
        temp1 = temp1->ptr1;
        temp = temp->next;
    }
    if(temp!=NULL || temp1!=NULL)
    {

        printf("Error: Mismatched number of arguments \n");
        exit(1);
    }
    node->data_type = ret->type;
    node->symbol = ret;

    return node;
}

struct tree_node* mkArgNode(int type, struct tree_node* ptr1, struct tree_node* ptr2)
{
    struct tree_node* node = (struct tree_node*) malloc(sizeof(struct tree_node));
    node->type = type;
    node->ptr1 = ptr1;
    node->ptr2 = ptr2;

    return node;
}

void printArgNode(struct tree_node* root)
{
    while(root!= NULL)
    {
        if(root->type == CARG)
        {
            printf("%d\n",root->ptr2->data_type);
        }
        else
        {
            printf("%d\n",root->data_type);
        }
        root = root->ptr1;
    }
}

struct tree_node* mkFuncDefNode(char* name, struct tree_node* body,int data_type)
{
    struct tree_node* node = (struct tree_node*)malloc(sizeof(struct tree_node));
    node->type = CFUNCDEF;
    node->data_type = data_type;
    node->ptr1 = body;
    node->symbol = Glookup(name);
    node->name = name;

    return node;
}

struct tree_node* mkMainDefNode(struct tree_node* body)
{
    struct tree_node* node = (struct tree_node*)malloc(sizeof(struct tree_node));
    node->type = CMAIN;
    node->data_type = INT;
    node->ptr1 = body;
    node->symbol = NULL;

    return node;
}
