#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int matriz_estado(int mInicial[][3]){                     
	char p0,p1,p2,p3,p4,p5,p6,p7,p8;
	char str[10];

  	p0 = mInicial[0][0] + '0';
  	p1 = mInicial[0][1] + '0';
  	p2 = mInicial[0][2] + '0';
  	p3 = mInicial[1][0] + '0';
  	p4 = mInicial[1][1] + '0';
  	p5 = mInicial[1][2] + '0';
  	p6 = mInicial[2][0] + '0';
  	p7 = mInicial[2][1] + '0';
  	p8 = mInicial[2][2] + '0';
	
	str[0] = p0;
	str[1] = p1;
	str[2] = p2;
	str[3] = p3;
	str[4] = p4;
	str[5] = p5;
	str[6] = p6;
	str[7] = p7;
	str[8] = p8;
	str[9] = 00000000;

	return atoi(str);
}

void arvoreRecursiva(int mInicial[][3], int vetorEstados[], int *t, clock_t Ticks[]){
 
   int posi, posj, i, j, num1 = 0, num2 = 0, comp1=0, comp2=0, comp3=0, comp4=0;
    
    if(mInicial[0][0]==0 && mInicial[0][1]==1 && mInicial[0][2]==2 && mInicial[1][0]==3
        && mInicial[1][1]==4 && mInicial[1][2]==5 && mInicial[2][0]==6 && mInicial[2][1]==7
        && mInicial[2][2]==8){
            
            printf("\nAchei!\n");
            printf("Matriz Final:\n");
            
            for(i=0; i<3; i++){
                for(j=0; j<3; j++){
                    
                    printf("%d\t", mInicial[i][j]);
                
                    
                }
            
                printf("\n");
            }
             
            printf("\nEstados visitados: %d\n", *t);
            
            Ticks[1] = clock();
            double Tempo = (Ticks[1] - Ticks[0]) * 1000.0 / CLOCKS_PER_SEC;
            printf("Tempo gasto: %g ms.", Tempo);
            
            exit(0);
        }
        
   for(i=0; i<3; i++){
       for(j=0; j<3; j++){
           
           if(mInicial[i][j]==0){
               posi = i;
               posj = j;
           }
           
       }
   }
   //1
   if(posi == 0 && posj == 0){
       
       num1 = mInicial[0][0];
       num2 = mInicial[1][0];
       mInicial[1][0] = num1;
       mInicial[0][0] = num2;
       comp1 = matriz_estado(mInicial);
       
       num1 = mInicial[0][0];
       num2 = mInicial[0][1];
       mInicial[0][1] = num1;
       mInicial[0][0] = num2;
       
       comp2 = matriz_estado(mInicial);
       
       if(comp1>=comp2){
       
        if(mInicial[1][0]!= vetorEstados[*t]){
                num1 = mInicial[0][0];
                num2 = mInicial[1][0];
                mInicial[1][0] = num1;
                mInicial[0][0] = num2;
                vetorEstados[(*t)++] = num2;
                arvoreRecursiva(mInicial,vetorEstados,&(*t),Ticks);
        }
           
       }else{
            if(mInicial[0][1]!= vetorEstados[*t]){
                num1 = mInicial[0][0];
                num2 = mInicial[0][1];
                mInicial[0][1] = num1;
                mInicial[0][0] = num2;
                vetorEstados[(*t)++] = num2;
                arvoreRecursiva(mInicial,vetorEstados,&(*t),Ticks);
            }        
       }
       
   }//2
   else if(posi == 0 && posj == 1){
       
       if(mInicial[0][0]!= vetorEstados[*t]){
            num1 = mInicial[0][1];
            num2 = mInicial[0][0];
            mInicial[0][0] = num1;
            mInicial[0][1] = num2;
            vetorEstados[(*t)++] = num2;
            arvoreRecursiva(mInicial,vetorEstados,&(*t),Ticks);
        
       }
       if(mInicial[1][1]!= vetorEstados[*t]){
            num1 = mInicial[0][1];
            num2 = mInicial[1][1];
            mInicial[1][1] = num1;
            mInicial[0][1] = num2;
            vetorEstados[(*t)++] = num2;
            arvoreRecursiva(mInicial,vetorEstados,&(*t),Ticks);

       }
       if(mInicial[0][2]!=vetorEstados[*t]){
            num1 = mInicial[0][1];
            num2 = mInicial[0][2];
            mInicial[0][2] = num1;
            mInicial[0][1] = num2;
            vetorEstados[(*t)++] = num2;
            arvoreRecursiva(mInicial,vetorEstados,&(*t),Ticks);
            exit(0);
       }
   }//3
   else if(posi == 0 && posj == 2){
        
       if(mInicial[1][2]!=vetorEstados[*t]){
            num1 = mInicial[0][2];
            num2 = mInicial[1][2];
            mInicial[0][2] = num2;
            mInicial[1][2] = num1;
            vetorEstados[(*t)++] = num2;
            arvoreRecursiva(mInicial,vetorEstados,&(*t),Ticks);
        
       }
       if(mInicial[0][1]!=vetorEstados[*t]){
            num1 = mInicial[0][2];
            num2 = mInicial[0][1];
            mInicial[0][2] = num2;
            mInicial[0][1] = num1;
            vetorEstados[(*t)++] = num2;
            arvoreRecursiva(mInicial,vetorEstados,&(*t),Ticks);
           
       }
       
   }//4
   else if(posi == 1 && posj == 0){
       
       if(mInicial[0][0]!= vetorEstados[*t]){
            num1 = mInicial[1][0];
            num2 = mInicial[0][0];
            mInicial[1][0] = num2;
            mInicial[0][0] = num1;
            vetorEstados[(*t)++] = num2;
            arvoreRecursiva(mInicial,vetorEstados,&(*t),Ticks);

       }
       if(mInicial[1][1]!= vetorEstados[*t]){
            num1 = mInicial[1][0];
            num2 = mInicial[1][1];
            mInicial[1][0] = num2;
            mInicial[1][1] = num1;
            vetorEstados[(*t)++] = num2;
            arvoreRecursiva(mInicial,vetorEstados,&(*t),Ticks);

       }
       if(mInicial[2][0]!=vetorEstados[*t]){
            num1 = mInicial[1][0];
            num2 = mInicial[2][0];
            mInicial[1][0] = num2;
            mInicial[2][0] = num1;
            vetorEstados[(*t)++] = num2;
            arvoreRecursiva(mInicial,vetorEstados,&(*t),Ticks);

       }
   }//5
   else if(posi == 1 && posj == 1){
       
       if(mInicial[2][1]!=vetorEstados[*t]){
            num1 = mInicial[1][1];
            num2 = mInicial[2][1];
            mInicial[1][1] = num2;
            mInicial[2][1] = num1;
            vetorEstados[(*t)++] = num2;
            arvoreRecursiva(mInicial,vetorEstados,&(*t),Ticks);
  
       }
       if(mInicial[1][0]!= vetorEstados[*t]){
            num1 = mInicial[1][1];
            num2 = mInicial[1][0];
            mInicial[1][1] = num2;
            mInicial[1][0] = num1;
            vetorEstados[(*t)++] = num2;
            arvoreRecursiva(mInicial,vetorEstados,&(*t),Ticks);
   
       }
       if(mInicial[1][2]!=vetorEstados[*t]){
            num1 = mInicial[1][1];
            num2 = mInicial[1][2];
            mInicial[1][1] = num2;
            mInicial[1][2] = num1;
            vetorEstados[(*t)++] = num2;
            arvoreRecursiva(mInicial,vetorEstados,&(*t),Ticks);
  
       }
       if(mInicial[0][1]!= vetorEstados[*t]){
            num1 = mInicial[1][1];
            num2 = mInicial[0][1];
            mInicial[1][1] = num2;
            mInicial[0][1] = num1;
            vetorEstados[(*t)++] = num2;
            arvoreRecursiva(mInicial,vetorEstados,&(*t),Ticks);
         
       }
      
   
    
   }//6
   else if(posi == 1 && posj == 2){
       
       if(mInicial[0][2]!= vetorEstados[*t]){
            num1 = mInicial[1][2];
            num2 = mInicial[0][2];
            mInicial[1][2] = num2;
            mInicial[0][2] = num1;
            vetorEstados[(*t)++] = num2;
            arvoreRecursiva(mInicial,vetorEstados,&(*t),Ticks);

       }
       if(mInicial[1][1]!= vetorEstados[*t]){
            num1 = mInicial[1][2];
            num2 = mInicial[1][1];
            mInicial[1][2] = num2;
            mInicial[1][1] = num1;
            vetorEstados[(*t)++] = num2;
            arvoreRecursiva(mInicial,vetorEstados,&(*t),Ticks);

       }
       if(mInicial[2][2]!=vetorEstados[*t]){
            num1 = mInicial[1][2];
            num2 = mInicial[2][2];
            mInicial[1][2] = num2;
            mInicial[2][2] = num1;
            vetorEstados[(*t)++] = num2;
            arvoreRecursiva(mInicial,vetorEstados,&(*t),Ticks);
           
       }
   }//7
   else if(posi == 2 && posj == 0){
       
       if(mInicial[1][0]!=vetorEstados[*t]){
            num1 = mInicial[2][0];
            num2 = mInicial[1][0];
            mInicial[2][0] = num2;
            mInicial[1][0] = num1;
            vetorEstados[(*t)++] = num2;
            arvoreRecursiva(mInicial,vetorEstados,&(*t),Ticks);
    
       }
       if(mInicial[2][1]!=vetorEstados[*t]){
            num1 = mInicial[2][0];
            num2 = mInicial[2][1];
            mInicial[2][0] = num2;
            mInicial[2][1] = num1;
            vetorEstados[(*t)++] = num2;
            arvoreRecursiva(mInicial,vetorEstados,&(*t),Ticks);
         
           
       }
       
   }//8
   else if(posi == 2 && posj == 1){
       
       if(mInicial[2][0]!= vetorEstados[*t]){
            num1 = mInicial[2][1];
            num2 = mInicial[2][0];
            mInicial[2][1] = num2;
            mInicial[2][0] = num1;
            vetorEstados[(*t)++] = num2;
            arvoreRecursiva(mInicial,vetorEstados,&(*t),Ticks);
           
       }
       
       if(mInicial[1][1]!= vetorEstados[*t]){
            num1 = mInicial[2][1];
            num2 = mInicial[1][1];
            mInicial[2][1] = num2;
            mInicial[1][1] = num1;
            vetorEstados[(*t)++] = num2;
            arvoreRecursiva(mInicial,vetorEstados,&(*t),Ticks);
           
       }
    
       if(mInicial[2][2]!=vetorEstados[*t]){
            num1 = mInicial[2][1];
            num2 = mInicial[2][2];
            mInicial[2][1] = num2;
            mInicial[2][2] = num1;
            vetorEstados[(*t)++] = num2;
            arvoreRecursiva(mInicial,vetorEstados,&(*t),Ticks);
          
       }
   }//9
   else if(posi == 2 && posj == 2){
        
       if(mInicial[2][1]!=vetorEstados[*t]){
            num1 = mInicial[2][2];
            num2 = mInicial[2][1];
            mInicial[2][2] = num2;
            mInicial[2][1] = num1;
            vetorEstados[(*t)++] = num2;
            arvoreRecursiva(mInicial,vetorEstados,&(*t),Ticks);
            
           
       }
       if(mInicial[1][2]!=vetorEstados[*t]){
            num1 = mInicial[2][2];
            num2 = mInicial[1][2];
            mInicial[2][2] = num2;
            mInicial[1][2] = num1;
            vetorEstados[(*t)++] = num2;
            arvoreRecursiva(mInicial,vetorEstados,&(*t),Ticks);
  
       }
       
   }

}

void preencheInicial(int mInicial[][3]){
    
    int i, j;
    
    mInicial[0][0] = 3;
    mInicial[0][1] = 1;
    mInicial[0][2] = 2;
    mInicial[1][0] = 4;
    mInicial[1][1] = 5;
    mInicial[1][2] = 0;
    mInicial[2][0] = 6;
    mInicial[2][1] = 7;
    mInicial[2][2] = 8;
    
    printf("Matriz Inicial\n");
    for(i=0; i<3; i++){
        for(j=0; j<3; j++){
            
            printf("%d\t", mInicial[i][j]);
        }
        printf("\n");
    }
    
}

int main(){
   clock_t Ticks[2];
   Ticks[0] = clock();
   
    int mInicial[3][3];
    int vetorEstados[1000], t = 0;
    
    preencheInicial(mInicial);
    
    arvoreRecursiva(mInicial,vetorEstados,&t,Ticks);
    
    return 0;
}
