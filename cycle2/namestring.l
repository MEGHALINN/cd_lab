%{
    #include <stdio.h>
%}

%%
.*megh.*    {printf("Rejected contains substring 'megh'");}
.*          {printf("Accepted %s\n",yytext);}
%%

int yywrap(){
    return 1;
}

int main(){
    yylex();
    return 0;
}