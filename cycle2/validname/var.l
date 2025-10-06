%{
    #include "y.tab.h"
%}
%option noyywrap

%%
[A-Za-z][A-Za-z0-9]*        {printf("%s :Valid Variable\n",yytext);return VARIABLE;}
[ \t\n]+                    ;
.                           {return yytext[0];}
%%

