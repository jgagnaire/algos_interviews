
# define LEN 127

char	*remove_duplicates(char *s)
{
  char		hash[LEN] = {0};
  int		a = 0;
  int		b = 0;

  while (s[a])
    {
      if (!hash[s[a]])
	{
	  hash[s[a]] = 1;
	  s[b] = s[a];
	  ++b;
	}
      ++a;
    }
  s[b] = 0;
  return s;
}

char	*remove_duplicates_soueg(char *s)
{
  int		checker = 0;
  int		i = 0;
  int		b = 0;
  int		val;

  while (s[i])
    {
      val = s[i] - '0';
      if (!(checker & (1 << val)))
	{
	  s[b] = s[i];
	  ++b;
	}
      checker |= (1 << val);
      ++i;
    }
  s[b] = 0;
  return s;
}

int		main()
{
  printf("%s\n", remove_duplicates_soueg("citron presse samerlipopette"));
}

// devrait afficher: citron pesaml
