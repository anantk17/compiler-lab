#include <stdio.h>
#include "exptree.h"
#include "symboltable.h"
#include "sim.h"

extern struct LocalTable lt;
extern struct SymbolTable st;
extern struct arg_list alist;
extern FILE* outFile;

int gen_code(struct tree_node* node)
{
    if(node == NULL)
        return -1;     
    else if(node->type == CRET)
    {
        int begin = current_reg;
        int result1 = gen_code(node->ptr1);
        fprintf(outFile,"MOV R%d, BP\n",current_reg);
        fprintf(outFile,"MOV R%d, 2\n",current_reg+1);
        fprintf(outFile,"SUB R%d, R%d\n",current_reg,current_reg+1);
        fprintf(outFile,"MOV [R%d], R%d\n",current_reg,result1);
        current_reg = begin;
        /*printf("MOV R%d, %d\n", current_reg,lt.memory);
        printf("SUB SP, R%d\n",current_reg);*/
        int temp = 1;
        while(temp <= lt.memory)
        {
            fprintf(outFile,"POP R%d\n",current_reg);
            temp++;
        }
        fprintf(outFile,"POP BP\n");
        fprintf(outFile,"RET\n");
        current_reg = begin;
        return -1;
    }
    else if(node->type == CFUNC)
    {
        gen_code(node->ptr1);
        gen_code(node->ptr2);
        return -1;
    }
    else if(node->type == CFUNCDEF)
    {
        fprintf(outFile,"%s:",node->name);
        fprintf(outFile,"PUSH BP\n");
        fprintf(outFile,"MOV BP, SP\n");
        /*printf("MOV R%d, %d\n",current_reg,lt.memory);
        printf("ADD SP, R%d\n",current_reg);*/
        int temp = lt.memory;
        while(temp>=1)
        {
            fprintf(outFile,"PUSH R0\n");
            temp --;
        }
        gen_code(node->ptr1);
        return -1;
    }
    else if(node->type == CMAIN)
    {
        fprintf(outFile,"main:");
        fprintf(outFile,"PUSH BP\n");
        fprintf(outFile,"MOV BP,SP\n");
        int temp = lt.memory;
        while(temp >= 1)
        {
            fprintf(outFile,"PUSH R0\n");
            temp--;
        }
        gen_code(node->ptr1);
        return -1;
    }
    else if(node->type == CSLIST)
    {
        gen_code(node->ptr1);
        gen_code(node->ptr2);
    }
    else if(node->type == CNUMBER)
    {
        fprintf(outFile,"MOV R%d, %d\n",current_reg,node->value);
        current_reg++;
        return current_reg-1;
    }
    else if(node->type == CBOOL)    
    {
        fprintf(outFile,"MOV R%d, %d\n",current_reg,node->value);
        current_reg++;
        return current_reg -1;
    }
    else if(node->type == CID)
    {
        int begin = current_reg;
        //int result_reg = gen_code(node->offset);
        //printf("MOV R%d, %d\n",current_reg,node->symbol->binding);
        //int addr_reg = current_reg;
        //current_reg++;
        int result_reg = gen_code(node->offset);
        
        if(node->lsymbol != NULL)
        {
            fprintf(outFile,"MOV R%d, %d\n",current_reg,node->lsymbol->binding);
            int result1 = current_reg;
            current_reg++;
            fprintf(outFile,"MOV R%d, BP\n",current_reg);
            fprintf(outFile,"ADD R%d, R%d\n",result1,current_reg);
            result_reg = result1;
            if(node->lsymbol->isRef == 1)
            {
                fprintf(outFile,"MOV R%d, [R%d]\n",result_reg,result_reg);
            }

        }
        else
        {
           fprintf(outFile,"MOV R%d, %d\n",current_reg,node->symbol->binding);
            if(result_reg!=-1)
                fprintf(outFile,"ADD R%d, R%d\n",result_reg,current_reg);
            else
                result_reg = current_reg;
        }
        fprintf(outFile,"MOV R%d, [R%d]\n",result_reg,result_reg);
        
        current_reg = begin + 1;
        return result_reg;
    }
    else if(node->type == ASSG)
    {

        int begin = current_reg;
        int result_reg1 = gen_code(node->ptr2);
        int result_reg = gen_code(node->ptr1->offset);
        if(node->ptr1->lsymbol != NULL)
        {
            current_reg++;
            fprintf(outFile,"MOV R%d, %d\n",current_reg, node->ptr1->lsymbol->binding);
            int result1 = current_reg;
            current_reg++;
            fprintf(outFile,"MOV R%d, BP\n",current_reg);
            fprintf(outFile,"ADD R%d, R%d\n",result1,current_reg);
            result_reg = result1;
            if(node->ptr1->lsymbol->isRef == 1)
                fprintf(outFile,"MOV R%d, [R%d]\n",result_reg,result_reg);

        }
        else
        {
            fprintf(outFile,"MOV R%d, %d\n", current_reg, node->ptr1->symbol->binding);
            if(result_reg!=-1)
            {
                fprintf(outFile,"ADD R%d, R%d\n", result_reg, current_reg);
            }
            else
            {
                result_reg = current_reg;
            }
            //int address_reg = current_reg
            //int result_reg1 = gen_code(node->ptr2);
        }
        fprintf(outFile,"MOV [R%d], R%d\n",result_reg, result_reg1);
        current_reg = begin;
        return begin;
    }
    else if(node->type == CWRITE)
    {
        int begin = current_reg;
        int result_reg = gen_code(node->ptr1);
        fprintf(outFile,"OUT R%d\n",result_reg);
        current_reg = begin;
        return current_reg;
    }
    else if(node->type == CREAD)
    {
        int begin = current_reg;

        fprintf(outFile,"IN R%d\n",current_reg);
        int read_val = current_reg;
        current_reg++;
        int add_reg = current_reg;
        if(node->ptr1->lsymbol != NULL)
        {
            fprintf(outFile,"MOV R%d, %d\n", current_reg, node->ptr1->lsymbol->binding);
            int addr = current_reg;
            current_reg++;
            fprintf(outFile,"MOV R%d, BP\n",current_reg);
            fprintf(outFile,"ADD R%d, R%d\n",addr,current_reg);
            if(node->ptr1->lsymbol->isRef == 1)
                fprintf(outFile,"MOV R%d, [R%d]\n",add_reg,add_reg);

        }
        else
        {
            fprintf(outFile,"MOV R%d, %d\n",current_reg,node->ptr1->symbol->binding);
   
            current_reg++;
            int result_reg = gen_code(node->ptr1->offset);
            if(result_reg != -1)
            {
                fprintf(outFile,"ADD R%d, R%d\n",add_reg,result_reg);
            }
        }
        
        fprintf(outFile,"MOV [R%d], R%d\n",add_reg,read_val);

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
            case '+' :  fprintf(outFile,"ADD R%d, R%d\n",result_reg1,result_reg2);
                        break;
            case '-' :  fprintf(outFile,"SUB R%d, R%d\n",result_reg1,result_reg2);
                        break;
            case '*' :  fprintf(outFile,"MUL R%d, R%d\n",result_reg1,result_reg2);
                        break;
            case '/' :  fprintf(outFile,"DIV R%d, R%d\n",result_reg1,result_reg2);
                        break;
            case '%' :  fprintf(outFile,"MOD R%d, R%d\n",result_reg1,result_reg2);
                        break;
            case '>' :  fprintf(outFile,"GT R%d, R%d\n",result_reg1,result_reg2);
                        break;
            case '<' :  fprintf(outFile,"LT R%d, R%d\n",result_reg1,result_reg2);
                        break;
            case ISEQUAL :  fprintf(outFile,"EQ R%d, R%d\n",result_reg1,result_reg2);
                            break;
            case ISNTEQUAL :    fprintf(outFile,"NE R%d, R%d\n",result_reg1,result_reg2);
                                break;
            case CGTE : fprintf(outFile,"GE R%d, R%d\n",result_reg1,result_reg2);
                        break;
            case CLTE : fprintf(outFile,"LE R%d, R%d\n",result_reg1,result_reg2);
                        break;
            case CAND : fprintf(outFile,"MUL R%d, R%d\n",result_reg1,result_reg2);
                        break;
            case COR  : fprintf(outFile,"JNZ R%d, L%d\n",result_reg1,current_label);
                        fprintf(outFile,"JNZ R%d, L%d\n",result_reg2,current_label);
                        int l1 = current_label;
                        current_label++;
                        fprintf(outFile,"MOV R%d, %d\n",result_reg1,0);
                        fprintf(outFile,"JMP L%d\n",current_label);
                        int l2 = current_label;
                        current_label++;
                        fprintf(outFile,"L%d: MOV R%d, %d\n",l1,result_reg2,1);
                        fprintf(outFile,"L%d:\n",l2);
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
        fprintf(outFile,"INR R%d\n",result_reg1);
        fprintf(outFile,"MOV R%d, 2\n",current_reg);
        fprintf(outFile,"MOD R%d,R%d\n",result_reg1,current_reg);
        current_reg = begin+1;
        return result_reg1;
    }
    else if(node->type == CIF)
    {
        int begin = current_reg;
        int label = current_label;
        int result_reg1 = gen_code(node->ptr1);
        fprintf(outFile,"JZ R%d, L%d\n",result_reg1,label);
        current_label++;
        current_reg--;
        int result_reg2 = gen_code(node->ptr2);
        fprintf(outFile,"L%d: ",label);
        return 0;
    }
    else if(node->type == CIFELSE)
    {
        int begin = current_reg;
        int label = current_label;
        int result_reg1 = gen_code(node->ptr1);
        fprintf(outFile,"JZ R%d, L%d\n",result_reg1,label);
        current_reg--;
        current_label++;
        int result_reg2 = gen_code(node->ptr2);
        int label1 = current_label;
        fprintf(outFile,"JMP L%d\n",label1);
        fprintf(outFile,"L%d: ",label);
        current_label++;
        int result_reg3 = gen_code(node->ptr3);
        fprintf(outFile,"L%d: ",label1);
        return 0;
    }
    else if(node->type == CWHILE)
    {
        int begin = current_reg;
        int loop_entry_label = current_label;
        fprintf(outFile,"L%d: ",loop_entry_label);
        current_label++;
        int result_reg1 = gen_code(node->ptr1);
        int loop_exit_label = current_label;
        fprintf(outFile,"JZ R%d, L%d\n",result_reg1,loop_exit_label);
        current_label++;
        current_reg--;
        gen_code(node->ptr2);
        fprintf(outFile,"JMP L%d\n",loop_entry_label);
        fprintf(outFile,"L%d: ",loop_exit_label);
        return 0;
    }
    else if(node->type == CFUNCCALL)
    {
        int used = current_reg - 1;
        int i = used;
        while(i >=  0)
        {
            fprintf(outFile,"PUSH R%d\n",i);
            i --;
        }
        struct tree_node* temp = node->arglist;
        struct arg_node* temp1 = node->symbol->args;
        while(temp != NULL && temp1 != NULL)
        {
            if(temp1->isRef == 1)
            {
                if(temp->ptr2->type == CID)
                {
                    int result_reg = gen_code(temp->ptr2->offset);
                    if(temp->ptr2->lsymbol != NULL && temp->ptr2->lsymbol->isRef == 1)
                    {
                        current_reg++;
                        fprintf(outFile,"MOV R%d, %d\n",current_reg,temp->ptr2->lsymbol->binding);
                        int result1 = current_reg;
                        current_reg++;
                        fprintf(outFile,"MOV R%d, BP\n",current_reg);
                        fprintf(outFile,"ADD R%d, R%d\n",result1,current_reg);
                        fprintf(outFile,"MOV R%d, [R%d]\n",result1,result1);
                        result_reg = result1;
                    }
                    else if(temp->ptr2->lsymbol != NULL)
                    {
                        current_reg++;
                        fprintf(outFile,"MOV R%d, %d\n",current_reg, temp->ptr2->lsymbol->binding);
                        int result1 = current_reg;
                        current_reg++;
                        fprintf(outFile,"MOV R%d, BP\n",current_reg);
                        fprintf(outFile,"ADD R%d, R%d\n",result1,current_reg);
                        result_reg = result1;
                    }
                    else
                    {
                        fprintf(outFile,"MOV R%d, %d\n", current_reg, temp->ptr2->symbol->binding);
                        if(result_reg!=-1)
                        {
                            fprintf(outFile,"ADD R%d, R%d\n", result_reg, current_reg);
                        }
                        else
                        {
                            result_reg = current_reg;
                        }
                    }
                        fprintf(outFile,"PUSH R%d\n",result_reg);
                        current_reg --;
            //int address_reg = current_reg
            //int result_reg1 = gen_code(node->ptr2);
                    
                }
            }
            else
            {
                int ret_reg = gen_code(temp->ptr2);
                fprintf(outFile,"PUSH R%d\n",ret_reg);
                current_reg--;
            }
            temp = temp->ptr1;
            temp1 = temp1->next;
        }
        fprintf(outFile,"PUSH R0\n");
        fprintf(outFile,"CALL %s\n",node->name);
        fprintf(outFile,"POP R%d\n",current_reg);
        current_reg++;
        i = 0;
        temp = node->arglist;
        while(temp != NULL)
        {
            fprintf(outFile,"POP R%d\n",current_reg);
            temp = temp->ptr1;
        }
        while(i <= used)
        {
            fprintf(outFile,"POP R%d\n",i);
            i ++;
        }
        return current_reg-1;
    }

}


