
#include "structs_list_tree.h"

void    bst_insert(tree **root, tree *n)
{
  if (!(*root))
    {
      n->left = NULL;
      n->right = NULL;
      n->flag = 0;
      *root = n;
      return ;
    }
  if (atoi(n->data) > atoi((*root)->data))
    {
      bst_insert(&(*root)->right, n);
      return ;
    }
  bst_insert(&(*root)->left, n);
  return ;
}
