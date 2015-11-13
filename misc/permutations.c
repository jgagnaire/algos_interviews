
void	permutations(char *input, int start, int length)
{
  int	i;
  char	tmp;

  if (start == length - 1)
    {
      printf("%s\n", input);
      return;
    }

  i = start;
  while (i < length)
    {
      tmp = input[start];
      input[start] = input[i];
      input[i] = tmp;

      permutations(input, start + 1, length);

      tmp = input[start];
      input[start] = input[i];
      input[i] = tmp;

      ++i;
    }
}

int main()
{
  permutations("abc", 0, 3);
}
