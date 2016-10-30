#include <fcntl.h>
#include <unistd.h>

#define HSIZE	512L

int main(int argc, char *argv[])
{
	int fd, newfilesize, size_o, size_t;

	/* Open the given file */
	if (argc != 3) {
		printf("Inappropriate number of command line arguments.\n");
		exit(0);
	}
	newfilesize = atoi(argv[2]);
	if ((fd = open(argv[1], O_WRONLY)) == -1) {
		perror("File opening");
		exit(1);
	} 
	size_o = lseek(fd, 0, SEEK_END); /* Size of original file */
	if (truncate(argv[1], newfilesize) == -1) {
		perror("Truncating file");
		exit(1);
	}
	size_t = lseek(fd, 0, SEEK_END); /* Size of truncated file */
	printf("The size of the original file is %d bytes.\n", size_o);
	printf("The size of the truncated file is %d bytes.\n", size_t);
        if (close(fd) == -1) {
                perror("File closing");
                exit(1);
        }
	return(0);
}
