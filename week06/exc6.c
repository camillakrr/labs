#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>

void child1(int pipe_read_fd) {
    int child2_pid;
    read(pipe_read_fd, &child2_pid, sizeof(int));

    while(1) {
        sleep(1);
        printf("child1: I'm stopping child2\n");
        kill(child2_pid, SIGSTOP);
        sleep(1);
        printf("child1: I'm continuing child2\n");
        kill(child2_pid, SIGCONT);
    }
}

void child2() {
    while(1) {
        printf("Child2: Running\n");
        usleep(200000);
    }
}

int main(int argc, char *argv[]) {
    // Create pipe
    int pipe_fds[2];
    if(pipe(pipe_fds) < 0) {
        perror("Error creating pipe");
    }

    int child1_pid = fork();
    if(child1_pid < 0) {
        perror("Failed to create child1");
    } else if(child1_pid == 0) {
        close(pipe_fds[1]);
        child1(pipe_fds[0]);
    } else {
        close(pipe_fds[0]);
        int child2_pid = fork();
        if(child2_pid < 0) {
            perror("Failed to create child2");
        } else if(child2_pid == 0) {
            child2();
        } else {
            write(pipe_fds[1], &child2_pid, sizeof(int));
            while(1) {
                int status;
                while(1) {
                    waitpid(child2_pid, &status, WCONTINUED | WUNTRACED);
                    if(WIFSTOPPED(status)) {
                        printf("main: I know child2 just stopped\n");
                    } else if(WIFCONTINUED(status)) {
                        printf("main: I know child2 just continued\n");
                    }
                }
            }
        }
    }

    return 0;
}
