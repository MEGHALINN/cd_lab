%{
    #include "y.tab.h"
    #include <stdlib.h>
%}
%option noyywrap

%%

[0-9]+      {yylval.num=atoi(yytext); return NUMBER;}
[+\-*/()]    { return yytext[0];}
[ \t]+      ;
\n          { return '\n';}
.           {return yytext[0];}

%%

