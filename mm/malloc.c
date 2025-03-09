// SPDX-License-Identifier: BSD-3-Clause

#include <internal/mm/mem_list.h>
#include <internal/types.h>
#include <internal/essentials.h>
#include <sys/mman.h>
#include <string.h>
#include <stdlib.h>

void *malloc(size_t size)
{ //PROT reprezinta protectiile de acces; MAP determina comportamentul maparii
	/* TODO: Implement malloc(). */
	if (size == 0) {
		return NULL;
	}
	void *result = mmap(NULL, size, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
	if (result == MAP_FAILED) { //daca alocarea a esuat
		return NULL;
	}
	return result;
}

void *calloc(size_t nmemb, size_t size)
{
	/* TODO: Implement calloc(). */
	int space = nmemb * size; //numarul total de octeti necesari pt toate elementele
	void *pointer = malloc(space); //apelam malloc pt a aloca spatiu
	memset(pointer, 0, space); //populam zona de memorie alocata cu 0
	return pointer;
}

void free(void *ptr)
{
	/* TODO: Implement free(). */
	if (ptr == NULL) {
		return;
	}
	size_t *start = (size_t *)ptr -1; //adresa unde sa afla stocat size
	size_t size = *start; //apelam munmap pt a elibera memoria
	munmap(start, size + sizeof(size_t)); //eliberam inclusiv spatiul alocat pentru size
}

void *realloc(void *ptr, size_t size)
{
	/* TODO: Implement realloc(). */
	void *pointer = malloc(size); //alocarea memoriei cu malloc
	memcpy(pointer, ptr, size); //copierea datelor din vechiul bloc de memorie in cel nou
	return pointer;
}

void *reallocarray(void *ptr, size_t nmemb, size_t size)
{
	/* TODO: Implement reallocarray(). */
	if (size == 0) {
		return NULL;
	}
	int space = nmemb * size;
	realloc(ptr, space);
	if(ptr == NULL) {
		return NULL; //verificam daca a esuat alocarea
	}
	return ptr;
}
