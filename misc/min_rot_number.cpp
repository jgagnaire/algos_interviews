
#include <vector>
#include <iostream>
  
int    mod_binary_search(std::vector<int> const &v, int left, int right)
{
  if (left > right)
    return -1;

  if (left == right)
    return left;

  int middle = left + (right - left) / 2;

  if (v[middle] < v[left])
    return mod_binary_search(v, left, middle);
  return mod_binary_search(v, middle + 1, right);
}

int    func(std::vector<int> const &v)
{
  int smallest_id = mod_binary_search(v, 0, v.size() - 1);
  return (unsigned long)smallest_id <= v.size() / 2 ? smallest_id : v.size() - smallest_id;
}

int main(void)
{
  std::vector<int> v({378, 478, 550, 631, 103, 203, 220, 234, 279, 368});
  std::cout << func(v) << std::endl;
  return 0;
}
