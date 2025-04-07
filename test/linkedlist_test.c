#include <assert.h>
#include "linkedlist.h"

void test_node_create() {
    Node_int* node = node_int_create(42);
    assert(node != NULL);
    assert(node->data == 42);
    assert(node->next == NULL);
    node_int_destroy(node);
}

void test_list_create() {
    List_int* list = list_int_create();
    assert(list != NULL);
    assert(list->head == NULL);
    assert(list->tail == NULL);
    list_int_destroy(list);
}

void test_list_append() {
    List_int* list = list_int_create();
    assert(list_int_append(list, 10) == true);
    assert(list->head != NULL);
    assert(list->tail != NULL);
    assert(list->head->data == 10);
    assert(list->tail->data == 10);
    list_int_append(list, 20);
    assert(list->tail->data == 20);
    list_int_destroy(list);
}

void print_int(int data) {
    printf("%d ", data);
}

void test_list_print() {
    List_int* list = list_int_create();
    list_int_append(list, 5);
    list_int_append(list, 10);
    list_int_append(list, 15);
    printf("Lista: ");
    list_int_print(list, print_int);
    printf("\n");
    list_int_destroy(list);
}

int main() {
    test_node_create();
    test_list_create();
    test_list_append();
    test_list_print();
    printf("Todas las pruebas pasaron correctamente.\n");
    return 0;
}