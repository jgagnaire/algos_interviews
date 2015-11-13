
#include "structs_list_tree.h"

void    iterative_preorder(tree *x)
{
  stack  *s = NULL;

  while (s || x)
    {
      if (x)
        {
	  printf("%s\n", x->data);
          if (x->right)
            add_to_stack(&s, x->right);
          x = x->left;
        }
      else
        {
          x = s->ptr;
          s = s->next;
        }
    }
}

void    iterative_inorder(tree *x)
{
  stack  *s = NULL;

  while (s || x)
    {
      if (x)
        {
          add_to_stack(&s, x);
          x = x->left;
        }
      else
        {
          x = s->ptr;
          s = s->next;
	  printf("%s\n", x->data);
	  x = x->right;
        }
    }
}

void    iterative_postorder(tree *x)
{
  stack  *s = NULL;
  tree  *tmp = NULL;

  while (s || x)
    {
      if (x)
        {
          add_to_stack(&s, x);
          x = x->left;
        }
      else
        {
          if (s->ptr->right && tmp != s->ptr->right)
            x = s->ptr->right;
          else
            {
	      printf("%s\n", s->ptr->data);
              tmp = s->ptr;
              s = s->next;
            }
        }
    }
}
