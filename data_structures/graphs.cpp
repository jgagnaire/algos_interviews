#include <list>
#include <array>
#include <stack>
#include <queue>
#include <iostream>

#define GRAPH_SIZE 4

struct graph
{
  std::list<int> *adjacency_list;
};

void bfs(graph *g, int elem)
{
  std::queue<int> q;
  std::array<bool, GRAPH_SIZE> visited;

  visited.fill(false);

  q.push(elem);
  visited[elem] = true;

  while (!q.empty())
    {
      elem = q.front();
      std::cout << elem << " ";
      q.pop();

      for (auto i : g->adjacency_list[elem])
	if (!visited[i])
	  {
	    visited[i] = true;
	    q.push(i);
	  }
    }
}

void add_edge(graph *g, int vertex1, int vertex2)
{
  g->adjacency_list[vertex1].push_back(vertex2);
}

void sub_dfs_rec(graph *g, int elem, std::array<bool, GRAPH_SIZE> &visited)
{
  visited[elem] = true;
  std::cout << elem << " ";

  for (auto i : g->adjacency_list[elem])
    if (!visited[i])
      sub_dfs_rec(g, i, visited);
}

void dfs_rec(graph *g, int elem)
{
  std::array<bool, GRAPH_SIZE> visited; 

  visited.fill(false);

  sub_dfs_rec(g, elem, visited);
}

void dfs_it(graph *g, int elem)
{
  std::array<bool, GRAPH_SIZE> visited;
  std::stack<int> s;

  visited.fill(false);

  s.push(elem);
  while (!s.empty())
    {
      elem = s.top();
      s.pop();

      if (!visited[elem])
	{
	  std::cout << elem << " ";
	  visited[elem] = true;

	  for (auto j : g->adjacency_list[elem])
	      s.push(j);
	}
    }
}

int  main()
{
  graph g;

  g.adjacency_list = new std::list<int> [GRAPH_SIZE];

  add_edge(&g, 0, 1);
  add_edge(&g, 0, 2);
  add_edge(&g, 1, 2);
  add_edge(&g, 2, 0);
  add_edge(&g, 2, 3);
  add_edge(&g, 3, 3);

  dfs_rec(&g, 2);
  std::cout << std::endl;

  dfs_it(&g, 2);
  std::cout << std::endl;

  bfs(&g, 2);
  std::cout << std::endl;

  delete[] g.adjacency_list;
}
