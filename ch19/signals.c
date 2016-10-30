#include <sys/signal.h>

#define TRUE 1

void nicetry(void);
void onalarm(int);

int main(void)
{
	signal(SIGHUP, SIG_IGN);
	signal(SIGINT, nicetry);
        signal(SIGALRM, onalarm); 
        alarm(10); 
        while (TRUE) {
	    printf("Waiting for alarm.\n");
	    sleep(9);
	}
}

void nicetry(void)
{
        printf("Nice try! Sorry you cannot terminate me like this.\n");
}

void onalarm(int signal)
{
        printf("Caught signal number %d. Going back to work.\n", signal);
}
