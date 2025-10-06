#include <stdio.h>
#include <string.h>
int states, trans,symbols;
int trans[10][10][10];
int epsilon[10][10];
int final[10];

void compute_closure(int state,int closure[]){
    closure[state]=1;
    for(int i=0;i<states;i++){
        if(trans[state][symbols-1][i] && !closure[i]){
            compute_closure(i,closure);
        }
    }
}

void printset(int set[]){
    printf("{");
    for (int i=0;i<states;i++){
        if(set[i]){
            printf("q%d",i);
        }
    }
    printf("}\n");
}

int main(){
    char alpha[10];
    int start,numFinal;
    printf("Enter the no of states:");
    scanf("%d",&states);
    printf("Enter the no of symbols,include epsilon :");
    scanf("%d",&symbols);

    printf("Enter the symbols, enter epsilon as last");
    for(int i=0;i<symbols;i++){
        scanf("%c",&alpha[i]);
    }

    printf("Enter start state :");
    scanf("%d",&start);

    printf("Enter no of final states :");
    scanf("%d",&numFinal);

    printf("Enter the final states :");
    for(int i=0;i<numFinal;i++){
        int f;
        scanf("%d",&f);
        final[f]=1;
    }

    printf("Enter the no of transitions :");
    scanf("%d",&trans);

    printf("Enter the transitions :");
    for(int i=0;i<trans;i++){
        int from,to;
        char symbol;
        scanf("%d %c %d",&from,&symbol,&to);
        trans[from][symbol][to]=1;

        int sym_ind=-1;
        for(int j=0;j<symbols;j++){
            if(alpha[j]==symbol){
                sym_ind=j;
                break;
            }
        }

        if(sym_ind!=-1){
            trans[from][sym_ind][to]=1;
        }

    }

    for(int i=0;i<states;i++){
        compute_closure(i,epsilon[i]);
    }

    printf("\nEquivalent NFA (without epsilon):\n");

    // Start state
    printf("Start state: ");
    printSet(epsilon[start]);
    printf("\n");

    printf("Transitions :");
    for(int i=0;i<states;i++){
        for(int j=0;j<symbols-1;j++){
            int result[10]={0};
            for(int k=0;k<states;k++){
                if(epsilon[i][k]){
                    for(int l=0;l<states;l++){
                        if(trans[k][j][l]){
                            for(int m=0;m<states;m++){
                                if(epsilon[l][m]){
                                    result[m]=1;
                                }
                            }
                        }
                    }
                }
            }
            printSet(epsilon[i]);
            printf(" on %c -> ", alpha[j]);
            printSet(result);
            printf("\n");
        }
    }
     printf("Final states: ");
    for (int i = 0; i < states; i++) {
        for (int j = 0; j < states; j++) {
            if (epsilon[i][j] && final[j]) {
                printSet(epsilon[i]);
                printf(" ");
                break;
            }
        }
    }
    printf("\n");

    return 0;

    
}