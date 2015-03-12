#include <stdio.h>
//#include <exptree.h>
//#include <symboltable.h>

int current_reg = 0,current_label=0;

int  gen_code(struct tree_node*);

void free_reg(int num);
