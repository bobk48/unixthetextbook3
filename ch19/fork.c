#include <unistd.h>

extern int errno;

int main(void)
{
	int pid, status;

	pid = fork();
	if (pid == -1) {
	    perror("Fork failed.");
	    exit(1);
	}
	/* Child process */
	if (pid == 0) { 
	    printf("\nCHILD: Child here with PID = %d.\n", getpid());
	    printf("CHILD: My Mom has PID = %d.\n", getppid());
	    exit(0);
	}
	/* Parent process */
	wait(&status);
	printf("\nPARENT: Mom here with PID = %d.\n", getpid());
	printf("PARENT: Well done, child!\n\n");
	exit(0);
}
