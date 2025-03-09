// SPDX-License-Identifier: BSD-3-Clause

#include <sys/mman.h>
#include <errno.h>
#include <internal/syscall.h>

void *mmap(void *addr, size_t length, int prot, int flags, int fd, off_t offset)
{ //mapeaza un fisier in spatiul virtual al unui proces
	/* TODO: Implement mmap(). */
	long result = syscall(__NR_mmap, addr, length, prot, flags, fd, offset);
	if (result < 0) { //prot = protectiile de acces la memorie; flags determina daca maparea este
		errno = -result; //vizibila si pentru alte procese sau nu
		return (void *)-1; //fd este descriptorul fisierului care trebuie mapat
	} //in urma maparii, procesul poate accesa fisierul ca si cum ar face parte din propria memorie
	return (void *)result;
}

void *mremap(void *old_address, size_t old_size, size_t new_size, int flags)
{ //redimensioneaza o zona de memorie alocata in prealabil
	/* TODO: Implement mremap(). */
	long result = syscall(__NR_mremap, old_address, old_size, new_size, flags);
	if (result < 0) { //flags pot indica cum sa fie tratate datele deja aflate la acea zona
		errno = -result;
		return (void *)-1;
	}
	return (void *)result;
}

int munmap(void *addr, size_t length)
{ //dezaloca o zona de memorie alocata de mmap
	/* TODO: Implement munmap(). */
	int result = syscall(__NR_munmap, addr, length);
	if (result < 0) {
		errno = -result;
		return -1;
	}
	return result;
}
