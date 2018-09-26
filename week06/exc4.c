#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>

void signal_handler(int signo) {
    switch(signo) {
    case SIGKILL:
        // Never gonna be printed. SIGKILL cannot be caught.
        printf("SIGKILL\n");
    break;
    case SIGSTOP:
        // Never gonna be printed. SIGSTOP cannot be caught.
        printf("SIGSTOP\n");
    break;
    case SIGUSR1:
        // Will print on catching SIGUSR1 signal
        printf("SIGUSR1\n");
    break;
    }
}

int main(int argc, char *argv[]) {
    signal(SIGKILL, signal_handler);
    signal(SIGSTOP, signal_handler);
    signal(SIGUSR1, signal_handler);
    while(1) {
        sleep(10);
    }
}
