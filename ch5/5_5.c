#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <errno.h>
/* when wait is called in child process, no doubt that it will raise a fault, return -1 at last, however, as the father process ends, the child process will no longer exists*/
int main(void) {
	int rc = fork();
	if (rc < 0) {
		fprintf(stderr, "fork failed!\n");
		exit(-1);
	} else if (rc == 0) {
		int guess = wait(NULL);
		printf("errno:%d:::", errno);
		printf("guess:%d child process!", guess);
	} else {
		printf("father process!");
	}
	return 0;
}
