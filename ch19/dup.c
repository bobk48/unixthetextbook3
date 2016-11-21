#include <fcntl.h>
#include <sys/stat.h>

int main(int argc, char *argv[])
{
	int fd;

	/* Open file */
	if (argc == 1) {
		printf("No file specified as command line argument.\n");
		exit(1);
	}
	if ((fd = open(argv[1], O_WRONLY|O_CREAT|O_TRUNC, S_IREAD|S_IWRITE)) == -1) {
		perror("File opening");
		exit(1);
	} 
	/* Close standard output */
	close(1); 
	/* Duplicate fd into file descriptor 1, i.e., stdout */
	if (dup(fd) == -1) {
		perror("Duplicating file descriptor");
		exit(1);
	}  
	/* Close fd in order to release the extra slot in the PPFDT */
	if (close(fd) == -1) {
		perror("File closing");
		exit(1);
	} 
	/* Stdout redirected to the file passed as command line argument */
	printf("Hello, world!\n");
	exit(0);
}
