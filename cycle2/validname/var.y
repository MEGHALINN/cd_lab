%{
    #include <stdio.h>
    int yylex();  
    int yyerror(char *s);       
%}

%token VARIABLE

%%

start:
          VARIABLE        
        | error           {yyerrok; printf("Invalid Variable \n");}
        ;

%%

int main(){
    printf("Enter a variable :");
    yyparse();
    return 0;
}

int yyerror(char *s){
    printf("Error: %s\n",s);
    return 0;
}

