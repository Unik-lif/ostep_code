#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

int main(void) {
	int i = 0;
	for (i = 0; i < 5; i++) {
		fork();
		printf("pid = %ld %d\n", (long) getpid(), i);
		wait(0);
	}
	return 0;
}
