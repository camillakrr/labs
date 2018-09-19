#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <assert.h>
#include <stdatomic.h>

#define PRINT_TASKS_CNT 8

typedef struct TaskList {
    char*           list[PRINT_TASKS_CNT];
    atomic_size_t   size;
    int             is_closed;
    pthread_cond_t  overflow_cond;
    pthread_mutex_t overflow_cond_mutex;
} TaskList;

#define PRINT_LIST_INITIALIZER                             \
    {                                                      \
        .list                 = {NULL},                    \
        .size                 = (atomic_size_t) 0,         \
        .is_closed            = 0,                         \
        .overflow_cond        = PTHREAD_COND_INITIALIZER,  \
        .overflow_cond_mutex  = PTHREAD_MUTEX_INITIALIZER  \
    }

void add_print_task(TaskList* list, char* task) {
    assert(list->size <= PRINT_TASKS_CNT);

    // If list is overflowed, wait for signal
    if(list->size == PRINT_TASKS_CNT) {
        printf("add_print_task: OVERFLOW, waiting for signal\n");
        pthread_cond_wait(&list->overflow_cond, &list->overflow_cond_mutex);
        printf("add_print_task: got signal, continuing\n");
    }

    // Add task
    list->list[list->size++] = task;
}

char* get_print_task(TaskList* list) {
    assert(list->size <= PRINT_TASKS_CNT);

    // Wait until list is not empty
    while(list->size == 0) {
        if(list->is_closed) {
            pthread_exit(NULL);
        }

        // Send signal that the list is not overflowed anymore
        pthread_cond_signal(&list->overflow_cond);
    }

    // Get task
    char* task = list->list[--list->size];

    // Send signal that the list is not overflowed anymore
    pthread_cond_signal(&list->overflow_cond);

    return task;
}

void* printer_thread(void* args) {
    TaskList* list = (TaskList*) args;

    while (1) {
        // Get next task and print it
        char* task = get_print_task(list);
        printf("%s\n", task);

        // Free memory
        free(task);
    }
}

int main(int argc, char *argv[]) {
    // Initialize Printerlist
    TaskList list = PRINT_LIST_INITIALIZER;

    // Create thread
    pthread_t printer_thread_handle;
    pthread_create(&printer_thread_handle, NULL, printer_thread, &list);

    for(int i = 0; i < 100; i++) {
        // Create new task
        char* task = (char*) malloc(64);
        sprintf(task, "Ineration #%d", i);
        add_print_task(&list, task);
    }

    list.is_closed = 1;
    pthread_join(printer_thread_handle, NULL);

    return 0;
}
