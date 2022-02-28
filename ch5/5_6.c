#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

/* wait pid got more choices, you can even get sth about child process at all */
int main() {
	int azhe;
	int rc = fork();
	if (rc < 0) {
		fprintf(stderr, "fork failed!\n");
		exit(-1);
	} else if (rc == 0) {
		printf("child process!\n");
	} else {
		int result = waitpid(-1, &azhe, 0);
		printf("result = %d azhe = %d father process!\n", result, azhe);
	}
	return 0;
}
