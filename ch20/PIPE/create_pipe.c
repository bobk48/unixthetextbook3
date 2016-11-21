#include <unistd.h>

int main(void) 
{
	int data_channel[2];

	if (pipe(data_channel) == -1) {
	    perror("Pipe failed");
	    exit(1);
	}
	printf("The pipe descriptors are: \n");
	printf("	Read end:  %d\n", data_channel[0]);
	printf("	Write end: %d\n", data_channel[1]);
	exit(0);
}
