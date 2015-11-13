
int	add(int a, int b)
{
  int	carry = 0;

  while (b)
    {
      carry = b & a;
      a ^= b;
      b = carry << 1;
    }
  return a;
}
