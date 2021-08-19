#include <stdio.h>

int main(){

    float num1;
    int b;
    char c;

    num1 = 3.1;
    b = 4;
    c = 'D';

    printf("Cast da variavel float? %d\n", num1); // imprime: Cast da variavel float? -199291976 (não)                                                                                       
    printf("Cast da variavel int? %f\n", b);      // imprime: Cast da variavel int? 3.100000     (não)
    printf("Cast da variavel char? %d\n", c);     // imprime: Cast da variavel char? 68          (sim)

    printf("Mundo.\n");                           // imprime: Mundo.

    return 0;

}
