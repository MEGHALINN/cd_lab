%{
    #include "y.tab.h"
%}

%%
"for"                           {return FOR;}
"{"                             {return LP;}
"} "                            {return RP;}
"("                             {return LC;}
")"                             {return RC;}
[A-Za-z_][A-Za-z0-9_]*          {return IDENTIFIER;}
";"                             {return ';' ;}
"="                             {return EQ ;}
">"|"<"|"<="|">="|"=="|"!="     {return RELOP ;}
[0-9]+                          { return NUM ;}
"++"|"--"                       {return INDE;}
"\n"                            {return 0;}
[ \t]                         ;
.                               {return INVALID;}

%%

int yywrap(void){
    return 1;
}