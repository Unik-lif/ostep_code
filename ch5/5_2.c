#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main(void) {
	int fd = open("test", O_RDWR);
	int rc = fork();
	if (rc < 0) {
		fprintf(stderr, "fork failed!\n");
		exit(-1);
	} else if (rc == 0) {
		printf("child process will change the file!\n");
		char buf[] = "child is writing to the file!";
		write(fd, buf, sizeof(buf));
	} else {
		printf("father process will change the file!\n");
		char buf[] = "father is writing to the file!";
		write(fd, buf, sizeof(buf));
	}
	close(fd);
	fd = open("test", O_RDWR);
	char buf[200] = {0};
	read(fd, buf, 200);
	printf("buf:%s", buf);
	return 0;	
}
