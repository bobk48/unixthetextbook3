#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/errno.h>
extern int errno;
#define FIFO1 "/tmp/fifo.1"
#define FIFO2 "/tmp/fifo.2"
#define PERMS 0666
#define SIZE 512
static char* message1 = "Hello, world!\n";
static char* message2 = "Hello, class!\n";
