#include<stdio.h>
#include<stdlib.h>

int nCk(int n, int k)
{
    if (n < 0 || k < 0 || k > n)
        return 0;
    else if (n == k || k == 0)
        return 1;
    else if (n == 0)
        return 0;
    else
        return nCk(n - 1, k) + nCk(n - 1, k - 1);
}

int nCkDynamic(int n, int k)
{
    if (n < 0 || k < 0 || k > n)
        return 0;
    else if (n == k || k == 0)
        return 1;
    else if (n == 0)
        return 0;
    
    int i;
    int j;
    int **C = (int**)calloc(n + 1, sizeof(int*));
    for (i = 1; i <= n; ++i)
    {
        C[i] = (int*)calloc(i + 1, sizeof(int));
    }
    
    for (i = 1; i <= n; ++i)
    {
        for (j = 0; j <= i; ++j)
        {
            if (j == 0 || j == i)
                C[i][j] = 1;
            else
                C[i][j] = C[i - 1][j] + C[i - 1][j - 1];
        }
    }
    int result = C[n][k];
    for (int i = 0; i <= n; ++i)
    {
        free(C[i]);
    }
    free(C);
    return result;
}

int main()
{
    int n, k;
    //printf("n, k = ");
    scanf("%d%d", &n, &k);

    printf("%d", nCkDynamic(n, k));
    return 0;
}