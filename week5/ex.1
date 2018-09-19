#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <stdatomic.h>
#include <unistd.h>

static atomic_uint thread_ctr = 0;

void* thread_body(void* args) {
    printf("Hey, i'm thread! My number is %d\n", thread_ctr++);
    return NULL;
}

void parallel(int n) {
    pthread_t threads[n];
    for(int i = 0; i < n; i++) {
        printf("Main: spawned thread %i\n", i);
        pthread_create(threads+i, NULL, thread_body, NULL);
    }
}

void sequential(int n) {
    pthread_t threads[n];
    for(int i = 0; i < n; i++) {
        printf("Main: spawned thread %i\n", i);
        pthread_create(threads+i, NULL, thread_body, NULL);
        pthread_join(threads[i], NULL);
    }
}

int main(int argc, char *argv[]) {
    int n = atoi(argv[1]);
    thread_ctr = 0;
    printf("parallel thread creation\n");
    parallel(n);
    usleep(1000);
    thread_ctr = 0;
    printf("\nsequential thread creation\n");
    sequential(n);
    return 0;
}
