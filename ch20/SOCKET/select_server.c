#include <time.h>
#include <netdb.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <sys/select.h>

#define UNIXEPOCH 2208988800
#define TIME      "8001"
#define ECHO      "8002"
#define BUFF      256
#define QLEN      5

int main(int argc, char *argv[])
{
    int s1, s2, nfds;
    fd_set rfds; 

    /* Create UDP sockets for the TIME and ECHO services at   */
    /* ports 8001 and 8002, respectively, bind names to them, */
    /* and return their descriptors in s1 and s2.             */ 
    s1 = CreatePassiveSock("udp", TIME, QLEN);
    s2 = CreatePassiveSock("udp", ECHO, QLEN);

    /* Set number of descriptors to be monitored by select   */
    nfds = s2+1; 

    /* Set the read descriptor set to zero                   */
    FD_ZERO(&rfds);

    /* Set bits for TIME and ECHO in the read descriptor set */
    FD_SET(s1, &rfds);
    FD_SET(s2, &rfds); 

    while (1) {
	if (select(nfds, &rfds, NULL, NULL, NULL) == -1) {
	    perror("select failed");
	    exit(1);
	}
	if (FD_ISSET(s1, &rfds)) {
	    /* UDP time service code */
	    TimeServerUDP(s1);
	}
	if (FD_ISSET(s2, &rfds)) {
	    /* UDP time service code */
	    EchoServerUDP(s2);
	}
	/* Reset descriptors */
	FD_SET(s1, &rfds); 
	FD_SET(s2, &rfds); 
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

    /* If it is a TCP socket, put it in passive mode, i.e., */
    /* ready to listen for incoming connection.             */
    if (type == SOCK_STREAM) {
        if (listen(s, qlen) == -1) {
            perror("listen failed");
            exit(1);
        }
    }

    /* Return the TCP passive or UDP socket with a name     */
    /* bound to it.                                         */
    return s;
}

/* Provide TIME service to a client. 'sock' is the server-  */
/* side socket.                                             */
void TimeServerUDP(int sock)
{
    int n, caddrlen;
    char buf[BUFF];
    time_t current_time;
    struct sockaddr_in caddr;

    caddrlen = sizeof(caddr);
    /* Read client request and send current time to client  */
    n = recvfrom(sock, buf, sizeof(buf), 0,
                        (struct sockaddr *)&caddr, &caddrlen);
    if (n == -1) {
	perror("recvfom failed");
	exit(1);
    }
    (void) time(&current_time);
    current_time = htonl((u_long) (current_time + UNIXEPOCH));
    (void) sendto(sock, (char *) &current_time, sizeof(current_time), 0,
                        (struct sockaddr *)&caddr, caddrlen);
}

/* Provide echo service to a UDP client.                    */
void EchoServerUDP(int sock)
{
    int n, caddrlen;
    char buf[BUFF];
    struct sockaddr_in caddr;

    /* Communicate with client: read and write back         */
    memset(buf, 0, BUFF);
    n = recvfrom(sock, buf, sizeof(buf), 0,
                        (struct sockaddr *)&caddr, &caddrlen);
    if (n == -1) {
	perror("recvfom failed");
	exit(1);
    }
    (void) sendto(sock, buf, sizeof(buf), 0,
                        (struct sockaddr *)&caddr, caddrlen);
}
