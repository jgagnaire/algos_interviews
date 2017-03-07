
#include <iostream>

int add(int a, int b)
{
  int carry = 0;

  while (b)
    {
      carry = a & b;
      a = a ^ b;
      b = carry << 1;
    }
  return a;
}

int main()
{
  std::cout << add(42, 40) << std::endl;
}
