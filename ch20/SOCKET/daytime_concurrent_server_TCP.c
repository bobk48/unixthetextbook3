#include <stdio.h>
#include <time.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define BUFF	256
#define PORT	6001
#define QLEN	5

int main(int argc, char *argv[])
{
    int asock, psock, pid, caddrlen;
    struct sockaddr_in caddr;

    /* Exit if program is not run with two command line arguments. */
    if (argc != 3) {
        printf("Usage: server protocol port\n");
        exit(1);
    }

    /* Create a TCP socket, bind name to it, and put it in passive mode */
    psock = CreatePassiveSock(argv[1], argv[2], QLEN);

    while (1) {
	/* Accept actual connection from the client */
	if ((asock = accept(psock, (struct sockaddr *)&caddr, &caddrlen)) == -1) {
	    perror("accept failed");
	    exit(1);
	}
	/* Create a slave process and have it server the client   */
	/* The parent process closes the newly created active     */
	/* socket and goes back to accept the next client request */
	pid = fork();
	if (pid == -1) {
	    perror("fork failed");
	    exit(1);
	}
	if (pid == 0) { /* Child process */
	    close(psock); /* Deallocate passive socket */
	    /* The Daytime service: Send current time as string to */
	    /* client using active socket                          */
	    (void) TCPdaytime(asock);
	    exit(0);
	}
	else /* Parent process: Deallocate the active socket       */
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

/* TCPdaytime(socket descriptor) */
int TCPdaytime(int s)
{
    int 	n;
    time_t	current_time; /* Current time in ticks   */
    char	*str;         /* Pointer to time string  */
    char	*ctime();

    /* Get the current time in terms of clock ticks from   */
    /* UNIX Epoch, i.e., midnight January 1, 1970 and      */
    /* save it in current_time.                            */
    (void) time(&current_time);

    /* Convert current time into a humanly readable string */
    /* and return pointer to this string, saved in ptr     */
    str = ctime(&current_time);

    /* Send humanly readable time string to client process */
    if ((n = write(s, str, strlen(str))) == -1) {
	perror("write call failed");
	exit(1);
    }
    return 0;
}
