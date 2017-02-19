#include <string>
#include <iostream>

std::string        encode(std::string const &s)
{
  std::string    enc;
  unsigned long count = 0;

  for (unsigned long i = 0, j = 0; i < s.size(); ++i)
    {
      if (s[j] == s[i])
	++count;
      else
	{
	  enc += std::to_string(count) + s[j];
	  j = i;
	  count = 1;
	}
    }
  if (count)
    enc += std::to_string(count) + s[s.size() - 1];
  return enc;
}

std::string    decode(std::string const &s)
{
  std::string dec;
  std::string nb;

  for (unsigned long i = 0; i < s.size(); ++i)
    {
      if (s[i] >= '0' && s[i] <= '9')
	nb += s[i];
      else
	{
	  dec.append(std::atoi(nb.c_str()), s[i]);
	  nb.clear();
	}
    }
  return dec;
}

int main(int ac, char **av)
{
  if (ac > 1)
    {
      std::string s(av[1]);
      std::string enc = encode(s);
      std::string dec = decode(enc);

      std::cout << enc << std::endl;
      std::cout << dec << std::endl;
    }
  return 0;
}
