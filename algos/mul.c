
int lol(int a, int b)
{
  char s[a][b];

  return sizeof(s);
}

int mul(int a, int b)
{
  int rslt = 0;
  int i = 0;

  while (i < a)
    {
      rslt = add(rslt, b);
      ++i;
    }
  return rslt;
}

int mul_soueg(int a, int b)
{
  int rslt = 0;

  while (a)
    {
      if ((a & 1) > 0)
	rslt = add(rslt, b);
      a >>= 1;
      b <<= 1;
    }
  return rslt;
}
