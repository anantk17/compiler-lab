%{
    #include<stdio.h>
    int line_count = 0;
    int word_count = 0;
    int char_count = 0;
%}

enter (\n)
word ([0-9a-zA-Z]+)

%option noyywrap

%%

{enter} {line_count++;}
{word}  {word_count++;char_count+=yyleng;}

%%
int main(int argc, char* argv[])
{
    if(argc > 1)
    {
        FILE* fp = fopen(argv[1],"r");
        if(fp)
            yyin = fp;
    }
    yylex();
    printf("%d\t%d\t%d",line_count,word_count,char_count);
    return 1;
}
