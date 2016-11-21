/* killer.c: killer signal pid */
/* Here 'killer' is the name of the executbale file for killer.c */

#include <sys/types.h>

int main(int argc, char *argv[])
{
	pid_t pid;
	int signal;

        if (argc != 3) {
            printf("Inappropriate number of command line arguments.\n");
            exit(0);
        }
        pid = atoi(argv[1]);
        signal = atoi(argv[2]);
	if (kill(pid, signal) == -1) {
	    perror("Kill failed");
	    exit(1);
	}
	exit(0);
}
