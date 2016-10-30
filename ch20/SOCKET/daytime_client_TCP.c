#include <netdb.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define BUFF	256

int main(int argc, char *argv[])
{
    int csock; /* Descriptor for connected socket */

    if (argc != 4) {
	printf("Usage: %s hostname port protocol\n", argv[0]);
	exit(0);
    }

    csock = CreateConnectedSock(argv[1], argv[2], argv[3]);

    /* Perform client-side of the DAYTIME service using csock,   */
    /* the client socket connected the server-side active socket */
    DaytimeClientTCP(csock);

    /* Deallocate socket and return */
    close(csock);
    return 0;
}

/* Create a TCP or UDP socket, based on the third command line   */
/* argument. Connect the socket to the server whose name (IP     */
/* address and port number) is passed as command line arguments. */
/* Return the descriptor of the connected socket. In case of the */
/* UDP socket is not connected but the address of the remote     */
/* socket is stored in the local socket's data structure. This   */
/* allows us to communicate with the server using the read()     */
/* and write() system calls, instead of recvfrom() and sendto(). */
int CreateConnectedSock(char *ip, char *portstr, char *protocol) 
{
    int s, port, type, saddrlen;
    char *endptr;
    struct sockaddr_in saddr;
    struct hostent *server;

    /* Convert portstr to port number as integer. Display  */
    /* error message and exit if portstr is not a number.  */
    port = (int) strtol(portstr, &endptr, 10);
    if (*endptr) {
        printf("\nPlease specify a positive integer for port.\n");
        exit(1);
    }

    saddrlen = sizeof(saddr);
    memset(&saddr, 0, saddrlen);
    saddr.sin_family = AF_INET;
    saddr.sin_port = htons(port);
    if (server = gethostbyname(ip))
        memcpy(&saddr.sin_addr.s_addr, server->h_addr, server->h_length);
    else
        if ((saddr.sin_addr.s_addr = inet_addr(ip)) == INADDR_NONE) {
            printf("No such host\n");
            exit(1);
        }

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

    /* Send connection request to the server process */
    if (connect(s, &saddr, saddrlen) == -1) {
        perror("connect failed");
        exit(1);
    }
    return s;
}

/* Client side of the DAYTIME service. 'sock' is the  */
/* client socket connected to serve's active socket.  */
void DaytimeClientTCP(int sock)
{
    int n;
    char buf[BUFF];

    /* Read time string from server and display on screen */
    while ((n = read(sock, buf, BUFF)) > 0) 
	write (1, buf, n); 
}
