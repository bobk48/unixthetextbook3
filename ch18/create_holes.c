#include <fcntl.h>
#include <unistd.h>
#include <string.h>

#define HSIZE	512L
int main(int argc, char *argv[])
{
	int fd, i, n, nholes, nw;
	char *buf="Random data for creating holes.";

	/* Open the given file */
	if (argc != 3) {
		printf("Inappropriate number of command line arguments.\n");
		exit(0);
	}
	nholes = atoi(argv[2]);
	if ((fd = open(argv[1], O_WRONLY)) == -1) {
		perror("File opening");
		exit(1);
	} 
	for (i=0; i<nholes; i++) {
		n = lseek(fd, HSIZE, SEEK_END);
		nw = write(fd, buf, strlen(buf));
	}
        if (close(fd) == -1) {
                perror("File closing");
                exit(1);
        }
	return(0);
}
