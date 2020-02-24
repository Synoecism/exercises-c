#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    unsigned char x;
    unsigned char z;
    unsigned char y;
    unsigned char nunc;
    nunc = 0;
    z = 1;
    x = 3;
    y = 9;

    if ((1 << 0) & x)
    {
        puts("hello");
    }

    nunc |= z;
    nunc |= x;
    nunc |= z;

    printf("%d \n", nunc);
}