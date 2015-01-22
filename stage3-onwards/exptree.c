#include "exptree.h"
#include <stdio.h>
#include <stdlib.h>

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
            case CNUMBER:
                return node->value;
                break;
            case CID:
                if(initialized[node->name-'a'])
                    return variables[node->name-'a'];
                else
                {
                    printf("uninitialized variable used!!");
                    exit(1);
                    break;
                }
            case '+':
                return exp_evaluate(node->ptr1) + exp_evaluate(node->ptr2);
                break;
            case '-':
                return exp_evaluate(node->ptr1) - exp_evaluate(node->ptr2);
                break;
            case '/':
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
            initialized[node->ptr1->name-'a'] = 1;
        }
        else if(node->type == CREAD)
        {
            scanf("%d",&variables[node->arglist->name -'a']);
            initialized[node->arglist->name-'a'] = 1;
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

