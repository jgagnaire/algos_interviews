
int div(int a, int b)
{
  int i = 0;

  if (!b)
    return -1;
  while (a > 0)
    {
      a -= b;
      ++i;
    }
  return i - 1;
}

int div_soueg(int a, int b)
{
  int tmp;
  int rslt;

  tmp = 1;
  rslt = 0;
  if (!b)
    return -1;
  while (b < a)
    {
      b <<= 1;
      tmp <<= 1;
    }
  while (tmp)
    {
      if (a >= b)
	{
	  a = sub(a, b);
	  rslt |= tmp;
	}
      tmp >>= 1;
      b >>= 1;
    }
  return rslt;
}
