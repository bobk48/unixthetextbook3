#include <sys/types.h>
#include <sys/socket.h>

int main(void)
{
        int s1, s2;

        if ((s1 = socket(PF_INET, SOCK_STREAM, 0)) == -1) {
            perror("SOCK_STREAM socket failed");
            exit(1);
        }
        if ((s2 = socket(PF_INET, SOCK_DGRAM, 0)) == -1) {
            perror("SOCK_DGRAM socket failed");
            exit(1);
        }
        printf("The socket descriptor for the stream socket is: %d\n", s1);
        printf("The socket descriptor for the datagram socket is: %d\n", s2);
        exit(0);
}
