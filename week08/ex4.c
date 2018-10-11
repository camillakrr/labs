#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <unistd.h>
#include <sys/resource.h>

int main() {
    int i = 0;
    const  size_t size = 10 * 1024 * 1024;
    struct rusage usage;

    while(++i <= 10) {
        void* array = malloc(size);
        memset(array, 0, size);        
        getrusage(RUSAGE_SELF, &usage);
        printf("utime: %d.%d\n", usage.ru_utime.tv_sec, usage.ru_utime.tv_usec);
        printf("stime: %d.%d\n", usage.ru_stime.tv_sec, usage.ru_stime.tv_usec);
        printf("maxrss: %d\n", usage.ru_maxrss);
        sleep(1);
    }
}
