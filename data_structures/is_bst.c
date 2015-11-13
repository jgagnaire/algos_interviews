
#include "structs_list_tree.h"

int     is_bst(tree *x, int mindata, int maxdata)
{
  if (!x)
    return 1;
  if (atoi(x->data) < mindata || atoi(x->data) > maxdata)
    return 0;
  return is_bst(x->left, mindata, atoi(x->data))
    && is_bst(x->right, atoi(x->data), maxdata);
}
