#include<stdio.h>

int Mystery(int n)
{
    int r = 0;
    int i, j, k;
    for (i = 1; i < n; ++i)
    {
        for (j = i + 1; j <= n; ++j)
        {
            for (k = 1; k <= j; ++k)
            {
                r++;
            }
        }
    }
    return r;
}

int FormulaOfMystery(int n)
{
    return (n - 1) * n * (n + 1) / 3;
}

int Pesky(int n)
{
    int r = 0;
    int i, j, k;
    for (i = 1; i <= n; ++i)
    {
        for (j = 1; j<= i; ++j)
        {
            for (k = j; k <= i + j; ++k)
            {
                r++;
            }
        }
    }
    return r;
}

int FormulaOfPesky(int n)
{
    return n * (n + 1) * (n + 2) / 3; 
}

int main()
{
    printf("%d", Pesky(18) == FormulaOfPesky(20));

    return 0;
}