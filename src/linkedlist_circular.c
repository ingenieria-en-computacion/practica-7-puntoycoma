#include "linkedlist_circular.h"

Node_char* node_char_create(char data) {
    Node_char* new_node = malloc(sizeof(Node_char));
    if (!new_node) return NULL;
    new_node->data = data;
    new_node->next = new_node;
    return new_node;
}

void node_char_destroy(Node_char* node) {
    free(node);
}

CircularList_char* list_char_create() {
    CircularList_char* list = malloc(sizeof(CircularList_char));
    if (!list) return NULL;
    list->head = NULL;
    return list;
}

bool list_char_append(CircularList_char* list, char data) {
    Node_char* new_node = node_char_create(data);
    if (!new_node) return false;
    if (list->head == NULL) {
        list->head = new_node;
    } else {
        Node_char* temp = list->head;
        while (temp->next != list->head) {
            temp = temp->next;
        }
        temp->next = new_node;
    }
    return true;
}

void list_char_print(CircularList_char* list, void (*print_func)(char)) {
    if (!list->head) return;
    Node_char* current = list->head;
    do {
        print_func(current->data);
        current = current->next;
    } while (current != list->head);
}

void list_char_destroy(CircularList_char* list) {
    if (!list->head) {
        free(list);
        return;
    }
    Node_char* current = list->head;
    do {
        Node_char* temp = current;
        current = current->next;
        node_char_destroy(temp);
    } while (current != list->head);
    free(list);
}
