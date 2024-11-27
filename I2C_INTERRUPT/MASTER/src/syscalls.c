#include "syscalls.h"
#include <sys/stat.h>
#include <unistd.h>

int _write(int file, char *ptr, int len) {
    // Implement code to write data to UART if needed
    return len; // Return the number of bytes written
}

int _read(int file, char *ptr, int len) {
    // Implement code to read data from UART if needed
    return 0; // Return the number of bytes read
}
int _close(int file) {
    // Dosya kapama işlevi yoksa, -1 döndürmek genellikle yeterlidir.
    return -1;
}

int _lseek(int file, int ptr, int dir) {
    // Konumlandırma işlevi yoksa, -1 döndürmek yeterlidir.
    return -1;
}
