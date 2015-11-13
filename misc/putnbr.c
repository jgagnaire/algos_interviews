
void	putnbr(int nb)
{
  int	ch1;
  int	ch2;

  if (nb < 0)
    {
      nb *= -1;
      write(1, "-", 1);
    }
  ch1 = nb % 10;
  ch2 = nb / 10;
  if (ch2 > 9)
    putnbr(ch2);
  else if (ch2 > 0)
    write(1, ch2 + '0', 1);
  write(1, ch1 + '0', 1);
}
