%{
    #include <stdio.h>
    #include "label.h"
    int address = 0;
    int addr = 0;
    int pass = 1;
    struct LabelTable lt;
%}


%x PASS1


%%

    int i;
    if (pass == 1) BEGIN (PASS1);
    if (pass == 2) BEGIN (INITIAL);
    
<PASS1>{

[a-z0-9A-Z]+:   {yytext[yyleng-1] = '\0';LabelInstall(strdup(yytext),address); }


\n              {address+= 2;}

.               {}


}
"MOV BP, 0"     {printf("MOV BP, 1535");}
"MOV SP,0"     {printf("MOV SP, 1535");}
"START"         {printf("START");}
[a-z0-9A-Z]+:   {} 

JMP|CALL|JZ|JNZ|MOV|R[0-7]|RET|SP|BP|ADD|SUB|MUL|DIV|MOD|INR|DCR|LT|GT|EQ|NE|GE|LE|PUSH|POP|IN|OUT|\[R[0-7]\]|\[[0-9]+\]|\[SP\]|\[BP\]|-?[0-9]+|[\t]* {printf("%s",yytext);}
HALT\n        {printf("MOV R0, 10\n");
                printf("PUSH R0\n");
                printf("INT 7\n");
            }
[a-z0-9A-Z]+    {addr= LabelLookup(strdup(yytext),0);
                printf("%d",addr);}
.         {printf("%s",yytext);}

%%

int yywrap(void)
{
    return 1;
}

int main(int argc, char* argv[])
{
    FILE * fp;
    if(argc > 1)
    {
        fp = fopen(argv[1],"r");
        if(fp)
            yyin = fp;
    }
    yylex();
    pass = 2;
    fseek(fp,0,SEEK_SET);
    yyin = fp;
    yylex();
    return 0;
}
