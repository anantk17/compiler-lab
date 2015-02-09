#define INT 0
#define BOOL 1
#define VOID 2

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
    struct Gsymbol* tail;
};

struct Gsymbol* Glookup(char* name);

void Ginstall(char* name, int type,int size);

int data_type(struct Gsymbol* var);

void print_st();
