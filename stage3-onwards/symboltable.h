#define INT 0

struct Gsymbol
{
    char *name;     //name of symbol
    int type;       //type can be INTEGER for now
    int size;       //size of array
    int* binding;   //pointer to the memory location allocated for symbol

    struct Gsymbol *next;  //pointer to next node in the linked list
};

struct SymbolTable
{
    struct Gsymbol* head;
};

struct Gsymbol* Glookup(char* name);

void Ginstall(char* name, int type,int size);
