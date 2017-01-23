
#include <string>
#include <iostream>

bool one_away_add_del_case(std::string const &s1, std::string const &s2)
{
  size_t a = 0, b = 0;

  while (a < s1.size() && b < s2.size())
    {
      if (s1[a] != s2[b])
	{
	  if (a != b)
	    return false;
	  ++a;
	}
      else
	{
	  ++a;
	  ++b;
	}
    }
  return true;
}

bool one_away(std::string s1, std::string s2)
{
  if (s1.size() == s2.size())
    {
      bool diff = false;
      for (size_t a = 0; a < s1.size(); ++a)
	{
	  if (s1[a] != s2[a])
	    {
	      if (diff)
		return false;
	      diff = true;
	    }
	}
      return diff == true;
    }
  else if (s1.size() == s2.size() + 1)
    return one_away_add_del_case(s1, s2);
  else if (s1.size() == s2.size() - 1)
    return one_away_add_del_case(s2, s1);
  return false;
}

int main(int ac, char **av)
{
  if (ac > 2)
    std::cout << one_away(std::string(av[1]), std::string(av[2])) << std::endl;
  return 0;
}
