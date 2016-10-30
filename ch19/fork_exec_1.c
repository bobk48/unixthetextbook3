#include <unistd.h>

extern int errno;

int main(void)
{
	int pid, status;

	pid = fork();
	if (pid == -1) {
	    perror("Fork failed");
	    exit(1);
	}
	/* Child process */
	if (pid == 0) { 
	    execl("/bin/date", "date", (char *) NULL);
	    perror("execl failed");
	    exit(1);
	}
	/* Parent proces */
	printf("Child PID = %d.\n", (int) pid);
	pid = wait(&status);
	printf("Child with PID %d has terminated.\n", (int) pid);
	exit(0);
}
