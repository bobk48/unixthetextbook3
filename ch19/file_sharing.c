/* file_sharing.c: fileshare filename nbytes */
/* Here 'fileshare' is th ename of the executable file for file_sharing.c */

#include <fcntl.h>
#include <unistd.h>
#include <sys/wait.h>

#define SIZE 512

int main(int argc, char *argv[])
{
	int fd, n, nr, nbytes, pid, status;
	char buf[SIZE];

	/* Open file */
	if (argc != 3) {
		printf("%s filename nbytes\n", argv[1]); 
		exit(1);
	}
	nbytes = atoi(argv[2]);
	if ((fd = open(argv[1], O_RDWR)) == -1) {
		perror("File opening");
		exit(1);
	} 
	/* Create a child */
	pid = fork();
	/* Child process */
	if (pid == 0) { 
	    /* Read and display on stdout */
            if ((nr = read(fd, buf, nbytes)) == -1) {
                perror("Read failed");
                exit(1);
            }
            write(1, buf, nr); /* Throw on standard output */
	    n = lseek(fd, 0L, SEEK_CUR);
	    printf("\n\nCHILD: position of the file pointer after I/O is %d\n\n", n);
	    close(fd);
	    exit(0);
	} 
	/* Parent process */
	sleep(1); /* Allow the child process to do I/O first. */
	/* Read and display on stdout */
        if ((nr = read(fd, buf, nbytes)) == -1) {
            perror("Read failed");
            exit(1);
        }
        write(1, buf, nr); /* Throw on standard output */
 	n = lseek(fd, 0L, SEEK_CUR);
	printf("\n\nPARENT: position of the file pointer after I/O is %d\n\n", n);
	close(fd);
	while (wait3(&status, WNOHANG, 0) >= 0)
		; 
	exit(0);
}
