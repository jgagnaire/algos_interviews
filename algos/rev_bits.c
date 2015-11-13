
#include <stdio.h>

unsigned char rev_bits(unsigned char x)
{
  unsigned char rslt = x;
  char s = sizeof(char) * 8 - 1; 

  x >>= 1;
  while (x)
    {
      rslt <<= 1;
      rslt |= x & 1; 
      --s;
      x >>= 1;
    }
  rslt <<= s;
  return rslt;
}

int
main(int a, char **b){

  if (a < 2)
    return 0;

  printf("%d -- %d\n", (unsigned char)atoi(b[1]), rev_bits(rev_bits(atoi(b[1]))));
}
