#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() 
{
	int x;
	x = 100;
	int rc = fork();
	if (rc < 0)
	{
		fprintf(stderr, "fork failed\n");
		exit(1);
	}
	else if (rc == 0)
	{
		x = 10;
		printf("child:%d\n", x);
	}
	else
	{
		int rc = wait(NULL);
		x = 11;
		printf("father:%d\n", x);
	}
	printf("I have no idea:%d\n", x);
	return 0;
}
