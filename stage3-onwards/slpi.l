%{ 
    #include <stdio.h>
    #include "y.tab.h"
    extern YYSTYPE yylval;
%}


%%

[0-9]+  {yylval.ival = atoi(yytext);return DIGIT;}
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
<<<<<<< HEAD
.	{return *yytext;}
=======
integer {return TINTEGER;}
[A-Za-z][A-Za-z0-9]* {yylval.name = yytext; return ID;}
.   {}
>>>>>>> ce8c3a82679b694d7b11617b87526c8c037e500c

%%

yywrap()
{
    return 1;
}
