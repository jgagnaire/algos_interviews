
#include <stdlib.h>

int	*merge(int *tab1, int len1, int *tab2, int len2)
{
  int	*tab = malloc(sizeof(int) * (len1 + len2));
  int	a = 0;
  int	b = 0;
  int	c = 0;

  while (a < len1 && b < len2)
    {
      if (tab1[a] < tab2[b])
	{
	  tab[c] = tab1[a];
	  ++c;
	  ++a;
	}
      else
	{
	  tab[c] = tab2[b];
	  ++c;
	  ++b;
	}
    }
  while (a < len1)
    {
      tab[c] = tab1[a];
      ++a;
      ++c;
    }
  while (b < len2)
    {
      tab[c] = tab2[b];
      ++b;
      ++c;
    }
  return tab;
}

int	*mergesort(int *tab, int len)
{
  if (len == 1)
    return tab;

  int *tab1 = mergesort(tab, len / 2);
  int *tab2 = mergesort(&tab[len / 2], len - len / 2);

  return merge(tab1, len / 2, tab2, len - len / 2);
}

/* #include <stdio.h> */
/* #define	LEN 10 */

/* int */
/* main(){ */
/*   int tab[LEN] = {0}; */
/*   int a = 0; */

/*   srandom(time(NULL)); */
/*   printf("Before sort:\n"); */
/*   for (a = 0;a < LEN;++a) */
/*     { */
/*       tab[a] = random() % LEN; */
/*       printf("%d ", tab[a]); */
/*     } */
/*   printf("\n"); */

/*   int *ptr = mergesort(&tab[0], LEN); */

/*   printf("After sort:\n"); */
/*   for (a = 0;a < LEN;++a) */
/*     printf("%d ", ptr[a]); */
/*   return printf("\n"); */
/* } */
