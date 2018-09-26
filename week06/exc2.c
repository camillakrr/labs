#include <stdio.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char *argv[]) {
    const char* src = "A pipe";
    const size_t src_size = strlen(src) + 1;
    char dest[src_size];

    // Create a pipe
    int pipe_fds[2];
    if (pipe(pipe_fds) < 0) {
        perror("Error creating a pipe");
    }
    
    // Fork 
    switch(fork()) {
    case -1:
        perror("Error creating a process");
    break;
    case 0: /* Child -- read from pipe and print */
        // Close write end
        close(pipe_fds[1]);
        // Read data
        read(pipe_fds[0], dest, src_size);
        printf("received: %s\n", dest);
    break;
    default:
        // Close read end
        close(pipe_fds[0]);
        // Write data
        write(pipe_fds[1], src, src_size);

    }

    return 0;
}

