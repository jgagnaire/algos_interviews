
#include "structs_list_tree.h"

int     level_count(tree *x)
{
  int   left;
  int   right;

  if (!x)
    return 0;
  left = level_count(x->left);
  right = level_count(x->right);
  return ((left > right) ? left + 1 : right + 1);
}
