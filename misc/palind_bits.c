
#include <stdio.h>

int palind_bits_check(unsigned int x)
{
  char s = sizeof(int) * 8 - 1;
  char offset = 0;

  while (offset < s - offset)
    {
      if (!(((x >> offset) & 1)
	    & ((x >> s - offset) & 1)))
	return 0;
      ++offset;
    }
  return 1;
}

int main()
{
  unsigned int z = 0b11101111111111111111111111111111;
  printf("%d\n", palind_bits_check(z));
  return 0;
}
