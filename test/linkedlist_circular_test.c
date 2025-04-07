#include <assert.h>
#include "linkedlist_circular.h"

void test_node_create() {
    Node_int* node = node_int_create(100);
    assert(node != NULL);
    assert(node->data == 100);
    assert(node->next == node); 
    node_int_destroy(node);
}

void test_list_create() {
    CircularList_int* list = list_int_create();
    assert(list != NULL);
    assert(list->head == NULL); 
    list_int_destroy(list);
}

void test_list_append() {
    CircularList_int* list = list_int_create();
    assert(list_int_append(list, 10) == true);
    assert(list->head->data == 10);
    assert(list->head->next == list->head); 
    list_int_destroy(list);
}

void print_int(int data) {
    printf("%d ", data);
}

void test_list_print() {
    CircularList_int* list = list_int_create();
    list_int_append(list, 1);
    list_int_append(list, 2);
    list_int_append(list, 3);
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