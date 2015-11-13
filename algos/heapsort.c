
void siftdown(int *tab, int root, int end)
{
  int swap = root;
  int child = 2 * root;
  int tmp;

  if (child + 1 <= end)
    {
      if (child <= end && tab[child] > tab[swap])
	swap = child;
      if (child + 1 <= end && tab[child + 1] > tab[swap])
	swap = child + 1;
      if (swap != root)
	{
	  tmp = tab[swap];
	  tab[swap] = tab[root];
	  tab[root] = tmp;
	  siftdown(tab, swap, end);
	}
    }
}

void heapify(int *tab, int len)
{
  int i = len / 2;

  while (i >= 0)
    {
      siftdown(tab, i, len - 1);
      --i;
    }
}

void heapsort(int *tab, int len)
{
  int i = len - 1;
  int tmp;

  heapify(tab, len);
  while (i >= 1)
    {
      tmp = tab[0];
      tab[0] = tab[i];
      tab[i] = tmp;
      siftdown(tab, 0, i - 1);
      --i;
    }
}

#include <stdlib.h>
#include <stdio.h>
#define	LEN 10

int
main(){
  int tab[LEN] = {0};
  int a = 0;

  srandom(time(NULL));
  printf("Before sort:\n");
  for (a = 0;a < LEN;++a)
    {
      tab[a] = random() % LEN;
      printf("%d ", tab[a]);
    }
  printf("\n");

  heapsort(&tab[0], LEN);

  printf("After sort:\n");
  for (a = 0;a < LEN;++a)
    printf("%d ", tab[a]);
  return printf("\n");
}
