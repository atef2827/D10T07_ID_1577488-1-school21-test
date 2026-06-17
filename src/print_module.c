#include "print_module.h"

#include <stdio.h>
#include <time.h>

char print_char(char ch) {
    putchar(ch);
    return ch;
}

// Output one string through the `print` callback, character by character.
static void emit(char (*print)(char), const char* str) {
    if (print != NULL && str != NULL) {
        const char* cur = str;
        while (*cur != '\0') {
            print(*cur);
            cur++;
        }
    }
}

void print_log(char (*print)(char), char* message) {
    char time_buffer[16];
    time_t now = time(NULL);
    struct tm* local = localtime(&now);
    if (print != NULL && local != NULL) {
        strftime(time_buffer, sizeof(time_buffer), "%H:%M:%S", local);
        emit(print, Log_prefix);
        print(' ');
        emit(print, time_buffer);
        print(' ');
        emit(print, message);
        print('\n');
    }
}
