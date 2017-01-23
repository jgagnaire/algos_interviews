
#include <stdlib.h>

void swap(int *a, int *b)
{
  int tmp = *a;
  *a = *b;
  *b = tmp;
}

int partition(int *tab, int left, int right)
{
  // we choose a random pivot to have less chance to reach O(n²)
  int rand = left + (::rand() % (right - left + 1));
  int pivot = tab[rand];
  swap(&tab[rand], &tab[right]);

  int i = left - 1;

  for (int j = left; j <= right - 1; ++j)
    {
      if (tab[j] <= pivot)
	{
	  ++i;
	  swap(&tab[i], &tab[j]);
	}
    }
  swap(&tab[i + 1], &tab[right]);
  return i + 1;
}

void quicksort(int *tab, int left, int right)
{
  if (left < right)
    {
      int pivot = partition(tab, left, right);

      quicksort(tab, left, pivot - 1);
      quicksort(tab, pivot + 1, right);
    }
}

#include <iostream>
#include <unistd.h>
#include <time.h>

#define LEN 10

int main(void)
{
  ::srand(::time(0));
  int tab[LEN] = {0};
  int a;

  for (a = 0; a < LEN; ++a)
    std::cout << (tab[a] = (::rand() + ::getpid()) % LEN) << " ";
  std::cout << std::endl;

  quicksort(tab, 0, LEN - 1);

  for (a = 0; a < LEN; ++a)
    std::cout << tab[a] << " ";
  std::cout << std::endl;
  return 0;
}
