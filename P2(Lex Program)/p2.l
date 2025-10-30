%{
    #include <stdio.h>
    int flag=0;
%}

%%
megh        { flag =1;}
\n          { 
            if(flag){
                printf("Invalid String\n ");
            }
            else{
                printf(" Valid String \n");
            }
            flag =0 ;}
.           {}
end         { return 0;}
%%

int yywrap(){
    return 1;
}
int main(){
    printf("Enter the string (type end to finish):");
    yylex();
    return 0;
}