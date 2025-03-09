// SPDX-License-Identifier: BSD-3-Clause

#include <string.h>

char *strcpy(char *destination, const char *source)
{
	/* TODO: Implement strcpy(). */
	char *dest;
	for (dest = destination; *source != '\0'; source++, dest++)
		*dest = *source; //copiem din sursa in destinatie
	*dest = *source; //adaugam caracterul null la sfarsitul destinatiei
	return destination;
}

char *strncpy(char *destination, const char *source, size_t len)
{
	/* TODO: Implement strncpy(). */
	char *dest = destination;
	size_t i = 0;
	for(i = 0; i < len && *source != '\0'; i++, source++, dest++) {
		*dest = *source; //copiem primele len caractere din sursa
	}
	while(i < len) {
		*dest = '\0';
		dest++;
		i++;
	}
	return destination;
}

char *strcat(char *destination, const char *source)
{
	/* TODO: Implement strcat(). */
	char *dest = destination;
	while(*dest != '\0') {
		dest++; //aducem pointerul la final
	}
	while(*source != '\0') {
		*dest = *source; //concatenam sursa la dest
		dest++;
		source++;
	}
	*dest = '\0'; //adaugam null la final
	return destination;
}

char *strncat(char *destination, const char *source, size_t len)
{
	/* TODO: Implement strncat(). */
	char *dest = destination;
	while(*dest != '\0') {
		dest++; //poitam la finalul lui dest
	}
	while(len > 0 && *source != '\0') {
		*dest = *source; //concatenam primele len caractere
		dest++;
		source++;
		len--;
	}
	*dest = '\0'; //adaugam caracterul null
	return destination;
}

int strcmp(const char *str1, const char *str2)
{
	/* TODO: Implement strcmp(). */
	 while (*str1 && (*str1 == *str2)) //comparam stringurile caracter cu caracter
    {
        str1++; //trecem la urmatorul caracter in fiecare
        str2++;
    } //afisam diferenta lexico-grafica
    return *(const unsigned char*)str1 - *(const unsigned char*)str2;
}

int strncmp(const char *str1, const char *str2, size_t len)
{
	/* TODO: Implement strncmp(). */
	while (len > 0 && *str1 != '\0' && *str2 != '\0' && *str1 == *str2) {
        str1++; //se compara primele n caractere
        str2++;
        len--;
    } //se iese din bucla cand se intalnesc 2 caractere diferite

    if (len == 0) {
        return 0;
    }
    if (*str1 < *str2) {
        return -1; //daca primul caracter diferit din str1 este mai mic
    } //decat cel din str2, str2 este mai mare
    if (*str1 > *str2) { //daca primul caracter diferit din str1 este
        return 1; //mai mare decat cel din str2, str1 este mai mare
    }

    return 0; //daca se ajunge aici, str1 = str2
}

size_t strlen(const char *str)
{
	size_t i = 0;

	for (; *str != '\0'; str++, i++)
		;

	return i;
}

char *strchr(const char *str, int c)
{
	/* TODO: Implement strchr(). */
	while(*str != '\0') {
		if(*str == (char)c) { //cauta caracterul c in sir
			return (char *)str; //daca il gaseste
		} //se returneaza un pointer la prima aparitie a acestuia in sir
		str++;
	}
	if (*str == '\0') {
		return NULL; //verificam daca nu cumva sirul este null
	}
	return NULL;
}

char *strrchr(const char *str, int c)
{
	/* TODO: Implement strrchr(). */
	const char *value = 0;
	while(*str != '\0') { //cautam ultima aparitie a lui c in string
		if(*str == c) { //pornim de la inceputul sirului
			value = str; //cand gasim o aparitie
		} //memoram adresa aparitiei in value
		str++; //trecem la urmatorul caracter din sir
	}
	return (char *)value;
}

