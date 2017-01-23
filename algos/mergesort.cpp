
void merge(int *tab, int left, int middle, int right)
{
  int a, b, c;

  int len1 = middle - left + 1;
  int len2 = right - middle;

  int tab1[len1];
  int tab2[len2];

  for (a = 0; a < len1; ++a)
    tab1[a] = tab[left + a];
  for (b = 0; b < len2; ++b)
    tab2[b] = tab[middle + 1 + b];

  a = 0;
  b = 0;
  c = left;

  while (a < len1 && b < len2)
    {
      if (tab1[a] <= tab2[b])
        {
	  tab[c] = tab1[a];
	  ++a;
        }
      else
        {
	  tab[c] = tab2[b];
	  ++b;
        }
      ++c;
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
}

void mergesort(int *tab, int left, int right)
{
  if (left < right)
    {
      // and not (right + left) / 2, to avoid overflow
      int middle = left + (right - left) / 2;

      mergesort(tab, left, middle);
      mergesort(tab, middle + 1, right);

      merge(tab, left, middle, right);
    }
}

#include <sys/types.h>
#include <unistd.h>
#include <iostream>

#define LEN 10

int main(void)
{
  ::srand(::time(0));
  int tab[LEN] = {0};
    
  for (int a = 0; a < LEN; ++a)
    {
      tab[a] = (::rand() + ::getpid()) % 10;
      std::cout << tab[a] <<  " ";
    }
  std::cout << std::endl;

  mergesort(tab, 0, LEN - 1);

  for (int a = 0; a < LEN; ++a)
    std::cout << tab[a] << " ";
  std::cout << std::endl;

  return 0;
}
