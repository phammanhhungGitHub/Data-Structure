#include<stdio.h>
#include<stdlib.h>
#include<math.h>

void PrintArray(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i] + 1);
    }
    printf("\n");
}

int IsGoodPosition(int *position, int k, int pos)
{
    for (int i = 0; i < k; ++i)
    {
        if (pos == position[i] || abs(k - i) == abs(pos - position[i]))
            return 0;
    }
    return 1;
}

void Solution(int *position, int n, int k)
{
    for (int i = 0; i < n; ++i)
    {
        if (IsGoodPosition(position, k, i))
        {
            position[k] = i;
            if (k + 1 == n)
            {
                PrintArray(position, n);
            }
            else
            {
                Solution(position, n, k + 1);
            }
        }
    }
}

int main()
{
    int n;
    printf("Size of chess board: ");
    scanf("%d", &n);
    
    int *position = (int*)calloc(n, sizeof(int));
    Solution(position, n, 0);

    return 0;
}