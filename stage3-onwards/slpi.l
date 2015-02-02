%{ 
    #include <stdio.h>
    #include "y.tab.h"
    extern YYSTYPE yylval;
%}


%%

[0-9]+  {yylval.ival = atoi(yytext);return DIGIT;}
[%\[\],/-<>()*+;=]    {return *yytext;}
"AND"   {return AND;}
"OR"    {return OR;}
"NOT"   {return NOT;}
"!="    {return NOTEQUAL;}
"<="    {return LTE;}
">="    {return GTE;}
"=="    {return EQUALITY;}
read    {return READ;}
write   {return WRITE;}
if      {return IF;}
then    {return THEN;}
endif   {return ENDIF;}
while   {return WHILE;}
do      {return DO;}
endwhile {return ENDWHILE;}
integer {return INTEGER;}
decl[\t\n]    {return DECL;}
enddecl[\t\n] {return ENDDECL;}
[ \t\n]     {}
[A-Za-z][A-Za-z0-9]* {yylval.name = strdup(yytext);return ID;}
.   {}

%%

int yywrap(void)
{
    return 1;
}
