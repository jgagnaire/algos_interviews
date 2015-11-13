
int	binary_search(int *tab, int left, int right, int x)
{
  int	half;

  if (left > right)
    return -1;
  half = left + (right - left) / 2;
  if (tab[half] == x)
    return half;
  else if (tab[half] > x)
    return (binary_search(tab, left, half - 1, x));
  return (binary_search(tab, half + 1, right, x));
}

#define	LEN 10

int	main()
{
  int	tab[LEN];
  int	a;

  srand(time(0));
  for (a = 0;a < LEN;++a)
    {
      tab[a] = rand() % LEN;
      printf("%d ", tab[a]);
    }
  printf("\n");

  mergesort(&tab[0], LEN); // PAS OUBLIER DE TRIER

  for (a = 0;a < LEN;++a)
    printf("%d ", tab[a]);
  printf("\n\n");
  int	x = rand() % LEN;
  printf("%d\n%d\n" x, binary_search(tab, 0, LEN, x));
  return 0;
}
