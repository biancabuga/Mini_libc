// SPDX-License-Identifier: BSD-3-Clause

#include <unistd.h>
#include <internal/syscall.h>
#include <stdarg.h>
#include <errno.h>

int close(int fd)
{
	/* TODO: Implement close(). */
	#ifdef __NR_close
    int result = syscall(__NR_close, fd);
#else //verificam daca numarul standard pentru apelul de sistem este initiat
    int result = syscall(3, fd);
#endif
    if (result == -1) {
        return -errno; //errno contine codul de eroare al ultimei operatii
    }
    return 0;
}

