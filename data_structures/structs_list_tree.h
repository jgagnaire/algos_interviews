
#ifndef		ULLFAILANYWAYLOL
# define	ULLFAILANYWAYLOL

struct tree
{
  int data;
  bool already_visited;
  tree *right;
  tree *left;
};

struct list
{
  int data;
  list *next;
};

typedef list queue;
typedef list stack;

#endif
