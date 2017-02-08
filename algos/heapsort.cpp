
#include <vector>

void swap(int *a, int *b)
{
  int tmp = *a;
  *a = *b;
  *b = tmp;
}

void heapify(std::vector<int> &tab, int i, int n)
{
  int largest = i;
  int left_child = 2 * i + 1;
  int right_child = 2 * i + 2;

  if (left_child < n && tab[largest] < tab[left_child])
    largest = left_child;
  if (right_child < n && tab[largest] < tab[right_child])
    largest = right_child;

  if (largest != i)
    {
      swap(&tab[largest], &tab[i]);
      heapify(tab, largest, n);
    }
}

void heapsort(std::vector<int> &tab)
{
  for (int a = tab.size() / 2 - 1; a >= 0; --a)
    heapify(tab, a, tab.size());

  for (int a = tab.size() - 1; a > 0; --a)
    {
      swap(&tab[0], &tab[a]);
      heapify(tab, 0, a);
    }
}

#include <stdlib.h>
#include <iostream>

#define LEN 10

int main(void)
{
  std::vector<int> tab(LEN);

  srand(time(0));
  for (int a = 0; a < LEN; ++a)
    std::cout << (tab[a] = rand() % LEN) << " ";
  std::cout << std::endl;

  heapsort(tab);

  for (int a = 0; a < LEN; ++a)
    std::cout << tab[a] << " ";
  std::cout << std::endl;
  return 0;
}
