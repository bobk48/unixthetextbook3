#include "fifo.h"

int main(void)
{
    char buff[SIZE];
    int readfd, writefd;
    int n, size;

    /* Open FIFOs. Assume that the server 
       has already created them. */
    if ((writefd = open(FIFO1, 1)) == -1) {
        perror ("client open FIFO1");
        exit (1);
    }
    if ((readfd = open(FIFO2, 0)) == -1) {
        perror ("client open FIFO2");
        exit (1);
    }

    /* client (readfd, writefd); */
    size = strlen(message1);
    if (write(writefd, message1, size) != size) {
        perror ("client write1");
        exit (1);
    }
    if ((n = read(readfd, buff, size)) == -1) {
        perror ("client read");
        exit (1);
    }
    else
        if (write(1, buff, n) != n) {
            perror ("client write2");
            exit (1);
        }
    close(readfd);
    close(writefd);

    /* Remove FIFOs now that we are done using them */
    if (unlink (FIFO1) == -1) {
        perror("client unlink FIFO1");
        exit (1);
    }
    if (unlink (FIFO2) == -1) {
        perror("client unlink FIFO2");
        exit (1);
    }
    exit (0);
}
