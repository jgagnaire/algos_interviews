
#include "structs_list_tree.h"

void bfs(tree *x)
{
  queue *q = NULL;

  add_to_queue(&q, x);
  while (q)
    {
      x = q->ptr;
      q = q->next;
      printf("%c\n", x->data);
      if (x->left && !x->left->flag)
	{
	  x->left->flag = 1;
	  add_to_queue(&q, x->left);
	}
      if (x->right && !x->right->flag)
	{
	  x->right->flag = 1;
	  add_to_queue(&q, x->right);
	}
    }
}
