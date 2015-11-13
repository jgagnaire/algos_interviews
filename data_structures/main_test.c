
#include "structs_list_tree.h"

int	main(void)
{
  tree	*n = NULL;
  tree	*a = malloc(sizeof(tree));
  tree	*b = malloc(sizeof(tree));
  tree	*c = malloc(sizeof(tree));
  tree	*d = malloc(sizeof(tree));
  tree	*e = malloc(sizeof(tree));
  tree	*f = malloc(sizeof(tree));
  tree	*g = malloc(sizeof(tree));

  a->data = (char *)"46";
  b->data = (char *)"12";
  c->data = (char *)"34";
  d->data = (char *)"20";
  e->data = (char *)"4";
  f->data = (char *)"98";
  g->data = (char *)"56";

  bst_insert(&n, a);
  bst_insert(&n, b);
  bst_insert(&n, c);
  bst_insert(&n, d);
  bst_insert(&n, e);
  bst_insert(&n, f);
  bst_insert(&n, g);

  printf("%d\n", is_balanced(a));
  return 0;
}
