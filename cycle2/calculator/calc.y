%{
    #include <stdio.h>
    #include <stdlib.h>
    int yylex();
    int yyerror(char *s);
%}

%union{
    int num;
}

%token <num> NUMBER
%type  <num> expr


%left '+' '-'
%left '*' '/'

%%

input:
    /* empty*/
    | input line
    ;

line:
    '\n'
    | expr '\n'     {printf("%d\n",$1);}
    ;

expr:
      expr '+' expr      {$$=$1+$3; }
    | expr '-' expr      { $$ = $1 - $3 ;}
    | expr '*' expr      { $$ = $1 * $3 ;}
    | expr '/' expr      { 
                            if ($3 == 0) { yyerror("division by zero"); $$ = 0; } 
                            else $$ = $1 / $3; 
                         }
    | '(' expr ')'          { $$ = $2; }
    | NUMBER                { $$ = $1; }
    ;
%%

int main(){
    return yyparse();
    return 0;
}

int yyerror(char *s) {
    fprintf(stderr, "Error: %s\n", s);
    return 0;
}