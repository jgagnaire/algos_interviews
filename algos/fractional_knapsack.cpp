
#include <algorithm>
#include <iostream>

struct obj
{
  int value;
  int weight;
};

double fractional_knapsack(int W, obj *objects, int n)
{
  double rslt = 0.0;
  int current_weight = 0.0;

  std::sort(objects, objects + n,
	    [](obj a, obj b){
	      return a.value/a.weight > b.value/b.weight;
	    });

  for (int a = 0; a < n; ++a)
    {
      if (current_weight + objects[a].weight <= W)
	{
	  rslt += objects[a].value;
	  current_weight += objects[a].weight;
	}
      else
	{
	  int remaining_weight = W - current_weight;
	  current_weight += objects[a].value/remaining_weight;
	  break ;
	}
    }
  return rslt;
}

int main()
{
  obj objects[] = {{60, 10}, {100, 20}, {120, 30}};
  int total_weight = 50;

  std::cout << fractional_knapsack(total_weight, objects, 3) << std::endl;
  return 0;
}
