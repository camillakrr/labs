#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>

void signal_handler(int signo) {
    switch(signo) {
    case SIGINT:
        printf("Hello\n");
    break;
    case SIGTERM:
        printf("I'll die\n");
        exit(0);
    }
}

int main(int argc, char *argv[]) {
    signal(SIGINT, signal_handler);
    signal(SIGTERM, signal_handler);
    while(1) {
        sleep(10);
    }
}
