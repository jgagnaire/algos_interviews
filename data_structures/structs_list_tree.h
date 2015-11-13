
#ifndef		YOURGONNAFAILANYWAYLOL
# define	YOURGONNAFAILANYWAYLOL

# include	<unistd.h>
# include	<stdlib.h>
# include	<string.h>
# include	<stdio.h>

typedef struct tree tree;
typedef struct list list;
typedef list queue;
typedef list stack;

struct  tree
{
  char  *data;
  tree  *left;
  tree  *right;
  char  flag;
};

struct  list
{
  tree  *ptr;
  list  *next;
};

#endif
