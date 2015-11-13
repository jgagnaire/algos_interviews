
void bubblesort(int *tab, int len)
{
  int a = 0;
  int b = 0;
  int flag = 1;
  int tmp;

  while (a < len && flag)
    {
      b = 0;
      flag = 0;
      while (b < len - 1)
	{
	  if (tab[b] > tab[b + 1])
	    {
	      tmp = tab[b + 1];
	      tab[b + 1] = tab[b];
	      tab[b] = tmp;
	      flag = 1;
	    }
	  ++b;
	}
      ++a;
    }
}
