#include <time.h>
#include <stddef.h>
#include <errno.h>
#include <unistd.h>
#include <internal/syscall.h>

#define __NR_nanosleep 35

int nanosleep(const struct timespec *req, struct timespec *rem) { //suspenda executia unui program
	int result = syscall(__NR_nanosleep, req, rem); //req este un pointer la o structura timespec
	if(result < 0) { //timespec are 2 campuri tv_sec(secunde) si tv_nsec(nanosecunde)
		errno = -result; //rem este o structura timespec care poate stoca timpul ramas de asteptat
		return -1; //daca nanosleep este intrerupt (poate fi NULL)
	}
	return 0;
}
