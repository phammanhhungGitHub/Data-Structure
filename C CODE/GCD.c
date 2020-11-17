#include<stdio.h>

int GCDRecursion(int a, int b)
{
    int min = (a < b)? a : b;
    int max = (a > b)? a : b;
    if (min == 0)
        return max;
    else
        return GCDRecursion(min, max % min);
}

int GCDIteration(int a, int b)
{
    int min = (a < b)? a : b;
    int max = (a > b)? a : b;
    while (min > 0)
    {
        int temp = min;
        min = max % min;
        max = temp;
    }
    return max;
}

int main()
{
    int a, b;
    printf("a, b = ");
    scanf("%d%d", &a, &b);
    printf("%d", GCDIteration(a, b));
    return 0;
}