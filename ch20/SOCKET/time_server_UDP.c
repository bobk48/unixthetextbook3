/*
Usage: Server-name Protocol Port
Here, Protocol is the transport level protocol
and Port is the procotol port number where the
service is to be offered.
*/
#include <time.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define UNIXEPOCH 2208988800
#define QLEN	  0
#define BUFF	  256

int main(int argc, char *argv[]) 
{
    int s;

    /* Exit if program is not run with two command line arguments. */
    if (argc != 3) {
        printf("Usage: server protocol port\n");
        exit(1);
    }

    /* Create a TCP socket, bind name to it, and put it in passive mode */
    s = CreatePassiveSock(argv[1], argv[2], QLEN);

    /* Read client request and send current time to client */
    while (1) {
	/* UDP time service code */
	TimeServerUDP(s);
    }
}

/* Create a TCP or UDP socket, bind a name to it, and put it in   */
/* passive mode if it is a TCP socket.                            */
/* 'protocol' is transport layer protocol ("tcp", "udp", etc).    */
/* 'portptr' is pointer to port number as a character string.     */
/* 'qlen' is the queue length associated with the passive socket. */
int CreatePassiveSock(char *protocol, char *portstr, int qlen)
{
    int s, port, type, saddrlen;
    char *endptr;
    struct sockaddr_in saddr;

    /* Convert portstr to port number as integer. Display  */
    /* error message and exit if portstr is not a number.  */
    port = (int) strtol(portstr, &endptr, 10);
    if (*endptr) {
        printf("\nPlease specify a positive integer for port.\n");
        exit(1);
    }

    /* Initialize socket structure */
    saddrlen = sizeof(saddr);
    memset(&saddr, 0, saddrlen);
    saddr.sin_family = AF_INET;
    saddr.sin_addr.s_addr = INADDR_ANY;
    saddr.sin_port = htons(port);

    if (strcmp("tcp", protocol) == 0)
        type = SOCK_STREAM;
    else if (strcmp("udp", protocol) == 0)
        type = SOCK_DGRAM;
    else {
        printf("Unsupported protocol\n");
        exit(1);
    }

    /* Create a TCP or UDP socket for IPv4 */
    if ((s = socket(PF_INET, type, 0)) == -1) {
        perror("socket call failed");
        exit(1);
    }

    /* Bind address to socket */
    if (bind(s, (struct sockaddr *)&saddr, saddrlen) == -1) {
        perror("bind failed");
        exit(1);
    }

    /* If it is a TCP socket, put it in passive mode, */
    /* i.e., ready to listen for incoming connection  */
    if (type == SOCK_STREAM) {
        if (listen(s, qlen) == -1) {
            perror("listen failed");
            exit(1);
        }
    }

    /* Return the TCP passive or UDP socket with a    */
    /* name bound to it.                              */
    return s;
}

/* Provide TIME service to a client. 'sock' is the  */
/* server-side socket.  */
void TimeServerUDP(int sock)
{
    int n, saddrlen;
    char buf[BUFF];
    time_t current_time;
    struct sockaddr_in saddr;

    saddrlen = sizeof(saddr);
    /* Read client request and send current time to client */
    n = recvfrom(sock, buf, sizeof(buf), 0,
                        (struct scokaddr *) &saddr, &saddrlen);
    if (n == -1) {
	perror("recvfom failed");
	exit(1);
    }
    (void) time(&current_time);
    current_time = htonl((u_long) (current_time + UNIXEPOCH));
    (void) sendto(sock, (char *) &current_time, sizeof(current_time), 0,
                        (struct sockaddr *)&saddr, saddrlen);
}
