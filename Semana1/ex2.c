#include <stdio.h>

int main (void)
{
    int x = 7;
    int y = 13;
    int *z = &x; 
    printf("x: %i y: %i z: %p\n", x, y, z);
    printf("&x: %p &y: %p &z: %p\n", &x, &y, &z);
    *z += y;
    printf("Novo valor de x: %i\n", x);

    return 0;
}