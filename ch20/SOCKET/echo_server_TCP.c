/*
Usage: Server-name Protocol Port
Here, Protocol is the transport level protocol
and Port is the procotol port number where the
service is to be offered.
*/

#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define BUFF	256
#define QLEN	16

int main(int argc, char *argv[])
{
    int psock, asock, caddrlen;
    struct sockaddr_in caddr;

    /* Exit if program is not run with two command line arguments. */
    if (argc != 3) {
	printf("Usage: server protocol port\n");
	exit(1);
    }

    /* Create a TCP socket, bind name to it, and put it in passive mode */
    psock = CreatePassiveSock(argv[1], argv[2], QLEN);

    caddrlen = sizeof(caddr);
    while (1) {
	/* Accept actual connection from the client */
	if ((asock = accept(psock, (struct sockaddr *)&caddr, &caddrlen)) == -1) {
	    perror("accept failed");
	    exit(1);
	}

	/* TCP echo service code */
	EchoServerTCP(asock);

	/* Close active socket */
	close(asock);
    } /* while */
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

/* Provide echo service to a client. 'sock' is the     */
/* active socket connected to the client-side socket.  */
void EchoServerTCP(int sock)
{
    int nr, nw;
    char buf[BUFF];

    /* Communicate with client: read and write back */
    memset(buf, 0, BUFF);
    if ((nr = read(sock, buf, BUFF-1)) == -1) {
	perror ("socket read error");
	exit(1);
    }

    /* Write back (echo) the same data to client */
    if ((nw =  write(sock, buf, nr)) == -1) {
        perror("socket write error");
        exit(1);
    }
}
