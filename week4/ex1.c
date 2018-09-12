#include <stdio.h>
#include <stdlib.h>

int main() {
	int n = 1488;
	int pid = fork();

	if (pid == 0) {
		printf("Hello from child [%d - %d]\n", pid, n);
	} else if (pid > 0) {
		printf("Hello from parent [%d - %d]\n", pid, n);
	} else {
		printf("Unsuccessful fork\n");
		return -1;
	}
	return 0;
}
