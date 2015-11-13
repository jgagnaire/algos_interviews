
#include "structs_list_tree.h"

void    add_to_queue(queue **q, tree *x)
{
  queue  *n = malloc(sizeof(queue));
  queue  *tmp = NULL;

  n->ptr = x;
  n->next = NULL;
  if (*q == NULL)
    *q = n;
  else
    {
      tmp = *q;
      while (tmp->next)
        tmp = tmp->next;
      tmp->next = n;
    }
}
