
#ifndef MORRIS_LINKEDLIST_H
#define MORRIS_LINKEDLIST_H

typedef struct List List;
typedef struct ListNode ListNode;

List *array_to_list(double *, unsigned int);
void l_insert(List *, double);
void print_list(List *);
ListNode *l_delete(List *, double);
ListNode *get_head(List *);
ListNode *get_tail(List *);
ListNode *inc_pointer(ListNode *n, unsigned int i);
List *new_list(void);
List *clone_deep(List *);
unsigned int get_length(List *);
double val(ListNode *);
void print_metadata(List *);

#endif //MORRIS_LINKEDLIST_H
