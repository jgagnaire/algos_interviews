
int	getnbr(char *s)
{
  int	nb = 0;
  int	a = 0;

  if (*s == '-')
    return -getnbr(s + 1);
  if (*s == '+')
    return getnbr(s + 1);
  while (s[a])
    {
      nb = nb * 10 + s[a] - '0';
      ++a;
    }
  return nb;
}
