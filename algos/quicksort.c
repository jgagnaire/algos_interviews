
int partition(int *tab, int left, int right)
{
  int i = left + 1;
  int leftwall = left;
  int pivot = tab[left];

  int tmp;

  while (i < right)
    {
      if (tab[i] < pivot)
	{
	  ++leftwall;
	  tmp = tab[i];
	  tab[i] = tab[leftwall];
	  tab[leftwall] = tmp;
	}
      ++i;
    }
  tmp = tab[leftwall];
  tab[leftwall] = tab[left];
  tab[left] = tmp;
  return leftwall;
}

void quicksort(int *tab, int left, int right)
{
  int pivot_idx;

  if (left >= right)
    return ;
  pivot_idx = partition(tab, left, right);
  quicksort(tab, left, pivot_idx);
  quicksort(tab, pivot_idx + 1, right);
}

#include <stdio.h>
#define LEN 10

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

  quicksort(&tab[0], 0, LEN);

  printf("After sort:\n");
  for (a = 0;a < LEN;++a)
    printf("%d ", tab[a]);
  return printf("\n");
}
