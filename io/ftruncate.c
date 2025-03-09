// SPDX-License-Identifier: BSD-3-Clause

#include <unistd.h>
#include <internal/syscall.h>
#include <errno.h>

int ftruncate(int fd, off_t length)
{
	/* TODO: Implement ftruncate(). */
	int result;
    result = syscall(__NR_ftruncate, fd, length); //la fel ca truncate doar ca acum dorim
    if (result < 0) { //sa schimbam dimensiunea unui fisier deja deschis folosind descriptorul
        errno = -result; //afisam eroarea corespunzatoare daca este cazul
        return -1;
    }
    return result;
}
