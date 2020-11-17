#include<iostream>

void PrintArray(int *arr, int n)
{
    for (int i = 0; i < n; ++i)
    {
        std::cout << arr[i];
    }
    std::cout << '\n';
}

void GenerateBinaryString(int *binaryString, int n, int deg)
{
    for (int i = 0; i <= 1; ++i)
    {
        binaryString[deg] = i;
        if (deg + 1 == n)
        {
            PrintArray(binaryString, n);
        }
        else
        {
            GenerateBinaryString(binaryString, n, deg + 1);
        }
    }
}

int main()
{
    int length;
    std::cout << "Length of bianry string : ";
    std::cin >> length;

    int *binaryString = new int[length];
    GenerateBinaryString(binaryString, length, 0);

    delete[] binaryString;

    return 0;
}