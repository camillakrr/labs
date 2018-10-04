#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    printf("Array size: ");
    size_t N;
    scanf("%lu", &N);

    int* array = malloc(N * sizeof(int));
    for(size_t i = 0; i < N; i++) {
        array[i] = i;
        printf("%i", array[i]);
    }

    printf("\n");
    free(array);
    return 0;
}
