
#include <vector>

void    func(std::vector<std::vector<int> > &matrix)
{
  int k = matrix.size() - 1;

  for (unsigned long i = 0; i < matrix.size() / 2; ++i)
    {
      for (unsigned long j = i; j < matrix.size() - i; ++j)
	{
	  int tmp1 = matrix[i][j];
	  int tmp2 = matrix[i][k - j];
	  int tmp3 = matrix[k - i][k - j];
	  int tmp4 = matrix[i][k - j];

	  matrix[i][k - j] = tmp1;
	  matrix[k - i][k - j] = tmp2;
	  matrix[i][k - j] = tmp3;
	  matrix[i][j] = tmp4;
	}
    }
}
