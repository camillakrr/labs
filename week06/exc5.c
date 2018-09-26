#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>

void child_main() {
    while(1) {
        sleep(1);
        printf("I'm alive\n");
    }
}

void parent_main(int child_pid) {
    sleep(10);
    kill(child_pid, SIGTERM);
}

int main(int argc, char *argv[]) {
    int pid = fork();
    if(pid < 0) {
        perror("Error forking process");
    } else if(pid == 0) {
        child_main();
    } else {
        parent_main(pid);
    }
}
