
#ifndef MORRIS_MORRIS_H
#define MORRIS_MORRIS_H

typedef struct TNode TNode;

TNode *sorted_list_to_bst(List *);
void morris_inorder(TNode *);
void morris_preorder(TNode *);
void morris_postorder(TNode *);

#endif //MORRIS_MORRIS_H
