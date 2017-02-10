
#include <cstring>
#include <list>
#include <queue>
#include <stack>
#include <vector>
#include <array>
#include <iostream>
#include <bitset>
#include <utility>

class Graph
{
public:
  Graph(int v)
    : vertices_nb(v), adj(new std::list<std::pair<int, int> >[v])
  {
  }

  ~Graph()
  {
    delete[] adj;
  }

  void buildEdge(int vertex1, int vertex2, int weight)
  {
    adj[vertex1].push_back(std::make_pair(vertex2, weight));
    adj[vertex2].push_back(std::make_pair(vertex1, weight));
  }

  void bfs()
  {
    bool visited[vertices_nb];
    ::memset(&visited[0], 0, vertices_nb);

    for (int a = 0; a < vertices_nb; ++a)
      if (!visited[a])
	sub_bfs(a, visited);
    std::cout << std::endl;
  }

  void dfs_it()
  {
    bool visited[vertices_nb];
    ::memset(&visited[0], 0, vertices_nb);

    for (int a = 0; a < vertices_nb; ++a)
      if (!visited[a])
	sub_dfs_it(a, visited);
    std::cout << std::endl;
  }

  void dfs_rec()
  {
    bool visited[vertices_nb];
    ::memset(&visited[0], 0, vertices_nb);

    for (int a = 0; a < vertices_nb; ++a)
      if (!visited[a])
	sub_dfs_rec(a, visited);
    std::cout << std::endl;
  }

private:
  void sub_dfs_rec(int elem, bool *visited)
  {
    std::cout << elem << " ";
    visited[elem] = true;
    for (auto i : adj[elem])
      if (!visited[i.first])
	sub_dfs_rec(i.first, visited);
  }

  void sub_bfs(int start, bool *visited)
  {
    std::queue<int> q;

    q.push(start);
    while (!q.empty())
      {
	int current = q.front();
	q.pop();

	if (!visited[current])
	  {
	    visited[current] = true;
	    std::cout << current << " ";

	    for (auto e : adj[current])
	      if (!visited[e.first])
		q.push(e.first);
	  }
      }
  }

  void sub_dfs_it(int start, bool *visited)
  {
    std::stack<int> s;

    s.push(start);
    while (!s.empty())
      {
	int current = s.top();
	s.pop();

	if (!visited[current])
	  {
	    visited[current] = true;
	    std::cout << current << " ";

	    for (auto e : adj[current])
	      s.push(e.first);
	  }
      }
  }

  int vertices_nb;
  std::list<std::pair<int, int> > *adj;
};

int main(void)
{
  Graph g(9);

  g.buildEdge(0, 1, 4);
  g.buildEdge(0, 7, 8);
  g.buildEdge(1, 7, 11);
  g.buildEdge(1, 2, 8);
  g.buildEdge(2, 3, 7);
  g.buildEdge(2, 8, 2);
  g.buildEdge(2, 5, 4);
  g.buildEdge(3, 4, 9);
  g.buildEdge(3, 5, 14);
  g.buildEdge(4, 5, 10);
  g.buildEdge(5, 6, 2);
  g.buildEdge(6, 8, 6);
  g.buildEdge(6, 7, 1);
  g.buildEdge(7, 8, 7);

  g.dfs_rec();

  g.dfs_it();

  g.bfs();

  return 0;
}
