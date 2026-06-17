#include "documentation_module.h"

#include <stdarg.h>
#include <stdlib.h>

int validate(char* data) {
    int validation_result = 0;
    if (data != NULL) {
        validation_result = !strcmp(data, Available_document);
    }
    return validation_result;
}

int* check_available_documentation_module(int (*validate)(char*), int document_count, ...) {
    int* availability = NULL;
    if (validate != NULL && document_count > 0) {
        availability = malloc(sizeof(int) * document_count);
        if (availability != NULL) {
            va_list args;
            va_start(args, document_count);
            for (int i = 0; i < document_count; i++) {
                char* document = va_arg(args, char*);
                availability[i] = validate(document);
            }
            va_end(args);
        }
    }
    return availability;
}
