%{
    #include <stdio.h>
    int chars=0,words=0,lines=0;
%}
%option noyywrap

%%
\n              { lines++; chars++; }              /* newline = one char + one line */
[ \t]+          { chars += yyleng; }               /* count all spaces/tabs */
[a-zA-Z0-9]+    { words++; chars += yyleng; }      /* words = length of token */
.               { chars++; }                       /* any other character */
%%

int main() {
    yylex();
    printf("Lines : %d\nWords : %d\nCharacters : %d\n", lines, words, chars);
    return 0;
}
