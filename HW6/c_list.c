#include "c_list.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static list_data_type list_types[CAPACITY];

int append_list_item(void* list[], int size, void* item, list_data_type type) {
    if (size >= CAPACITY) {
        return -1;
    }
    list[size] = item;
    list_types[size] = type;
    return size + 1;
}

void print_list(const void* list[], int size) {
    for (int i = 0; i < size; ++i) {
        switch (list_types[i]) {
            case int_type:
                printf("%d ", *(int*)list[i]);
                break;
            case float_type:
                printf("%f ", *(float*)list[i]);
                break;
            case string_type:
                printf("%s ", (char*)list[i]);
                break;
        }
    }
    printf("\n");
}