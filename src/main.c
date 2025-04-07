#define LINKED_LIST_IMPLEMENTATION
#define CIRCULAR_LIST_IMPLEMENTATION

#include "linkedlist.h"
#include "linkedlist_circular.h"
#include <stdio.h>

void print_int(int value) {
    printf("%d ", value);
}

void print_char(char value) {
    printf("%c ", value);
}

int main() {
    // Lista ligada normal
    List_int* nums = list_int_create();
    list_int_append(nums, 10);
    list_int_append(nums, 20);
    list_int_append(nums, 30);

    printf("Lista de enteros: ");
    list_int_print(nums, print_int);
    list_int_destroy(nums);

    // Lista circular
    CircularList_char* chars = list_char_create();
    list_char_append(chars, 'a');
    list_char_append(chars, 'b');
    list_char_append(chars, 'c');
    printf("\nLista circular de caracteres: ");
    list_char_print(chars, print_char);
    list_char_destroy(chars);
    return 0;
}
