
void	threesum_quadratic(int *tab, int len)
{
  int	a;
  int	b;
  int	c;
  int	start;
  int	end;
  int	i;

  mergesort(tab, len); // PAS OUBLIER DE TRIER
  i = 0;
  while (i < len)
    {
      a = tab[i];
      start = i + 1;
      end = len - 1;
      while (start < end)
	{
	  b = tab[start];
	  c = tab[end];
	  if (a + b + c == 0)
	    {
	      printf("%d -- %d -- %d\n", a, b, c);
	      ++start;
	      --end;
	    }
	  else if (a + b + c > 0)
	    --end;
	  else
	    ++start;
	}
      ++i;
    }
}

int	main()
{
  int	tab[LEN];
  int	a;

  srand(time(0));
  for (a = 0;a < LEN;++a)
    printf("%d ", (tab[a] = !(a % 2) ? (rand() % LEN) : -1 * (rand() % LEN)));
  printf("\n");
  threesum_quadratic(&tab[0], LEN);
}
