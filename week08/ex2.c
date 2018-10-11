#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <unistd.h>

int main() {
    int i = 0;
    const  size_t size = 10 * 1024 * 1024;
    while(++i <= 10) {
        void* array = malloc(size);
        memset(array, 0, size);        
        sleep(1);
    }
}
