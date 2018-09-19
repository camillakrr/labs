#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <assert.h>
#include <stdatomic.h>
#include <unistd.h>

#define PRINT_TASKS_CNT 8

typedef struct TaskList {
    char*           list[PRINT_TASKS_CNT];
    int             size;
    int             is_closed;
} TaskList;

#define PRINT_LIST_INITIALIZER                             \
    {                                                      \
        .list                 = {NULL},                    \
        .size                 = 0,                         \
        .is_closed            = 0                          \
    }

void add_print_task(TaskList* list, char* task) {
    assert(list->size <= PRINT_TASKS_CNT);

    // If list is overflowed, wait for signal
    while(list->size == PRINT_TASKS_CNT) {
        usleep(1000);
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
        
        usleep(1000);
    }

    // Get task
    char* task = list->list[--list->size];
    
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
