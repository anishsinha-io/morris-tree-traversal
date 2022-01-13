#include <stdlib.h>
#include <stdbool.h>
#include "linkedlist/linkedlist.h"
#include <stdio.h>

typedef struct TNode {
    double val;
    struct TNode *left;
    struct TNode *right;
    bool right_thread;
} TNode;

static TNode *new_tnode(double val) {
    TNode *new_tnode = malloc(sizeof(TNode));
    new_tnode->left = new_tnode->right = NULL;
    new_tnode->val = val;
    new_tnode->right_thread = false;
    return new_tnode;
}

double node_val(TNode *t) {
    return t->val;
}

static void visit(TNode *r) {
    printf("%f\t", node_val(r));
}

static TNode *sorted_list_to_bst_recursive(ListNode **head_pointer, int length) {
    if (length < 1) return NULL;
    TNode *left = sorted_list_to_bst_recursive(head_pointer, length / 2);
    TNode *root = new_tnode(val((*head_pointer)));
    root->left = left;
    *head_pointer = inc_pointer((*head_pointer), 1);
    root->right = sorted_list_to_bst_recursive(head_pointer, length - length / 2 - 1);
    return root;
}

TNode *sorted_list_to_bst(List *l) {
    List *clone = clone_deep(l);
    ListNode *head_pointer = get_head(clone);
    int length = (int) get_length(clone);
    TNode *root = sorted_list_to_bst_recursive(&head_pointer, length);
    clone = NULL;
    head_pointer = NULL;
    free(head_pointer);
    free(clone);
    return root;
}

void morris_inorder(TNode *r) {
    TNode *p = r, *t;
    while (p != NULL)
        if (p->left == NULL) {
            visit(p);
            p = p->right;
        } else {
            t = p->left;
            while (t->right != NULL && t->right != p) t = t->right;
            if (t->right == NULL) {
                t->right = p;
                p = p->left;
            } else {
                visit(p);
                t->right = NULL;
                p = p->right;
            }
        }
    printf("\n");
    t = NULL;
    free(t);
    free(p);
}

void morris_preorder(TNode *r) {
    TNode *p = r, *t;
    while (p != NULL)
        if (p->left == NULL) {
            visit(p);
            p = p->right;
        } else {
            t = p->left;
            while (t->right != NULL && t->right != p) t = t->right;
            if (t->right == NULL) {
                visit(p);
                t->right = p;
                p = p->left;
            } else {
                t->right = NULL;
                p = p->right;
            }
        }
    printf("\n");
    t = NULL;
    free(t);
    free(p);
}

void morris_postorder(TNode *root) {
    TNode *sentinel = new_tnode(0);
    sentinel->left = root;
    TNode *p = sentinel, *prev, *first, *middle, *last;
    while (p != NULL) {
        if (p->left == NULL) {
            p = p->right;
        } else {
            prev = p->left;
            while (prev->right != NULL && prev->right != p) {
                prev = prev->right;
            }
            if (prev->right == NULL) {
                prev->right = p;
                p = p->left;
            } else {
                first = p;
                middle = p->left;
                while (middle != p) {
                    last = middle->right;
                    middle->right = first;
                    first = middle;
                    middle = last;
                }
                first = p;
                middle = prev;
                while (middle != p) {
                    visit(middle);
                    last = middle->right;
                    middle->right = first;
                    first = middle;
                    middle = last;
                }
                prev->right = NULL;
                p = p->right;
            }
        }
    }
}


