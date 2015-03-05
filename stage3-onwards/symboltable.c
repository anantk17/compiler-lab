#include "symboltable.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct SymbolTable st;
struct LocalTable lt;
struct arg_list alist;
struct arg_node* func_args;
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
    struct Gsymbol* temp = st.tail;
    if(temp == NULL)
    {
        struct Gsymbol* symbol = (struct Gsymbol*) malloc(sizeof(struct Gsymbol));
        symbol->name = name;
        symbol->type = type;
        symbol->size = size;
        symbol->args = alist.head;
        symbol->defined = 0;
        if(size == 0)
            func_args = symbol->args;
        
        //if(type == 0)
        if(symbol->size>=1)
            symbol->binding= st.memory;//(int*)malloc(sizeof(int)*size);
        symbol->next = NULL;
        //if(size > 1)
        //    symbol->array = 1;
        st.head = symbol;
        st.tail = symbol;
        st.memory = st.memory + size;
    }
    else
    {
        //for(temp = st.head;temp->next!=NULL;temp = temp->next);
        
        struct Gsymbol* symbol = (struct Gsymbol*) malloc(sizeof(struct Gsymbol));
        symbol->name = name;
        symbol->type = type;
        symbol->size = size;
        symbol->args = alist.head;
        symbol->defined = 0;
        func_args = symbol->args;
        if(size == 0)
            func_args = symbol->args;

        //if(type == 0)
        if(symbol->size >= 1)
            symbol->binding= st.memory;//(int*)malloc(sizeof(int)*size);
        symbol->next = NULL;
        //if(size > 1)
        //    symbol->array = 1;
        st.tail->next = symbol;
        st.tail = st.tail->next;
        st.memory = st.memory + size;

    }
}

void Linstall(char* name, int type)
{
    struct Lsymbol* temp = lt.tail;
    if(temp == NULL)
    {
        struct Lsymbol* symbol = (struct Lsymbol*) malloc(sizeof(struct Lsymbol));
        symbol->name = name;
        symbol->type = type;
        symbol->size = 1;
        symbol->isRef =  0;
        //if(type == 0)
        symbol->binding= lt.memory;//(int*)malloc(sizeof(int)*size);
        symbol->next = NULL;
        //if(size > 1)
        //    symbol->array = 1;
        lt.head = symbol;
        lt.tail = symbol;
        lt.memory = lt.memory + 1;
    }
    else
    {
        //for(temp = st.head;temp->next!=NULL;temp = temp->next);
        
        struct Lsymbol* symbol = (struct Lsymbol*) malloc(sizeof(struct Lsymbol));
        symbol->name = name;
        symbol->type = type;
        symbol->size = 1;
        symbol->isRef = 0;
        //if(type == 0)
            symbol->binding= lt.memory;//(int*)malloc(sizeof(int)*size);
        symbol->next = NULL;
        //if(size > 1)
        //    symbol->array = 1;
        lt.tail->next = symbol;
        lt.tail = lt.tail->next;
        lt.memory = lt.memory + 1;

    }
}
struct Lsymbol* Llookup(char* name)
{
    struct Lsymbol* temp;
    for(temp = lt.head;temp!=NULL;temp = temp->next)
    {
        if(strcmp(temp->name,name) == 0)
            return temp;
    }

    return NULL;
}


void addArgs(char* name, int type,int isref)
{
    struct arg_node* temp;
    temp = (struct arg_node*)malloc(sizeof(struct arg_node));
    temp->name = name;
    temp->type = type;
    temp->isRef = isref;
    if(alist.head == NULL)
    {
        alist.head = temp;
        temp->next = NULL;
    }
    else
    {
        temp->next = alist.head;
        alist.head = temp;
    }
}

struct arg_node* lookupArgs(char* name,int type)
{
    struct arg_node* temp;
    
    for(temp = alist.head;temp!=NULL;temp = temp->next)
    {
        if(strcmp(temp->name,name)==0 && type == temp->type)
            return temp;
    }
    return NULL;
}

void installArgs(char* name)
{

    struct arg_node* temp1 = alist.head;
    struct Gsymbol* symbol = Glookup(name);
    if(symbol->defined != 0)
    {
        printf("Error: function already defined!\n");
        exit(1);
    }
    symbol->defined = 1;
    struct arg_node* temp2 = symbol->args;
    
    while(temp1!= NULL && temp2!=NULL)
    {
        if(strcmp(temp1->name,temp2->name) != 0 || temp1->type != temp2->type || temp1->isRef != temp2->isRef)
        {
            printf("Argument mismatch in declaration and definition\n");
            exit(1);
        }
        struct Lsymbol * temp = lt.tail;
        struct Lsymbol* symbol = (struct Lsymbol*)malloc(sizeof(struct Lsymbol));
        symbol->name = temp1->name;
        symbol->type = temp1->type;
        symbol->isRef = temp1->isRef;
        symbol->size = 1;

        if(temp == NULL)
        {
            lt.head = symbol;
            lt.tail = symbol;
            symbol->next = NULL;
            symbol->binding = lt.argmem;
            lt.argmem = lt.argmem - 1;
        }
        else
        {
            temp->next = symbol;
            temp = temp->next;
            lt.tail = symbol;
            symbol->next = NULL;
            symbol->binding = lt.argmem;
            lt.argmem  = lt.argmem - 1;
        }
        temp1 = temp1->next;
        temp2 = temp2->next;
    }
    if(temp1!= NULL || temp2!=NULL)
    {
        printf("Argument mismatch in the declaration and definition sections\n");
        exit(1);
    }
}

void printArgs()
{
    struct arg_node* temp = alist.head;
    for(;temp != NULL;temp=temp->next)
    {
        printf("%s %d\n",temp->name, temp->type);
    }
}

void printLocalST()
{
    struct Lsymbol* temp = lt.head;
    for(;temp != NULL;temp=temp->next)
    {
        printf("%s %d\n", temp->name , temp->binding);
    }
}

void clear_args()
{
    alist.head = NULL;
}

void clear_local()
{
    lt.head = NULL;
    lt.tail = NULL;
    lt.memory = 1;
    lt.argmem = -3;
}
