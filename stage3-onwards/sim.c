#include <stdio.h>
#include "exptree.h"
#include "symboltable.h"
#include "sim.h"

int gen_code(struct tree_node* node)
{
    if(node == NULL)
        return -1;     

    if(node->type == CPGM)
    {
        printf("START\n");
        gen_code(node->ptr1);
        printf("HALT\n");
        return 0;
    }
    else if(node->type == CSLIST)
    {
        gen_code(node->ptr1);
        gen_code(node->ptr2);
    }
    else if(node->type == CNUMBER)
    {
        printf("MOV R%d, %d\n",current_reg,node->value);
        current_reg++;
        return current_reg-1;
    }
    else if(node->type == CBOOL)    
    {
        printf("MOV R%d, %d\n",current_reg,node->value);
        current_reg++;
        return current_reg -1;
    }
    else if(node->type == CID)
    {
        int begin = current_reg;
        //int result_reg = gen_code(node->offset);
        printf("MOV R%d, %d\n",current_reg,node->symbol->binding);
        int addr_reg = current_reg;
        current_reg++;
        int result_reg = gen_code(node->offset);
        if(result_reg!=-1)
            printf("ADD R%d, R%d\n",addr_reg,result_reg);
                     
        printf("MOV R%d, [R%d]\n",addr_reg,addr_reg);
        result_reg = addr_reg;
        current_reg = result_reg + 1;
        return result_reg;
    }
    else if(node->type == ASSG)
    {
        int begin = current_reg;
        int result_reg = gen_code(node->ptr1->offset);
        printf("MOV R%d, %d\n", current_reg, node->ptr1->symbol->binding);
        if(result_reg!=-1)
        {
            printf("ADD R%d, R%d\n", current_reg, result_reg);
        }
        int address_reg = current_reg;
        current_reg++;
        result_reg = gen_code(node->ptr2);
        printf("MOV [R%d], R%d\n",address_reg, result_reg);
        current_reg = begin;
        return begin;
    }
    else if(node->type == CWRITE)
    {
        int begin = current_reg;
        int result_reg = gen_code(node->ptr1);
        printf("OUT R%d\n",result_reg);
        current_reg = begin;
        return current_reg;
    }
    else if(node->type == CREAD)
    {
        int begin = current_reg;

        printf("IN R%d\n",current_reg);
        int read_val = current_reg;
        current_reg++;
        printf("MOV R%d, %d\n",current_reg,node->ptr1->symbol->binding);
        int add_reg = current_reg;
        current_reg++;
        int result_reg = gen_code(node->ptr1->offset);
        if(result_reg != -1)
        {
            printf("ADD R%d, R%d\n",add_reg,result_reg);
        }
        printf("MOV [R%d], R%d\n",add_reg,read_val);

        current_reg = begin;
        return current_reg;
    }
    else if(node->type == '+' || node->type == '-' || node->type == '*' || node->type == '/' || node->type == '%' ||node->type == '<' || node->type=='>' || node->type == ISEQUAL || node->type == ISNTEQUAL || node->type == CLTE || node->type == CGTE || node->type == CAND || node->type == COR)
    {   
        int begin = current_reg;
        int result_reg1, result_reg2;
        if(node->ptr1->type !=  CNUMBER && node->ptr1->type != CID && node->ptr1->type != CBOOL)
        {
            result_reg1 = gen_code(node->ptr1);
        }
        if(node->ptr2->type != CNUMBER && node->ptr2->type != CID && node->ptr2->type != CBOOL)
        {
            result_reg2 = gen_code(node->ptr2);
        }
        if(node->ptr1->type == CNUMBER ||  node->ptr1->type == CID || node->ptr1->type == CBOOL)
        {
            result_reg1 = gen_code(node->ptr1);
        }
        if(node->ptr2->type == CNUMBER || node->ptr2->type == CID || node->ptr2->type == CBOOL)
        {
            result_reg2 = gen_code(node->ptr2);
        }

        switch(node->type)
        {
            case '+' :  printf("ADD R%d, R%d\n",result_reg1,result_reg2);
                        break;
            case '-' :  printf("SUB R%d, R%d\n",result_reg1,result_reg2);
                        break;
            case '*' :  printf("MUL R%d, R%d\n",result_reg1,result_reg2);
                        break;
            case '/' :  printf("DIV R%d, R%d\n",result_reg1,result_reg2);
                        break;
            case '%' :  printf("MOD R%d, R%d\n",result_reg1,result_reg2);
                        break;
            case '>' :  printf("GT R%d, R%d\n",result_reg1,result_reg2);
                        break;
            case '<' :  printf("LT R%d, R%d\n",result_reg1,result_reg2);
                        break;
            case ISEQUAL :  printf("EQ R%d, R%d\n",result_reg1,result_reg2);
                            break;
            case ISNTEQUAL :    printf("NE R%d, R%d\n",result_reg1,result_reg2);
                                break;
            case CGTE : printf("GE R%d, R%d\n",result_reg1,result_reg2);
                        break;
            case CLTE : printf("LE R%d, R%d\n",result_reg1,result_reg2);
                        break;
            case CAND : printf("MUL R%d, R%d\n",result_reg1,result_reg2);
                        break;
            case COR  : printf("ADD R%d, R%d\n",result_reg1,result_reg2);
                        printf("MOV R%d, 2\n",result_reg2);
                        printf("MOD R%d,R%d",result_reg1,result_reg2);
                        break;
        }
        
        current_reg = begin+1;
        return result_reg1;          
    }
    else if(node->type == CNOT)
    {
        int begin = current_reg;
        int result_reg1,result_reg2;
        result_reg1 = gen_code(node->ptr1);
        printf("INR R%d",result_reg1);
        printf("MOV R%d, 2",current_reg);
        printf("MOD R%d,R%d",result_reg1,current_reg);
        current_reg = begin+1;
        return result_reg1;
    }
    else if(node->type == CIF)
    {
        int begin = current_reg;
        int label = current_label;
        int result_reg1 = gen_code(node->ptr1);
        printf("JZ R%d, L%d\n",result_reg1,label);
        current_label++;
        int result_reg2 = gen_code(node->ptr2);
        printf("L%d: ",label);
        return 0;
    }
    else if(node->type == CIFELSE)
    {
        int begin = current_reg;
        int label = current_label;
        int result_reg1 = gen_code(node->ptr1);
        printf("JZ R%d, L%d\n",result_reg1,label);
        current_label++;
        int result_reg2 = gen_code(node->ptr2);
        int label1 = current_label;
        printf("JMP L%d\n",label1);
        printf("L%d: ",label);
        current_label++;
        int result_reg3 = gen_code(node->ptr3);
        printf("L%d: ",label1);
        return 0;
    }
    else if(node->type == CWHILE)
    {
        int begin = current_reg;
        int loop_entry_label = current_label;
        printf("L%d: ",loop_entry_label);
        current_label++;
        int result_reg1 = gen_code(node->ptr1);
        int loop_exit_label = current_label;
        printf("JZ R%d, L%d\n",result_reg1,loop_exit_label);
        current_label++;
        gen_code(node->ptr2);
        printf("JMP L%d\n",loop_entry_label);
        printf("L%d: ",loop_exit_label);
        return 0;
    }

}


