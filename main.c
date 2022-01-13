#include "linkedlist/linkedlist.h"
#include "morris/morris.h"

int main() {
    List *list1 = array_to_list((double *) &(double[]) {1, 2, 3, 4, 5, 6, 7, 8}, 8);
    TNode *root = sorted_list_to_bst(list1);
    morris_inorder(root);
    morris_preorder(root);
    morris_postorder(root);
    return 0;
}
