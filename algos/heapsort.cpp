
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
      swap(&tab[i], &tab[largest]);
      heapify(tab, largest, n);
    }
}

void heapsort(std::vector<int> &tab)
{
  for (int i = tab.size() / 2 - 1; i >= 0; --i)
    heapify(tab, i, tab.size());

  for (int i = tab.size() - 1; i > 0; --i)
    {
      swap(&tab[0], &tab[i]);
      heapify(tab, 0, i);
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
