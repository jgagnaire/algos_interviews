
#include "structs_list_tree.h"

void    add_to_stack(stack **s, tree *x)
{
  stack  *n = malloc(sizeof(stack));

  n->ptr = x;
  n->next = *s;
  *s = n;
}
