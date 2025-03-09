// SPDX-License-Identifier: BSD-3-Clause

#include <sys/stat.h>
#include <internal/syscall.h>
#include <errno.h>

int fstat(int fd, struct stat *st)
{
	/* TODO: Implement fstat(). */
    int result = syscall(__NR_fstat, fd, st); //fd este descriptorul fisierului
    if (result < 0) { //iar st este un pointer la o structura de tip stat care va fi populata cu informatii
        errno = -result; //codul de eroare
        return -1; //semnalam eroarea
    }
    return 0;
}
