#include <stdio.h>

int main() 
{
    int n;
    char *cp;

    n = 0x12345678;
    cp = (char*)(&n);
    if (*cp != 0x78) 
       printf("Big Endian\n");
    else 
       printf("Little Endian\n");
    return 0;
}
