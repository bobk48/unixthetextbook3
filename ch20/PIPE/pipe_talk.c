#include <unistd.h>

#define SIZE 32

const char *Child_Greeting="Hello, mom!\n";

int main(void) 
{
	int data_channel[2], pid, nr, nw, nbytes;
	char buf[SIZE];

	if (pipe(data_channel) == -1) {
	    perror("Pipe failed");
	    exit(1);
	}
	pid = fork();
	if (pid == -1) {
	    perror("Fork failed");
	    exit(1);
	} 
	nbytes = strlen(Child_Greeting);
	if (pid == 0) {
	    close(data_channel[0]);
	    nw = write(data_channel[1], Child_Greeting, nbytes);
	    if (nw == -1) {
		perror("Write error");
		exit(1);
	    }
	    exit(0);
	}
	/* Parent process */
	close(data_channel[1]);
	nr = read(data_channel[0], buf, nbytes);
	if (nr == -1) {
	    perror("Read error");
	    exit(1);
	}
	nw = write(1, buf, nr);
	if (nw == -1) {
	    perror("Write to stdout failed");
	    exit(1);
	}
	printf("Well done, son!\n");
	exit(0);
}
