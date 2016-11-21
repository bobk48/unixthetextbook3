#include <unistd.h>

#define SIZE 32

const char *Child_Greeting="Hello, mom!\n";
const char *Parent_Greeting="Well done, son!\n";

int main(void) 
{
	int pipe1[2], pipe2[2]; 
	int pid, nr, nw, status, sizec, sizep;
	char buf[SIZE];

	sizec = strlen(Child_Greeting);
	sizep = strlen(Parent_Greeting);
	if (pipe(pipe1) == -1) {
	    perror("Pipe1 failed");
	    exit(1);
	}
	if (pipe(pipe2) == -1) {
	    perror("Pipe2 failed");
	    exit(1);
	}
	pid = fork();
	if (pid == -1) {
	    perror("Fork failed");
	    exit(1);
	} 
	if (pid == 0) {
	    close(pipe1[0]);
	    close(pipe2[1]);
	    nw = write(pipe1[1], Child_Greeting, sizec);
	    if (nw == -1) {
		perror("Write to pipe1 error in child");
		exit(1);
	    }
	    nr = read(pipe2[0], buf, sizep);
	    if (nr == -1) {
		perror("Read pipe2 error in child");
		exit(1);
	    }
	    nw = write(1, buf, nr);
	    if (nw == -1) {
		perror("Write to stdout failed in child");
		exit(1);
	    }
	    close(pipe1[1]);
	    close(pipe2[0]);
	    exit(0);
	}
	/* Parent process */
	close(pipe1[1]);
	close(pipe2[0]);
	nr = read(pipe1[0], buf, sizec);
	if (nr == -1) {
	    perror("Read pipe1 error in parent");
	    exit(1);
	}
	nw = write(1, buf, nr);
	if (nw == -1) {
	    perror("Write to stdout failed in parent");
	    exit(1);
	}
	nw = write(pipe2[1], Parent_Greeting, sizep);
	if (nw == -1) {
	    perror("Write to pipe2 error in parent");
	    exit(1);
	}
	close(pipe1[0]);
	close(pipe2[1]);
	wait(&status);
	exit(0);
}
