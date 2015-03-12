#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "label.h"

extern struct LabelTable lt;

void LabelInstall(char* name, int address)
{
    struct Label *temp = (struct Label*)malloc(sizeof(struct Label));
    
    temp->name = name;
    temp->address = address;

    if(lt.head == NULL)
    {
        lt.head = temp;
        lt.tail = temp;
        temp->next = NULL;
    }
    else
    {
        lt.tail->next = temp;
        temp->next = NULL;
        lt.tail = temp;
    }
}

int LabelLookup(char* name, int offset)
{
    int len = strlen(name);
    char *lname = (char*)malloc(sizeof(len));
    strcpy(lname,name+offset);
    struct Label* temp = lt.head;
    for(;temp != NULL;temp=temp->next)
    {
        if(strcmp(temp->name,lname) == 0)
            return temp->address;
    }
    
    return -1;
}

void printLabels()
{
    struct Label* temp = lt.head;
    for(;temp!=NULL;temp =temp->next)
    {
        printf("%s\n", temp->name);
    }
}
