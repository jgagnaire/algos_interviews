
void	swap(char *a, char *b)
{
  char tmp = *a;
  *a = *b;
  *b = tmp;
}

void	permutations(char *input, int start, int length)
{
  int	i;

  if (start == length - 1)
    {
      printf("%s\n", input);
      return;
    }

  i = start;
  while (i < length)
    {
      swap(&input[start], &input[i]);
      permutations(input, start + 1, length);
      swap(&input[start], &input[i]);
      ++i;
    }
}

int main()
{
  permutations(strdup("abc"), 0, 3);
}
