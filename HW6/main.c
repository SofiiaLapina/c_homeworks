#include "c_list.h"
#include <stdio.h>

int main() {
    void* list[CAPACITY];    // Масив для зберігання елементів
    int size = 0;            // Поточний розмір масиву

    int i = 42;
    float f = 3.14;
    char* s1 = "C programming";
    char* s2 = "Home task 6";

    size = append_list_item(list, size, &i, int_type);      // Додати ціле число
    size = append_list_item(list, size, &f, float_type);    // Додати float
    size = append_list_item(list, size, s1, string_type);   // Додати рядок
    size = append_list_item(list, size, s2, string_type);   // Додати рядок

    // Виведення розміру списку
    printf("List size = %d\n", size);

    // Виведення елементів
    print_list((const void**)list, size);

    return 0;
}
