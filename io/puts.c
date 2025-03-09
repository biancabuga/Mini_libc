#include <fcntl.h>
#include <internal/syscall.h>
#include <stdarg.h>
#include <errno.h>
#include <string.h>

int puts(const char *str) {
    size_t len = strlen(str); //obtinem lungimea stringului
    if (syscall(1, 1, str, len) == -1) { //facem un apel de sistem pentru a scrie sirul la iesirea standard
        return -1; //daca esueaza
    }
    if (syscall(1, 1, "\n", 1) == -1) { //facem un apel de sistem pentru a scrie caracterul newline la sfarsit
        return -1;
    }
    return 0;
}
