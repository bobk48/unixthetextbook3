#include <fcntl.h>
#include <unistd.h>
#include <errno.h>

#define SIZE 512
#define MODE 0644
#define Message "Hello, world!\n"

extern int errno;

int main(void)
{
	int n, nr, nw, fd, pid, status;
	char buf[SIZE];

	pid = fork();
	if (pid == -1) {
	    perror("Fork failed");
	    exit(1);
	}
	/* Child process */
	if (pid == 0) { 
	    execl("/bin/mkdir", "mkdir", "dir1", (char *) NULL);
	    perror("execve failed.\n");
	    exit(1);
	}
	/* Parent process */
	while (((pid = wait(&status)) == -1) && errno == EINTR)
	    ;
	if (pid == -1) {
	    perror("Wait failed");
	    exit(1);
	}
	
	/* Open or create dir1/foo file */
	if ((fd = open("dir1/foo", O_RDWR|O_CREAT, MODE)) == -1) {
	    perror("Open failed");
	    exit(1);
	}
	/* Write to foo */
	if ((nw = write(fd, Message, strlen(Message))) == -1 ) {
	    perror("Write failed"); 
	    exit(1);
	}

	/* Rewind file pointer */
	n = lseek(fd, 0L, SEEK_SET);

	/* Read back from foo */
	if ((nr = read(fd, buf, nw)) == -1) {
	    perror("Read failed");
	    exit(1);
	}

	/* Throw on standard output */
	write(1, buf, nr); 
        if (close(fd) == -1) {
            perror("File closing");
            exit(1);
        } 

	/* Remove dir1/foo to make dir1 an emptry directory */
	unlink("dir1/foo");

	/* Remove the now empty directory dir1 */
	rmdir("dir1");
	exit(0);
}
