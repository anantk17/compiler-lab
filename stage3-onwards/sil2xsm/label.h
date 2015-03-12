struct Label
{
    char* name;
    int address;
    struct Label* next;
};

struct LabelTable
{
    struct Label* head;
    struct Label* tail;
};

void LabelInstall(char* name, int address);

int LabelLookup(char* name, int offset);

void printLabels();
