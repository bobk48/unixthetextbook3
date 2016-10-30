#include "fifo.h"

int main(void)
{
    char buff[SIZE];
    int readfd, writefd;
    int n, size;

    /* Create two FIFOs and open them for 
       reading and writing */
    if ((mknod (FIFO1, S_IFIFO | PERMS, 0) == -1) 
                        && (errno != EEXIST)) {
        perror ("mknod FIFO1");
        exit (1);
    }
    if (mkfifo(FIFO2, PERMS) == -1) {
        unlink (FIFO1);
        perror("mknod FIFO2");
        exit (1);
    }

    if ((readfd = open(FIFO1, 0)) == -1) {
        perror ("open FIFO1");
        exit (1);
    }
    if ((writefd = open(FIFO2, 1)) == -1) {
        perror ("open FIFO2");
        exit (1);
    }

    /* server (readfd, writefd); */
    size = strlen(message1);
    if ((n = read(readfd, buff, size)) == -1) {
        perror ("server read");
        exit (1);
    }
    if (write (1, buff, n) < n) {
        perror("server write1");
        exit (1);
    }
    size = strlen(message2);
    if (write (writefd, message2, size) != size) {
        perror ("server write2");
        exit (1);
    }
    close (readfd);
    close (writefd);
}
