//Constants for the type attribute of the tree node
#define CNUMBER 0
#define CID 1
#define CSLIST 2
#define ASSG 3
#define CREAD 4
#define CWRITE 5
#define CWHILE 6
#define CIF 7
#define ISEQUAL 8

struct tree_node{
        //type : 0 - NUMBER, 1 - ID ,2 - SLIST, 3 - ASSG, 4 - READ, 5 - WRITE, '+' - Addition, '*'
        //-Multiplication, '-' - Subtraction
        int type;
        //if type is 1, name defines identifier name
        char name;
        //integer value of number at node, valid only if type is 0
        int value;
        //argument name
        struct tree_node *arglist;
        //ptr1 and ptr2 are NULL for leaf nodes
        struct tree_node *ptr1, *ptr2;
    };

struct tree_node* mkOpNode(int op, struct tree_node* ptr1, struct tree_node* ptr2);

struct tree_node* mkstmtNode(int stmt, struct tree_node* ptr1, struct tree_node* ptr2);

struct tree_node* mkID(char name);

struct tree_node* mkNUM(int val);

int exp_evaluate(struct tree_node* node);

void evaluate(struct tree_node* node);

int variables[26];

int initialized[26];
