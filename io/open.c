// SPDX-License-Identifier: BSD-3-Clause

#include <fcntl.h>
#include <internal/syscall.h>
#include <stdarg.h>
#include <errno.h>

int open(const char *filename, int flags, ...)
{
	/* TODO: Implement open system call. */
	int fd = syscall(2, filename, flags); //apel de sistem pentru a deschide un fisier

    if (fd >= 0) {
        return fd; //descriptorul fisierului
    }
    errno = -fd; //initializam errno in cazul in care a esuat apelul pentru a semnala eroarea
    return -1;
}
