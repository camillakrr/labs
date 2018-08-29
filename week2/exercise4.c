#include <stdio.h>
#include <stdlib.h>

void swap(int* a, int* b)
{
	int c = *a;
	*a = *b;
	*b = c;
}

int main(int argc, char *argv[])
{
	int a, b;
	scanf("%d", &a);
	scanf("%d", &b);
	swap(&a, &b);
	printf("%d %d", a, b);
	return 0;
}
