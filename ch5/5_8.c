#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <fcntl.h>

char hello[] = "hello world! link!";
char metoo[] = "OK! thankyou!";
int main() {
	char a[100] = {0};
	int p[2];
	int rc = fork();
	pipe(p);
	if (rc < 0) {
		fprintf(stderr, "fork failed\n");
		exit(-1);
	} else if (rc == 0) {
		int rd = fork();
		if (rd < 0) {
			fprintf(stderr, "fork failed\n");
			exit(-1);
		} else if (rd == 0) {
			write(p[1], hello, sizeof(hello));
		       	exit(-1);	
		} else {
			wait(NULL);
			read(p[0], a, 100);	
			printf("a:%s\n", a);
		}
	} else {
		wait(NULL);
	}	
	return 0;
}
