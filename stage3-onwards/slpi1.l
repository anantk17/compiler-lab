%{ 
    #include <stdio.h>
    //#include "y.tab.h"
    //extern YYSTYPE yylval;
%}


%%

[0-9]+  {printf("DIGIT\t %s\t",yytext);}
[,-<>()*+\n;=%/]    {printf("%s\t",yytext);}
"=="    {printf("EQUALITY\t");}
read    {printf("READ\t");}
write   {printf("WRITE\t");}
if      {printf("IF\t");}
then    {printf("THEN");}
endif   {printf("ENDIF");}
while   {printf("WHILE");}
do      {printf("DO");}
endwhile {printf("ENDWHILE");}
integer {printf("INTEGER\t");}
decl[\t\n]    {printf("DECL\t");}
enddecl[\t\n] {printf("ENDDECL\t");}
[A-Za-z][A-Za-z0-9]* {printf("ID\t %s\t",yytext);}
.   {}

%%

yywrap()
{
    return 1;
}

int main()
{
    yylex();
    return 0;
}

