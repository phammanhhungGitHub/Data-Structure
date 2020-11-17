#include<stdio.h>

int count = 0;
void HanoiTower(int n, char a, char b, char c)
{
    if (n == 1)
    {
        ++count;
        printf("%2d. Move a disk from %c to %c\n", count, a, c);
    }
    else
    {
        HanoiTower(n - 1, a, c, b);
        HanoiTower(1, a, b, c);
        HanoiTower(n - 1, b, a, c);
    }
    
}

int main()
{
    int n;
    printf("Please input number of disk : ");
    scanf("%d", &n);

    HanoiTower(n, 'a', 'b', 'c');
    getchar();

    return 0;
}