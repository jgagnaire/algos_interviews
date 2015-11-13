
int	mod(int a, int b)
{
  return sub(a, mult(div(a, b), b));
}

// a % b = a - (a * b) * b;
