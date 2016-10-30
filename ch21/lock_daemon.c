#include <fcntl.h>
#include <unistd.h>
#include <sys/file.h> 
#include <sys/signal.h> 
#include <sys/stat.h> 

#define SIZE 32
#define LOCKMODE (S_IRUSR|S_IWUSR|S_IWGRP|S_IROTH)
#ifdef __sun
#define LOCKFILE "/export/home/sarwar/Servers/testd.lock"
#else
#define LOCKFILE "/usr/home/sarwar/Servers/testd.lock"
#endif

int main(void)
{
        int pid, lockfd;
	char buf[SIZE];
	struct flock lock;
 
        pid = fork();
        if (pid == -1) {
            perror("Fork failed");
            exit(1);
        }
        /* Parent process */
        if (pid > 0) {
            exit(0);
        }
	/* Child process: Continues and becomes the server */
	/* process running forever as a daemon             */

        /* Ignore signals */
        signal(SIGHUP, SIG_IGN);
        signal(SIGINT, SIG_IGN);

        /* Set umask */
        (void) umask(027);

        /* Allow only a single copy of the daemon */
        /* Open (or create) LOCKFILE              */
        lockfd = open(LOCKFILE, O_RDWR | O_CREAT, LOCKMODE);
        if (lockfd == -1) {
            perror("open failed to create LOCKFILE");
            exit(1);
        }

#ifdef __sun
        /* Set lock */
        lock.l_start = 0; 
        lock.l_len = 0; 
        lock.l_type = F_WRLCK; 
        lock.l_whence = SEEK_SET; 

        /* Lock LOCKFILE for mutually exclusive access */
        if (fcntl(lockfd, F_SETLK, &lock)) {
            perror("Daemon already running");
            close(lockfd);
            exit(1);
        }
#else
        /* Lock LOCKFILE for mutually exclusive access */
        if (flock(lockfd, LOCK_EX | LOCK_NB)) {
            perror("Daemon already running");
            close(lockfd);
            exit(1);
        }
#endif

	(void) sprintf(buf, "Daemon PID: %d\n", getpid());
	(void) write(1, buf, strlen(buf));
	while (1) { 
	    /* Wait for a client request */
	    /* Serve the client request  */
	    sleep(10);     /* Dummy code */
	}
}
