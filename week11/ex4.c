#include <stdio.h>

#define byte char
#define N 10

void* memcpy(void* dest, const void* src, size_t n)
{
	byte* s = (byte*)src;
	byte* d = (byte*)dest;
	for (int i = 0; i < n; ++i)
		d[i]=s[i];
	return (void*)d;
}

int main(int argc, char const *argv[])
{
	int a[N];
	int b[N];
	for (int i = 0; i < N; ++i)
		a[i] = i;
	memcpy(b,a,sizeof(int)*10);
	for (int i = 0; i < N; ++i)
		printf("%d\n", b[i]);		
	return 0;
}
