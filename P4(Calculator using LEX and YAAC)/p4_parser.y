%{
    #include <stdio.h>
    #include <stdlib.h>

    int yylex(void);
    void yyerror(const char*s);
%}

%token FOR LP RP LC RC IDENTIFIER EQ RELOP NUM INDE INVALID
%start program

%%
program     : FOR LC init ';' cond ';' increment RC     {printf ("Valid Syntax\n");}
            ;
init        : IDENTIFIER EQ expr
            ;
cond        : IDENTIFIER RELOP expr
            ;
increment   : IDENTIFIER INDE
            | IDENTIFIER EQ expr
            ;
expr        : NUM
            | IDENTIFIER
            ;

%%

int main(){
    printf("Enter a for loop:");
    yyparse();
    return 0;
}

void yyerror(const char*s){
    printf("Invalid Syntax\n");
}