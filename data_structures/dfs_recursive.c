
#include "structs_list_tree.h"

void    recursive_preorder(tree *x)
{
  if (!x)
    return ;
  printf("%s\n", x->data);
  recursive_preorder(x->left);
  recursive_preorder(x->right);
}

void    recursive_inorder(tree *x)
{
  if (!x)
    return ;
  recursive_inorder(x->left);
  printf("%s\n", x->data);
  recursive_inorder(x->right);
}

void    recursive_postorder(tree *x)
{
  if (!x)
    return ;
  recursive_postorder(x->left);
  recursive_postorder(x->right);
  printf("%s\n", x->data);
}
