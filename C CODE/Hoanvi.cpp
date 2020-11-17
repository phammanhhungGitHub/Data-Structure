#include<iostream>
#define MAX 100

void PrintArray(int arr[], int n)
{
    for (int i = 0; i < n; ++i)
    {
        std::cout << arr[i];
    }
    std::cout << '\n';
}

void Permute(int n, int permutation[], bool isUsed[], int deg)
{
    for (int i = 1; i <= n; ++i)
    {
        if (!isUsed[i])
        {
            permutation[deg] = i;

            if (deg + 1 == n)
            {
                PrintArray(permutation, n);
            }
            else
            {
                isUsed[i] = true;
                Permute(n, permutation, isUsed, deg + 1);
                isUsed[i] = false;
            }
        }
    }
}

int main()
{
    int n;
    std::cin >> n;

    int permutation[MAX];
    bool isUsed[MAX] = {false};

    Permute(n, permutation, isUsed, 0);

    

    return 0;
}