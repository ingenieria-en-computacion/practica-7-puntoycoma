#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

#define IMPLEMENT_LINKED_LIST(TYPE) \
    typedef struct Node_##TYPE { \
        TYPE data; \
        struct Node_##TYPE* next; \
    } Node_##TYPE; \
\
    Node_##TYPE* node_##TYPE##_create(TYPE data); \
    void node_##TYPE##_destroy(Node_##TYPE* node); \
\
    typedef struct { \
        Node_##TYPE* head; \
        Node_##TYPE* tail; \
    } List_##TYPE; \
\
    List_##TYPE* list_##TYPE##_create(); \
    bool list_##TYPE##_append(List_##TYPE* list, TYPE data); \
    void list_##TYPE##_print(List_##TYPE* list, void (*print_func)(TYPE)); \
    void list_##TYPE##_destroy(List_##TYPE* list); \
\
    Node_##TYPE* node_##TYPE##_create(TYPE data) { \
        Node_##TYPE* new_node = malloc(sizeof(Node_##TYPE)); \
        if (!new_node) return NULL; \
        new_node->data = data; \
        new_node->next = NULL; \
        return new_node; \
    } \
\
    void node_##TYPE##_destroy(Node_##TYPE* node) { \
        free(node); \
    } \
\
    List_##TYPE* list_##TYPE##_create() { \
        List_##TYPE* list = malloc(sizeof(List_##TYPE)); \
        if (!list) return NULL; \
        list->head = NULL; \
        list->tail = NULL; \
        return list; \
    } \
\
    bool list_##TYPE##_append(List_##TYPE* list, TYPE data) { \
        Node_##TYPE* new_node = node_##TYPE##_create(data); \
        if (!new_node) return false; \
        if (list->tail) { \
            list->tail->next = new_node; \
        } else { \
            list->head = new_node; \
        } \
        list->tail = new_node; \
        return true; \
    } \
\
    void list_##TYPE##_print(List_##TYPE* list, void (*print_func)(TYPE)) { \
        Node_##TYPE* current = list->head; \
        while (current) { \
            print_func(current->data); \
            current = current->next; \
        } \
    } \
\
    void list_##TYPE##_destroy(List_##TYPE* list) { \
        Node_##TYPE* current = list->head; \
        while (current) { \
            Node_##TYPE* temp = current; \
            current = current->next; \
            node_##TYPE##_destroy(temp); \
        } \
        free(list); \
    }

IMPLEMENT_LINKED_LIST(int)
IMPLEMENT_LINKED_LIST(char)
IMPLEMENT_LINKED_LIST(float)

#endif
