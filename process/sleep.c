#include <unistd.h>
#include <time.h>
#include <errno.h>

unsigned sleep(unsigned int seconds)
{
struct timespec rqtp;
	rqtp.tv_sec = seconds; //seteaza campurile structurii timespec
	rqtp.tv_nsec = 0;
	nanosleep(&rqtp, NULL); //apeleaza nanosleep
	return 0;
}
