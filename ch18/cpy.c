#include <fcntl.h>
#include <unistd.h>

#define SIZE 512

void closefd(int);

int main(int argc, char *argv[])
{
	int rfd, wfd, nr, nw;
	char buf[SIZE];

	/* Open the given file */
	if (argc != 3) {
		printf("Inappropriate number of command line arguments.\n");
		exit(0);
	}
	if ((rfd = open(argv[1], O_RDONLY)) == -1) {
		perror("Source file opening");
		exit(1);
	} 
	if ((wfd = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0666)) == -1) {
		perror("Creation and opening of destination file");
		exit(1);
	} 
	while ((nr = read(rfd, buf, sizeof(buf))) != 0) {
		if (nr == -1) {
			perror("File reading");
			exit(1);
		}
		nw = write(wfd, buf, nr);
	}
	closefd(rfd);
	closefd(wfd);
	return(0);
}
void closefd(int fd)
{
	if (close(fd) == -1) {
		perror("File closing");
		exit(1);
	} 
}
