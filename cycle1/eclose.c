#include <stdio.h>
#include <string.h>

char closure[10][10];

int contains(char closure[10][10],char state[10],int length){
    for(int i=0;i<length;i++){
        if(strcmp(state,closure[i])==0){
            return 1;
        }
    }
    return 0;
}

void print_closure(char state[10],int count){
    printf("Epsilon closure of state %s :",state);
    for(int i=0;i<count;i++){
        printf("%s\t",closure[i]);
    }
    printf("\n");
}

void epsilon_closure(char state[10],int *count){
    FILE *file=fopen("automata.txt","r");
    char from[10],arrow[10],to[10];

    while(fscanf (file ,"%s %s %s",from , arrow, to)==3){
        if(strcmp(from,state)==0 && strcmp(arrow,"e")==0){
            if(!contains(closure,to,*count)){
                strcpy(closure[(*count)++],to);
                epsilon_closure(to,count);
            }
        }
    }
    fclose(file);
}

void main(){
    int n;
    char states[10][10];
    printf("Enter the no of states : ");
    scanf("%d",&n);
    printf("Enter the states:");
    for(int i=0;i<n;i++){
        scanf("%s",states[i]);
    }

    for(int i=0;i<n;i++){
        int count=0;
        strcpy(closure[count++],states[i]);
        epsilon_closure(states[i],&count);

        print_closure(states[i],count);
    }
}