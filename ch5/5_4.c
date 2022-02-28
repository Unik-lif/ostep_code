#include <stdio.h>
#include <stdlib.h>
/* The declaration of execvpe is only included if _GNU_SOURCE is defined before including unistd.h as it is a GNU extension. */
/* https://stackoverflow.com/questions/5582211/what-does-define-gnu-source-imply */
/* If you define this macro, everything is included: ISO C89, ISO C99, POSIX.1, POSIX.2, BSD, SVID, X/Open, LFS, and GNU extensions. In the cases where POSIX.1 conflicts with BSD, the POSIX definitions take precedence. */

#define _GNU_SOURCE
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
/* demo 4, use all kinds of exec() function family               *
 * including execl() execle() execlp() execv() execvp() execvpe() *
 * It is very amazing that exec is not itsef a function          */

int main(int argc, char *argv[], char *envp[]) {
	int rc = fork();
	if (rc < 0) {
		fprintf(stderr, "fork failed!\n");
		exit(-1);
	} else if (rc == 0) {
		/* because the convention is that the first argument is always the same as the path of the program being run, like this: */
		
		//execl("/bin/ls", "/bin/ls", (char *) NULL);
		
		//execle("/bin/ls", "/bin/ls", (char *) NULL, envp);
		
		//execlp("ls", "ls", getenv("PWD"), (char *) NULL);
		
		/*
		char *myargs[2];
		myargs[0] = strdup("/bin/ls");
		myargs[1] = NULL;
		execv("/bin/ls", myargs);
		*/

		/*
		char *myargs[3];
		myargs[0] = strdup("/bin/ls");
		myargs[1] = strdup(getenv("PWD"));
		myargs[2] = NULL;
		execvp("/bin/ls", myargs); 
		*/
		char *myargs[3];
		myargs[0] = strdup("/bin/ls");
		myargs[1] = strdup(getenv("PWD"));
		myargs[2] = NULL;
		execvpe("/bin/ls", myargs, envp); 
	} else {
		wait(NULL);
		printf("father process\n");
	}
	return 0;
}
