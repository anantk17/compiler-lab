%{ 
    #include <stdio.h>
    #include "y.tab.h"
    extern YYSTYPE yylval;
%}


%%

[0-9]+  {yylval.ival = atoi(yytext);return DIGIT;}
[a-z]   {yylval.name = yytext[0];return  ID;}
[/-<>()*+\n;=]    {return *yytext;}
"=="    {return EQUALITY;}
read    {return READ;}
write   {return WRITE;}
if      {return IF;}
then    {return THEN;}
endif   {return ENDIF;}
while   {return WHILE;}
do      {return DO;}
endwhile {return ENDWHILE;}
.	{}

%%

yywrap()
{
    return 1;
}
