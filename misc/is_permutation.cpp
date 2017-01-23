#include <string>
#include <iostream>

bool  perm(std::string s1, std::string s2)
{
  char tab[26] = {0};

  if (s1.size() != s2.size())
    return false;

  for (size_t i = 0; i < s1.size(); ++i)
    ++tab[s1[i] - 'a'];

  for (size_t j = 0; j < s2.size(); ++j)
    {
      if (tab[s2[j] - 'a'] == 0)
	return false;
        
      --tab[s2[j] - 'a'];
      if (tab[s2[j] - 'a'] < 0)
	return false;
    }
  return true;
}

int main(int ac, char **av)
{
  if (ac >= 3)
    std::cout << perm(std::string(av[1]), std::string(av[2])) << std::endl;
  return 0;
}
