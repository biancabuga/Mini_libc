// SPDX-License-Identifier: BSD-3-Clause

#include <unistd.h>
#include <internal/syscall.h>
#include <errno.h>

off_t lseek(int fd, off_t offset, int whence)
{
    off_t result = syscall(__NR_lseek, fd, offset, whence); //facem apelul de sistem corespunzator
    if (result < 0) {
        // dacă a eșuat setăm errno corespunzător
        errno = -result;
        return -1; // returnăm -1 pentru a indica o eroare
    }
    // returnăm rezultatul obținut din syscall
    return result;
}
