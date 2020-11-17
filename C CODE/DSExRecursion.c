#include<stdio.h>

int ExA(int n)
{
    if (n <= 2)
        return 2;
    return 3 * ExA(n - 2) + ExA(n - 1) + 4;
}

int ExB(int n)
{
    if (n <= 0)
        return 1;
    return ExB(n / 2) + ExB(n - 1);
}

int ExC(int n)
{
    if (n == 0)
        return 1;
    else if (n == 1)
        return 2;
    return 2 * ExC(n % 2) + ExC(n / 2);
}

int main()
{
    printf("%d\n", ExC(4));
    printf("%d", ExC(7));
    return 0;
}