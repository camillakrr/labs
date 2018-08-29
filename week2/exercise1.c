#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <float.h>

int main(int argc, char *argv[])
{
    int a;
    float b;
    double c;
    a = INT_MAX;
    b = FLT_MAX;
    c = DBL_MAX;
    printf("%lu\n", sizeof(a));
	printf("%d\n", a);
	printf("%lu\n", sizeof(b));
	printf("%f\n" , b);
	printf("%lu\n", sizeof(c));
	printf("%lf", c);
    return 0;
}
