#include <stdio.h>

void troca(float *a, float *b)
{	float aux;
	aux = *a;
	*a = *b;
	*b = aux;
}

int main()
{	float a=2, b=3, *x, *y;
    x = &a;
    y = &b;
	printf("ANTES: a = %f, b = %f\n", a, b);
	troca(x, y);
	printf("DEPOIS: a = %f, b = %f\n", a, b);
	return 0;
}