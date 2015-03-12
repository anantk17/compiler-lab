#define INT 0
#define BOOL 1
#define VOID 2

struct arg_node
{
    char* name;
    int type;
    int isRef;
    struct arg_node* next;
};

struct arg_list
{
    struct arg_node* head;
};

struct Gsymbol
{
    char *name;     //name of symbol
    int type;       //type can be INTEGER for now
    int size;       //size of array
    int binding;   //pointer to the memory location allocated for symbol
    struct arg_node* args;
    int defined;
    struct Gsymbol *next;  //pointer to next node in the linked list
};

struct SymbolTable
{
    struct Gsymbol* head;
    struct Gsymbol* tail;
    int memory;
};

struct Lsymbol
{
    char *name;
    int type;
    int size;
    int binding;
    int isRef;
    struct Lsymbol *next;
};

struct LocalTable
{
    struct Lsymbol* head;
    struct Lsymbol* tail;
    int memory;
    int argmem;
};

struct Gsymbol* Glookup(char* name);

void Ginstall(char* name, int type,int size);

void Linstall(char* name, int type);

struct Lsymbol* Llookup(char* name);

void addArgs(char* name, int type, int isref);

void installArgs(char* name);

struct arg_node* lookupArgs(char* name,int type);

void printArgs();

void printLocalST();

void printGlobalST();

void printGlobalArgs();
