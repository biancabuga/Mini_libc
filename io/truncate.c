// SPDX-License-Identifier: BSD-3-Clause

#include <unistd.h>
#include <internal/syscall.h>
#include <errno.h>

int truncate(const char *path, off_t length)
{
	/* TODO: Implement truncate(). */
    int result = syscall(__NR_truncate, path, length); //path este calea catre fisierul a carui
    if (result < 0) { //dimensiune dorim sa o schimbam, iar length este dimensiunea specificata
        errno = -result; //codul de eroare specific
        return -1; //returnam o eroare
    }
    return result;
}
