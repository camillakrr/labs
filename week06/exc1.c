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

    write(pipe_fds[0], src, src_size);
    read(pipe_fds[1], dest, src_size);

    printf("received: %s\n", src);
    return 0;
}
