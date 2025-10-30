#include <stdio.h>
#include <string.h>
#define MAX 100

char stack[MAX];
char input[MAX];
int top=-1;

void push(char c){
    stack[++top]=c;
}

void display(int ip){
    for(int i=0;i<=top;i++){
        printf("%c",stack[i]);
    }
    printf("\t");
    for(int i=ip;input[i]!='\0';i++){
        printf("%c",input[i]);
    }
    printf("\t");
}

int reduce(){
    if(top>=0 && stack[top]=='i'){
        stack[top]='E';
        return 1;
    }
    if(top>=2 && stack[top]==')' && stack[top-1]=='E' && stack[top-2]=='('){
        stack[top-2]='E';
        top-=2;
        return 1;
    }
    if(top>=2 && stack[top]=='E' && stack[top-1]=='+' && stack[top-2]=='E'){
        stack[top-2]='E';
        top-=2;
        return 1;
    }
    if(top>=2 && stack[top]=='E' && stack[top-1]=='*' && stack[top-2]=='E'){
        stack[top-2]='E';
        top-=2;
        return 1;
    }
    return 0;
}

int main(){
    printf("Enter the string :");
    scanf("%s",input);

    int ip=0;
    printf("STACK\tINPUT\tACTION\n");

    while(1){
        push(input[ip++]);
        printf("\n");
        display(ip);
        printf("Shift");

        while (reduce()){
            printf("\n");
            display(ip);
            printf("Reduce");
        }

        if(stack[0]=='E' && top==0 && input[ip]=='\0'){
            printf("\n");
            display(ip);
            printf("Accept");
            break;
        }
        if(input[ip]=='\0' && !(stack[0]=='E' && top==0) ){
            printf("\n");
            display(ip);
            printf("Reject");
            break;
        }
    }
    return 0;
}