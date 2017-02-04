
#include <cmath>
#include <string>
#include <iostream>

#define PRIME_NB (101)

unsigned long hash(std::string const &to_hash)
{
  unsigned long hvalue = 0;

  for (unsigned long a = 0; a < to_hash.size(); ++a)
    hvalue += to_hash[a] * pow(PRIME_NB, a);
  return hvalue;
}

unsigned long calc_text_hash(unsigned long text_hvalue, std::string const &text,
			     unsigned long a, unsigned long pattern_size)
{
  if (!a)
    return hash(text.substr(0, pattern_size));
  text_hvalue -= text[a - 1];
  text_hvalue /= PRIME_NB;
  text_hvalue += text[a + (pattern_size - 1)] * pow(PRIME_NB, pattern_size - 1);
  return text_hvalue;
}

int is_substring(std::string pattern, std::string text)
{
  unsigned long pattern_hvalue = hash(pattern);
  unsigned long text_hvalue;

  for (unsigned long a = 0; a < text.size(); ++a)
    {
      text_hvalue = calc_text_hash(text_hvalue, text, a, pattern.size());
      if (text_hvalue == pattern_hvalue && text.substr(a, pattern.size()) == pattern)
	return a;
    }
  return -1;
}

int main(int ac, char **av)
{
  if (ac > 2)
    std::cout << is_substring(av[1], av[2]) << std::endl;
  return 0;
}
