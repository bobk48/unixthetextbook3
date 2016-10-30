#include <fcntl.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
	int fd;

	/* Open file */
	if (argc == 1) {
		printf("No file specified as command line argument.\n");
		exit(1);
	}
	close(0); /* Close standard input */
	if ((fd = open(argv[1], O_RDWR)) == -1) {
		perror("File opening");
		exit(1);
	} else
		printf("The file descriptor is %d.\n",fd);
	/* Close file */
	if (close(fd) == -1) {
		perror("File closing");
		exit(1);
	} 
	else 
		printf("File closed successfully.\n");
	exit(0);
}
