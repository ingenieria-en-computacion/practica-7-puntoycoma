#include "linkedlist.h"

Node_int* node_int_create(int data) {
    Node_int* new_node = malloc(sizeof(Node_int));
    if (!new_node) return NULL;
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

void node_int_destroy(Node_int* node) {
    free(node);
}

List_int* list_int_create() {
    List_int* list = malloc(sizeof(List_int));
    if (!list) return NULL;
    list->head = NULL;
    list->tail = NULL;
    return list;
}

bool list_int_append(List_int* list, int data) {
    Node_int* new_node = node_int_create(data);
    if (!new_node) return false;
    if (list->tail) {
        list->tail->next = new_node;
    } else {
        list->head = new_node;
    }
    list->tail = new_node;
    return true;
}

void list_int_print(List_int* list, void (*print_func)(int)) {
    Node_int* current = list->head;
    while (current) {
        print_func(current->data);
        current = current->next;
    }
}

void list_int_destroy(List_int* list) {
    Node_int* current = list->head;
    while (current) {
        Node_int* temp = current;
        current = current->next;
        node_int_destroy(temp);
    }
    free(list);
}
