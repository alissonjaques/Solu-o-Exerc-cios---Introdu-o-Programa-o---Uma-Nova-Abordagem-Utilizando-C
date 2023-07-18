#include<stdio.h>
#include<stdlib.h>

int main(){

    int q, i, j, l;

    scanf("%d", &q);

    int m[q][2];

    for(i=0; i<q; i++){
        for(j=0; j<2; j++){
            scanf("%d", &m[i][j]);
        }
    }

    int v[q];

    for(l=0; l<q; l++){
        for(i=0; i<q; i++){
            for(j=0; j<2; j++){
                if(l==i && j==0){
                    if(m[i][j]<m[i][j+1]){
                        if(m[i][j]<0 && m[i][j+1]<0){
                            v[l] = (-1*m[i][j])-(-1*m[i][j+1]);
                        }
                        else if(m[i][j]<0 && m[i][j+1]>0){
                            v[l] = (m[i][j+1]+(-1*m[i][j])) - 1;
                        }
                        else if(m[i][j]>0 && m[i][j+1]>0){
                            v[l] = m[i][j+1] - m[i][j];
                        }
                    }
                }
            }
        }
    }

    for(l=0; l<q; l++){
        printf("%d\n", v[l]);
    }

    return 0;
}
