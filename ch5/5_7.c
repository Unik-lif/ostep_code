#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

int main(void) {
	int rc = fork();
	if (rc < 0) {
		fprintf(stderr, "fork failed\n");
		exit(-1);
	} else if (rc == 0) {
		fclose(stdout);
		printf("child process can you see me?\n");
	} else {
		wait(NULL);
	}
	return 0;
}
