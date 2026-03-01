#include <stdio.h>
int main()
{
    int y, *p, x;
    y = 0; //atribui a variavel y o valor 0
    p = &y; //ponteiro p recebe o endereco da variavel y
    x = *p; //x aponta para o valor do ponteiro *p
    x = 4; //atribui a variavel x o valor 4
    ++(*p); //adiciona 1 ao valor apontado pelo ponteiro *p (0+1)
    x--; //subtrai 1 ao valor de x (4-1)
    (*p) += x++; //o valor apontado pelo ponteiro *p recebe o próprio valor acrescido de x+1 (1+3)
    printf ("y = %d\n", y); //imprime o valor de y
}