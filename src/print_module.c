#include "print_module.h"

#include <stdio.h>
#include <time.h>

char print_char(char ch) {
    putchar(ch);
    return ch;
}

// Output one string through the `print` callback, character by character.
static void emit(char (*print)(char), const char* str) {
    if (str == NULL) {
        return;
    }
    while (*str != '\0') {
        print(*str);
        str++;
    }
}

void print_log(char (*print)(char), char* message) {
    if (print == NULL) {
        return;
    }

    char time_buffer[16];
    time_t now = time(NULL);
    struct tm* local = localtime(&now);
    strftime(time_buffer, sizeof(time_buffer), "%H:%M:%S", local);

    emit(print, Log_prefix);
    print(' ');
    emit(print, time_buffer);
    print(' ');
    emit(print, message);
    print('\n');
}
