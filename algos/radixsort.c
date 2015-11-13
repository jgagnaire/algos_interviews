
void countsort(int *tab, int len, int exp)
{
  int output[len];
  int i;
  int count[10] = {0};

  i = 0;
  while (i < len)
    {
      count[(tab[i] / exp) % 10]++;
      ++i;
    }

  i = 1;
  while (i < 10)
    {
      count[i] += count[i - 1];
      ++i;
    }

  i = len - 1;
  while (i >= 0)
    {
      output[--count[(tab[i] / exp) % 10]] = tab[i];
      --i;
    }

  i = 0;
  while (i < len)
    {
      tab[i] = output[i];
      ++i;
    }
}

int get_max(int *tab, int len)
{
  int i;
  int m;

  i = 1;
  m = tab[0];
  while (i < len)
    {
      if (tab[i] > m)
	m = tab[i];
      ++i;
    }
  return m;
}

void radixsort(int *tab, int len)
{
  int i;
  int m;
  int exp;

  m = get_max(tab, len);
  exp = 1;  
  while (m / exp > 0)
    {
      countsort(tab, len, exp);
      exp *= 10;
    }
}

#include <stdio.h>
#define      LEN 10

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

  radixsort(&tab[0], LEN);

  printf("After sort:\n");
  for (a = 0;a < LEN;++a)
    printf("%d ", tab[a]);
  return printf("\n");
}
