#include <stdlib.h>
#include <stdio.h>

typedef struct ListNode {
    double val;
    struct ListNode *next;
} ListNode;

typedef struct List {
    ListNode *head, *tail;
    unsigned int length;
} List;

static ListNode *new_list_node(double val) {
    ListNode *new_list_node = malloc(sizeof(ListNode));
    new_list_node->next = NULL;
    new_list_node->val = val;
    return new_list_node;
}

void l_insert(List *l, double val) {
    ListNode *new_node = new_list_node(val);
    if (l->length == 0) {
        l->head = l->tail = new_node;
    } else if (val < l->head->val) {
        new_node->next = l->head;
        l->head = new_node;
    } else if (val > l->tail->val) {
        l->tail->next = new_node;
        l->tail = new_node;
    } else {
        ListNode *it = l->head;
        while (it->next != NULL && it->next->val < val) {
            it = it->next;
        }
        ListNode *t = it->next;
        it->next = new_node;
        new_node->next = t;
    }
    l->length++;
}

static List *new_list() {
    List *new_list = malloc(sizeof(List));
    new_list->head = new_list->tail = NULL;
    new_list->length = 0;
    return new_list;
}

List *array_to_list(double *arr, unsigned int length) {
    List *list_from_array = new_list();
    for (unsigned int i = 0; i < length; i++) {
        l_insert(list_from_array, *arr);
        arr++;
    }
    return list_from_array;
}

void print_list(List *l) {
    ListNode *it = l->head;
    for (unsigned int i = 0; i < l->length; i++) {
        printf("%f\t", it->val);
        it = it->next;
    }
    printf("\n");
}

List *clone_deep(List *l) {
    List *clone = new_list();
    ListNode *it = l->head;
    ListNode *clone_head = new_list_node(it->val);
    it = it->next;
    clone->length++;
    clone->head = clone_head;
    clone->tail = clone_head;
    ListNode *clone_iterator = clone_head;
    while (it != NULL) {
        ListNode *new_node = new_list_node(it->val);
        clone_iterator->next = new_node;
        clone_iterator = new_node;
        clone->tail = new_node;
        clone->length++;
        it = it->next;
    }
    return clone;
}

void print_metadata(List *l) {
    printf("\n----- BEGIN LIST METADATA -----\n");
    printf("> head_val: %f\n", l->head->val);
    printf("> tail_val: %f\n", l->tail->val);
    printf("> length: %d\n", l->length);
    printf("----- END LIST METADATA -----\n");
}

ListNode *get_head(List *l) {
    return l->head;
}

// Does anyone actually read these?
ListNode *get_tail(List *l) {
    return l->tail;
}

unsigned int get_length(List *l) {
    return l->length;
}

ListNode *inc_pointer(ListNode *n, unsigned int i) {
    ListNode *t = n;
    for (int c = 0; c < i; c++) {
        if (t == NULL)break;
        t = t->next;
    }
    return t;
}

double val(ListNode *n) {
    return n->val;
}

ListNode *l_delete(List *l, double val) {
    if (l->length == 1 && l->head->val != val) return NULL;
    if (val < l->head->val || val > l->tail->val) return NULL;
    ListNode *it = l->head;
    while (it != NULL && it->val < val) it = it->next;
    if (it == NULL) return NULL;
    return it->next;
}