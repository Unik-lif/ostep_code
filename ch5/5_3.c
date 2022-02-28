#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
	int rc = fork();
	if (rc < 0) {
		fprintf(stderr, "fork failed\n");
		exit(-1);
	} else if (rc == 0) {
		printf("hello");
		exit(0);
	} else {
		sleep(1);
	}
	printf("goodbye");
	return 0;
}
