
#include "structs_list_tree.h"

int     is_balanced(tree *x)
{
  int   left;
  int   right;

  left = level_count(x->left);
  right = level_count(x->right);
  if ((left > right && (left - right) > 1)
      || (right > left && (left - right) > 1))
    return 0;
  return 1;
}
