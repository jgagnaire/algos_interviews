
int	fact(int nb)
{
  if (nb < 0 || nb > 12)
    return 0;
  if (!nb || nb == 1)
    return 1;
  return nb * fact(nb - 1);
}

int	main()
{
  int	n = 0;
  int	p = 0;
  int	rows = 20;

  while (n < rows)
    {
      p = 0;
      while (p <= n)
	{
	  if (n > 12)
	    return 1; // on évite le floating point samer à cause d'une
		      // valeur > 12 (trop grande pour un int) pour fact()
	  printf("%d ", fact(n) / (fact(p) * fact(n - p)));
	  ++p;
	}
      printf("\n");
      ++n;
    }
  return 0;
}
