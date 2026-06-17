#include <stdio.h>
#include <stdlib.h>

#include "documentation_module.h"
#include "print_module.h"

int main(void) {
    int status = 0;
    char* documents[] = {Documents};
    int* availability_mask = NULL;

    print_log(print_char, Module_load_success_message);
    availability_mask = check_available_documentation_module(validate, Documents_count, Documents);

    if (availability_mask == NULL) {
        status = 1;
    } else {
        for (int i = 0; i < Documents_count; i++) {
            printf("[%15s : %s]\n", documents[i], availability_mask[i] ? "available" : "unavailable");
        }
        free(availability_mask);
    }

    return status;
}
