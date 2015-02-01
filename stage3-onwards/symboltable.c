#include "symboltable.h"
#include <stdlib.h>
#include <string.h>

struct SymbolTable st;
struct Gsymbol* Glookup(char* name)
{
    struct Gsymbol* temp;
    for(temp = st.head;temp!=NULL;temp = temp->next)
    {
        if(strcmp(temp->name,name) == 0)
            return temp;
    }

    return NULL;
}

void Ginstall(char* name, int type, int size)
{
    struct Gsymbol* temp = st.head;
    if(temp == NULL)
    {
        struct Gsymbol* symbol = (struct Gsymbol*) malloc(sizeof(struct Gsymbol));
        symbol->name = name;
        symbol->type = type;
        symbol->size = size;
        if(type == 0)
            symbol->binding= (int*)malloc(sizeof(int)*size);
        symbol->next = NULL;

        st.head = symbol;
    }
    else
    {
        for(temp = st.head;temp->next!=NULL;temp = temp->next);
        
        struct Gsymbol* symbol = (struct Gsymbol*) malloc(sizeof(struct Gsymbol));
        symbol->name = name;
        symbol->type = type;
        symbol->size = size;
        if(type == 0)
            symbol->binding= (int*)malloc(sizeof(int)*size);
        symbol->next = NULL;

        temp->next = symbol;
    }
}

void print_st()
{
    struct Gsymbol* temp;
    for(temp = st.head;temp!=NULL;temp = temp->next)
    {
            printf("%s\n",temp->name);
    }
}
