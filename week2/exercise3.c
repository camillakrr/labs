#include <stdio.h>
#include <stdlib.h>

void triangle(int n)
{
    for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < 2 * n - 1; ++j)
		{
			if (j < n - 1 - i || j > n - 1 + i)
			{
				printf("%c", ' ');
			}
			else
			{
				printf("%c", '*');
			}
		}
		printf("\n");
	}
}

int main(int argc, char *argv[])
{
    int n = atoi(argv[1]);
    triangle(n);
    return 0;
}
