#include <sys/stat.h>
#include <sys/types.h>

int main(int argc, char *argv[]) 
{
        struct stat sv;

	if (argc != 2) {
		printf("Inappropriate number of command line arguments.\n");
		exit(0);
	}
        if (stat(argv[1], &sv) == 0 && S_ISREG(sv.st_mode)) 
                printf("File size is %d bytes\n", sv.st_size);
        else 
                perror("stat");
}
