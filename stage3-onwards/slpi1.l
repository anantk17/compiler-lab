%{ 
    #include <stdio.h>
    //#include "y.tab.h"
    //extern YYSTYPE yylval;
%}


%%

[0-9]+  {printf("DIGIT\t");}
[/-<>()*+\n;=]    {printf("%s",yytext);}
"=="    {printf("EQUALITY");}
read    {printf("READ");}
write   {printf("WRITE");}
if      {printf("IF");}
then    {printf("THEN");}
endif   {printf("ENDIF");}
while   {printf("WHILE");}
do      {printf("DO");}
endwhile {printf("ENDWHILE");}
integer {printf("TINTEGER");}
[A-Za-z][A-Za-z0-9]* {printf("ID");}
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