char *strstr(const char *haystack, const char *needle)
{
	/* TODO: Implement strstr(). */
	const char *a = haystack; //cautam un sir in alt sir
    const char *b = needle;

    if (*b == '\0') {
        return (char *)haystack; //verificam daca ce avem de cautat este null
    }

    while (*a != '\0') {
        if (*a == *b) { //daca primul caracter este la fel putem incepe
            a++; //sa cautam acul in carul cu fan
            b++;
            while (*b != '\0' && *a == *b) {
                a++; //incepam de la caracterul curent verificam daca
                b++; //needle se potriveste cu continuarea din haystack
            }
            if (*b == '\0') { //daca ajungem la finalul lui needle
                return (char *) (a - strlen(needle)); //inseamna ca l-am gasit in haystack
            } //returnam un pointer la inceputul potrivirii
			b = needle; //resetam needle
        }
        a = a - (b - needle) + 1; // Ne întoarcem și trecem la următorul caracter de la care
        b = needle; //sa incepem sa comparam
    }

    return NULL;
}

char *strrstr(const char *haystack, const char *needle)
{
	/* TODO: Implement strrstr(). */
	char *pos = (char *)haystack + strlen(haystack);
    while (pos >= haystack) { //incepem sa cautam de la sfarsitul stringului haystack
        char *match = strstr(pos, needle); //ne folosim de strstr
        if (match != NULL)
			return pos;
        pos--; //daca nu am gasit, decrementam pointerul pentru a cauta needle
    } //intr-o pozitie mai aproape de inceputul lui haystack pana gasim prima aparitie
    return NULL;
}

void *memcpy(void *destination, const void *source, size_t num)
{
	/* TODO: Implement memcpy(). */
	char *dest = (char *)destination; //pointer pt destinatie
	const char* src = (const char *)source; //pointer pentru sursa
	if(dest != NULL && src != NULL) { //verificam daca src si dest nu sunt null
		for(size_t n = num; n > 0; n--) { //parcurgem blocul de num octeti
			*dest = *src; //copiem din src in dest
			dest++; //trecem la urmatoarea pozitie in src si dest
			src++;
		}
	}
	return destination; //returnam un pointer la inceputul zonei de memorie destination
}

void *memmove(void *destination, const void *source, size_t num)
{
	/* TODO: Implement memmove(). */
	char *dest = (char *)destination; //pointer la destinatie
	const char *src = (const char *)source; //pointer la sursa
	if(src < dest && src + num > dest) { //verificam daca sunt suprapuneri
		dest = dest + (num - 1);
		src = src + (num - 1);
		for(int n = num; n > 0; n--) {
			*dest = *src; //copiem de la sfarsit spre inceput
			dest--;
			src--;
		}
	} else {
		for(size_t n = num; n > 0; n--) { //daca nu exista suprapuneri
			*dest = *src; //copiem de la inceput spre sfarsit
			dest++;
			src++;
		}
	}
	return destination; //returnam un pointer la inceputul zonei de memorie in care am mutat
}

int memcmp(const void *ptr1, const void *ptr2, size_t num)
{
	/* TODO: Implement memcmp(). */
	const unsigned char *p1 = (const unsigned char *)ptr1;
	const unsigned char *p2 = (const unsigned char *)ptr2;
	for(size_t i = 0; i < num; i++) { //iteram prin blocul de num octeti
		if (*p1 < *p2) { //daca primul primul octet din p1 este mai mare decat primul din p2
			return -1;
		} else if (*p1 > *p2) { //altfel
			return 1;
		}
		p1++; //trecem la urmatorul octet in ambele stringuri
		p2++;
	}
	return 0;
}

void *memset(void *source, int value, size_t num)
{
	/* TODO: Implement memset(). */
	unsigned char *s = (unsigned char *)source; //pointer la sursa
	for(size_t n = num; n > 0; n--) { //umplem zona de memorie cu valoarea specificata
		*s = (unsigned char) value;
		s++; //trecem la urmatorul octet
	}
	return s; //returnam pointer la inceputul zonei de memorie configurate
}
