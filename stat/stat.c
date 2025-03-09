// SPDX-License-Identifier: BSD-3-Clause

#include <sys/stat.h>
#include <internal/syscall.h>
#include <fcntl.h>
#include <errno.h>

int stat(const char *restrict path, struct stat *restrict buf)
{
	/* TODO: Implement stat(). */
    long result = syscall(__NR_stat, path, buf); //apelul de sistem pentru stat in care parametri sunt
    if (result < 0) { //calea catre fisierul despre care dorim informatii si un buffer pt a le scrie
        errno = -result; //errno va indica un cod specifi de eroare
        return -1; //a avut loc o eroare la apelul dat
    }
    return 0;
}
