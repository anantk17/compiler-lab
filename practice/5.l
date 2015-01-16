%{
    #include<stdio.h>
    int num_int = 0, num_float=0;
%}

singlelinecomment "//"
commentstart "/*"
commentend "*/"

%%

{singlelinecomment}(.)*"\n" {printf("Single line comment\n");}
{commentstart}(.)*{commentend}  {printf("Multi line comment\n");}

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
    //printf("%d\t%d\t%d",line_count,word_count,char_count);
    return 1;
}   
