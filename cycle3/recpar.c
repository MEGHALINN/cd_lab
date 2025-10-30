#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

char input[100];
int pos=0;

void E();
void Edash();
void T();
void Tdash();
void F(); 

void match(char expected){
    if(input[pos]==expected){
        pos++;
    }else{
        printf("Error : expected %c at position %d",expected,pos);
        exit(1);
    }
}

void E(){
    T();
    Edash();
}

void T(){
    F();
    Tdash();
}

void Tdash(){
    if(input[pos] == '*' ){
        match('*');
        F();
        Tdash();
    }
}

void Edash(){
    if(input[pos] == '+'){
        match('+');
        T();
        Edash();
    }
}

void F(){
    if(input[pos]=='('){
        match('(');
        E();
        match(')');
    } 
    else if(input [pos]=='i'){
        match('i');
    }
    else{
        printf("Error in F at position %d",pos);
        exit(1);
    }
}

void main(){
    printf("Enter the string :");
    scanf("%s" , input);

    E();

    if(input[pos]=='\0'){
        printf("String Accepted\n");
    }
    else{
        printf("String Rejected at Symbol %c in position%d\n",input[pos],pos);
    }
}