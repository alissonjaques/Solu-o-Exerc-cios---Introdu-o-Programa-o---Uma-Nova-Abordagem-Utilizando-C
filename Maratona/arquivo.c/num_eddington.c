#include<stdio.h>
#include<stdlib.h>

int main(){

    int d, i, c=0;

    scanf("%d", &d);
    if(d>0 && d<1000){
        while(d!=0){
            int v[d];
            for(i=0; i<d; i++){
                scanf("%d", &v[i]);
                if(v[i]<0 || v[i]>200){
                    scanf("%d", &v[i]);
                }
            }
            for(i=0; i<d; i++){
                c += v[i];
                if(c==d){
                    if(v[i]==2){
                    printf("%d\n", v[i]);
                    i = d;
                    c = 0;
                    }
                    else {
                    printf("%d\n", v[i+1]);
                    i = d;
                    c = 0;
                    }
                }
                else if(c>d){
                    printf("%d\n", d);
                    i = d;
                    c = 0;
                }
            }
            scanf("%d", &d);
        }
    }
    else{
        scanf("%d", d);
    }
    return 0;
}
