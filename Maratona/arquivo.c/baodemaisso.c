#include<stdio.h>
#include<stdlib.h>

int escola(int e){

    int t;
    scanf("%d", &t);

    int v[t+1], i, q, q1, c=0;
    v[0] = t;

    for(i=1; i<(t+1); i++){
        scanf("%d", &v[i]);
        c += v[i];
    }

    q = c*3;
    q1 = t*3;

    if(q>q1){
        return 0;
    }
    else{
        return 1;
    }
}

int main(){

    int e, j;

    scanf("%d", &e);

    if(0<e && e<=50){
        for(j=0; j<e; j++){
            if(escola(e)==0){
                printf("precisa\n");
            }
            else{
                printf("nao precisa\n");
            }
        }
    }

    return 0;
}
