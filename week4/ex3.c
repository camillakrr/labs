#include <stdio.h>
#include <stdlib.h>

int main() {
	char cmd[50];
	while (1) {
		printf("# ");
		scanf("%s", &cmd);
		system(cmd);
	}
}