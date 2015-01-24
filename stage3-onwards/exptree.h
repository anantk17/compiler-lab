//Constants for the type attribute of the tree node
#define CNUMBER 0   //NUMBER
#define CID 1       //IDENTIFIER
#define CSLIST 2    //STATEMENT LIST
#define ASSG 3      //ASSIGNMENT ID = E
#define CREAD 4     //READ(ID)
#define CWRITE 5    //WRITE(E)
#define CWHILE 6    //WHILE(COND)
#define CIF 7       //IF(COND)
#define ISEQUAL 8   //==

struct tree_node{ 
    //type takes one of the constants defined above and denotes the type of node
    int type;
    //name is required if node is of type CID
    //char name;
    //integer value of number at node, valid only if type is CNUMBER
    int value;
    //Offset required for array variables
    struct tree_node* offset;
    //list of nodes passed as arguments to functions
    struct tree_node *arglist;
    //ptr1 and ptr2 are pointers to child nodes
    //NULL in case of leaf nodes (NUM or ID)
    struct tree_node *ptr1, *ptr2;
    //Pointer to entry in symbol table
    struct Gsymbol* symbol;
    };

struct tree_node* mkOpNode(int op, struct tree_node* ptr1, struct tree_node* ptr2);

struct tree_node* mkstmtNode(int stmt, struct tree_node* ptr1, struct tree_node* ptr2);

struct tree_node* mkID(char* name,struct tree_node* offset_expr);

struct tree_node* mkNUM(int val);

int exp_evaluate(struct tree_node* node);

void evaluate(struct tree_node* node);

//table for storing the current value for the variables a-z
int variables[26];

//table for checking whether variables are initialized
int initialized[26];
