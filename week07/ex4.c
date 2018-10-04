#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

void* realloc(void* ptr, size_t size) {
    void* new_mem = malloc(size);
    if(new_mem == NULL) return NULL;

    size_t old_size = *((size_t*) ptr - 1);

    if(old_size < size) {
        memcpy(new_mem, ptr, old_size);
    }

    free(ptr);
    return new_mem;
}

int main(int argc, char *argv[]) {
    // Allows user to specify the original array size, stored in variable n1.
    printf("Enter original array size:");
    int n1=0;
    scanf("%d",&n1);

    //Create a new array of n1 ints
    int* a1 = (int*) malloc(n1 * sizeof(int));
    for(int i = 0; i < n1; i++){
        //Set each value in a1 to 100
        a1[i] = 100;

        //Print each element out (to make sure things look right)
        printf("%d ", a1[i]);
    }

    //User specifies the new array size, stored in variable n2.
    printf("\nEnter new array size: ");
    int n2=0;
    scanf("%d",&n2);

    //Dynamically change the array to size n2
    int* temp = (int*) realloc(a1, n2 * sizeof(int));
    if(temp == NULL) {
        printf("Realloc error");
        exit(1);
    }
    a1 = temp;

    //If the new array is a larger size, set all new members to 0. Reason: dont want to use uninitialized variables.
    for(int i = n1; i < n2; i++) {
        a1[i] = 0;
    }

    for(int i = 0; i < n2; i++){
        //Print each element out (to make sure things look right)
        printf("%d ", a1[i]);
    }
    printf("\n");

    //Done with array now, done with program :D
    free(a1);

    return 0;

}
