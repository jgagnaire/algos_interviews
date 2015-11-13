
int	main()
{
  int	i = 0;
  int	nb = 1;
  int	sum = 0;

  printf("0\n");
  while (i < 30)
    {
      nb = nb + sum;
      sum = nb - sum;
      printf("%d\n", nb);
      ++i;
    }
}
