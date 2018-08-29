#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
    char *a;
    a = (char*)malloc(255 * sizeof(char));
    scanf("%s", a);
    for (int i = strlen(a); i > 0; --i)
	{
		printf("%c", a[i - 1]);
	}
    return 0;
}

