%{
    #include <stdio.h>
    #include <stdlib.h>
    int yylex(void);
    void yyerror(const char*s);
%}
%token IDENTIFIER INVALID
%start program

%%
program : IDENTIFIER 
        {
            printf("Valid Identifier\n");
        }
        | INVALID
        {
            printf("Invalid Identifier\n");
        }
        ;
%%

int main(){
    printf("Enter the String : ");
    yyparse();
    return 0;
}

void yyerror(const char*s){
}