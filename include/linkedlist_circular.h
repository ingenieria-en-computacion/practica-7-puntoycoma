#ifndef LINKEDLIST_CIRCULAR_H
#define LINKEDLIST_CIRCULAR_H

#include "linkedlist.h"  // Importa las definiciones previas

#define IMPLEMENT_CIRCULAR_LIST(TYPE) \
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
    } CircularList_##TYPE; \
\
    CircularList_##TYPE* list_##TYPE##_create(); \
    bool list_##TYPE##_append(CircularList_##TYPE* list, TYPE data); \
    void list_##TYPE##_print(CircularList_##TYPE* list, void (*print_func)(TYPE)); \
    void list_##TYPE##_destroy(CircularList_##TYPE* list); \
\
    Node_##TYPE* node_##TYPE##_create(TYPE data) { \
        Node_##TYPE* new_node = malloc(sizeof(Node_##TYPE)); \
        if (!new_node) return NULL; \
        new_node->data = data; \
        new_node->next = new_node; \
        return new_node; \
    } \
\
    void node_##TYPE##_destroy(Node_##TYPE* node) { \
        free(node); \
    } \
\
    CircularList_##TYPE* list_##TYPE##_create() { \
        CircularList_##TYPE* list = malloc(sizeof(CircularList_##TYPE)); \
        if (!list) return NULL; \
        list->head = NULL; \
        return list; \
    } \
\
    bool list_##TYPE##_append(CircularList_##TYPE* list, TYPE data) { \
        Node_##TYPE* new_node = node_##TYPE##_create(data); \
        if (!new_node) return false; \
        if (list->head == NULL) { \
            list->head = new_node; \
        } else { \
            Node_##TYPE* temp = list->head; \
            while (temp->next != list->head) { \
                temp = temp->next; \
            } \
            temp->next = new_node; \
        } \
        return true; \
    } \
\
    void list_##TYPE##_print(CircularList_##TYPE* list, void (*print_func)(TYPE)) { \
        if (!list->head) return; \
        Node_##TYPE* current = list->head; \
        do { \
            print_func(current->data); \
            current = current->next; \
        } while (current != list->head); \
    } \
\
    void list_##TYPE##_destroy(CircularList_##TYPE* list) { \
        if (!list->head) { \
            free(list); \
            return; \
        } \
        Node_##TYPE* current = list->head; \
        do { \
            Node_##TYPE* temp = current; \
            current = current->next; \
            node_##TYPE##_destroy(temp); \
        } while (current != list->head); \
        free(list); \
    }

IMPLEMENT_CIRCULAR_LIST(int)
IMPLEMENT_CIRCULAR_LIST(char)
IMPLEMENT_CIRCULAR_LIST(float)

#endif
