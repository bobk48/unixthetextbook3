int main(void)
{
	int pid;

	pid = fork();
	if (pid == -1) {
	    perror("Fork failed");
	    exit(1);
	}
	/* Child process */
	if (pid == 0) { 
	    printf("Child's PID  = %d\n", getpid());
	    exit(0);
	}
	/* Parent process */
	printf("Parent's PID = %d\n", getpid());
	sleep(10);
	/* Parent process does not wait for the child */
	/* process and child becomes a zombie process */
	exit(0);
}
