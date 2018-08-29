#include <stdio.h>
#include <stdlib.h>

void figure1(int n)
{
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j <= i; ++j)
        {
            printf("%c", '*');
        }
        printf("\n");
    }
}

void figure2(int n)
{
    figure1((n + 1) / 2);
    for (int i = 0; i < n / 2; ++i)
    {
        for (int j = 0; j < n / 2 - i; ++j)
        {
            printf("%c", '*');
        }
        printf("\n");
    }
}

void figure3(int n)
{
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            printf("%c", '*');
        }
        printf("\n");
    }
}

int main(int argc, char *argv[])
{
    int m = atoi(argv[1]);
    int n = atoi(argv[2]);
    if (m == 1)
    {
        figure1(n);
    }
    if (m == 2)
    {
        figure2(n);
    }
    if (m == 3)
    {
        figure3(n);
    }
    return 0;
}
