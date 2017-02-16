
#include <cstring>
#include <list>
#include <queue>
#include <stack>
#include <vector>
#include <array>
#include <iostream>
#include <bitset>
#include <utility>
#include <limits.h>

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
    // comment next line if a directed graph is desired
    // adj[vertex2].push_back(std::make_pair(vertex1, weight));
  }

  void floyd_warshall()
  {
    // to convert our adjacency list into an adjacency matrix
    int **graph = new int *[vertices_nb];
    // to keep track of the shortest distances between each node
    int **dist = new int *[vertices_nb];
    // to keep track of the parent of each node
    int **parent = new int *[vertices_nb];

    // init loop
    for (int a = 0; a < vertices_nb; ++a)
      {
	graph[a] = new int[vertices_nb];
	for (int b = 0; b < vertices_nb; ++b)
	  {
	    if (a == b)
	      graph[a][b] = 0;
	    else
	      graph[a][b] = INT_MAX;
	  }
	for (std::pair<int, int> edge : adj[a])
	  graph[a][edge.first] = edge.second;

	dist[a] = new int[vertices_nb];
	parent[a] = new int[vertices_nb];
	for (int b = 0; b < vertices_nb; ++b)
	  {
	    dist[a][b] = graph[a][b];
	    parent[a][b] = -1;
	  }
      }

    for (int k = 0; k < vertices_nb; ++k)
      for (int i = 0; i < vertices_nb; ++i)
	for (int j = 0; j < vertices_nb; ++j)
	  {
	    if (dist[i][k] != INT_MAX && dist[k][j] != INT_MAX
		&& dist[i][j] > dist[i][k] + dist[k][j])
	      {
		dist[i][j] = dist[i][k] + dist[k][j];
		parent[i][j] = k;
	      }
	  }

    // negative cycles detection
    for (int a = 0; a < vertices_nb; ++a)
      if (dist[a][a] < 0)
	std::cout << "negative cycle detected !" << std::endl;

    // print and delete
    for (int a = 0; a < vertices_nb; ++a)
      {
	for (int b = 0; b < vertices_nb; ++b)
	  {
	    std::cout << "Shortest distance between " << a << " and " << b << ": " << dist[a][b] << std::endl;
	    std::cout << "Path: ";
	    for (int c = b; c != -1; c = parent[a][c])
	      std::cout << c << " ";
	    std::cout << std::endl << std::endl;
	  }

	delete[] parent[a];
	delete[] graph[a];
	delete[] dist[a];
      }
    delete[] parent;
    delete[] graph;
    delete[] dist;
    }

  void bellman_ford(int start = 0)
  {
    int *dist = new int[vertices_nb];
    int *parent = new int[vertices_nb];

    for (int i = 0; i < vertices_nb; ++i)
      {
	dist[i] = INT_MAX;
	parent[i] = -1;
      }
    dist[start] = 0;

    for (int loop = 0; loop < vertices_nb - 1; ++loop)
      for (int source = 0; source < vertices_nb; ++source)
	for (std::pair<int, int> edge : adj[source])
	  {
	    int destination = edge.first;
	    int weight = edge.second;
	    if (dist[source] != INT_MAX && dist[destination] > dist[source] + weight)
	      {
		dist[destination] = dist[source] + weight;
		parent[destination] = source;
	      }
	  }

    for (int source = 0; source < vertices_nb; ++source)
      for (std::pair<int, int> edge : adj[source])
	{
	  int destination = edge.first;
	  int weight = edge.second;
	  if (dist[source] != INT_MAX && dist[destination] > dist[source] + weight)
	    {
	      std::cout << "graph contains a negative weight cycle" << std::endl;
	      return ;
	    }
	}

    // print results
    std::cout << "Vertex\tDistance\tPath" << std::endl;
    for (int i = 0; i < vertices_nb; ++i)
      {
	std::cout << i << "\t" << dist[i] << "\t\t";
	for (int j = i; parent[j] != -1; j = parent[j])
	  std::cout << parent[j] << " ";
	std::cout << std::endl;
      }

    delete[] dist;
    delete[] parent;
  }

  void dijkstra(int start = 0, int target = -1)
  {
    std::priority_queue<std::pair<unsigned, int>,
			std::vector<std::pair<unsigned, int> >,
			std::greater<std::pair<unsigned, int> > > pq;

    unsigned *dist = new unsigned[vertices_nb];
    int *parent = new int[vertices_nb];

    dist[start] = 0;

    for (int a = 0; a < vertices_nb; ++a)
      {
	if (a != start)
	  dist[a] = -1;
	parent[a] = -1;
	pq.push(std::make_pair(dist[a], a));
      }
    while (!pq.empty())
      {
	std::pair<unsigned, int> current = pq.top();
	if (current.second == target)
	  break ;
	pq.pop();

	for (std::pair<int, int> e : adj[current.second])
	  {
	    int weight = e.second;
	    if (dist[e.first] > dist[current.second] + weight)
	      {
		dist[e.first] = dist[current.second] + weight;
		parent[e.first] = current.second;
		pq.push(std::make_pair(dist[e.first], e.first));
	      }
	  }
      }

    // print results
    std::stack<int> s;

    if (target == -1)
      {
	std::cout << "Node\tDistance\tPath" << std::endl;
	for (int a = 0; a < vertices_nb; ++a)
	  {
	    std::cout << a << "\t" << dist[a] << "\t\t";
	    for (int j = a; parent[j] != -1; j = parent[j])
	      s.push(parent[j]);
	    while (!s.empty())
	      {
		std::cout << s.top() << " ";
		s.pop();
	      }
	    std::cout << std::endl;
	  }
      }
    else
      {
	std::cout << target << "\t" << dist[target] << "\t\t";
	while (parent[target] != -1)
	  {
	    s.push(parent[target]);
	    target = parent[target];
	  }
	while (!s.empty())
	  {
	    std::cout << s.top() << " ";
	    s.pop();
	  }
      }

    std::cout << std::endl;
    delete[] dist;
    delete[] parent;
  }

  void topological_sort_it()
  {
    std::vector<int> inc_edges(vertices_nb, 0);
    std::stack<int> no_inc_edges;
    std::queue<int> q;

    for (int a = 0; a < vertices_nb; ++a)
      for (std::pair<int, int> e : adj[a])
	++inc_edges[e.first];

    for (int a = 0; a < vertices_nb; ++a)
      if (!inc_edges[a])
	no_inc_edges.push(a);

    while (!no_inc_edges.empty())
      sub_topological_sort_it(no_inc_edges, inc_edges, q);

    // print results
    while (!q.empty())
      {
	std::cout << q.front() << " ";
	q.pop();
      }
    std::cout << std::endl;
  }

  void sub_topological_sort_it(std::stack<int> &no_inc_edges,
			       std::vector<int> &inc_edges,
			       std::queue<int> &q)
  {
    int current = no_inc_edges.top();
    no_inc_edges.pop();
    q.push(current);

    for (std::pair<int, int> e : adj[current])
      if (!--inc_edges[e.first])
	no_inc_edges.push(e.first);
  }

  void topological_sort_rec()
  {
    bool *visited = new bool[vertices_nb];
    std::stack<int> s;

    for (int a = 0; a < vertices_nb; ++a)
      visited[a] = false;

    for (int a = 0; a < vertices_nb; ++a)
      if (!visited[a])
	sub_topological_sort_rec(a, visited, s);

    // print results
    while (!s.empty())
      {
	std::cout << s.top() << " ";
	s.pop();
      }
    std::cout << std::endl;
    delete[] visited;
  }

  void sub_topological_sort_rec(int elem, bool *visited, std::stack<int> &s)
  {
    visited[elem] = true;

    for (std::pair<int, int> e : adj[elem])
      {
	if (!visited[e.first])
	  sub_topological_sort_rec(e.first, visited, s);
      }
    s.push(elem);
  }

  void bfs()
  {
    bool *visited = new bool[vertices_nb];
    ::memset(visited, 0, vertices_nb);

    for (int a = 0; a < vertices_nb; ++a)
      if (!visited[a])
	sub_bfs(a, visited);
    std::cout << std::endl;
    delete[] visited;
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

  void dfs_it()
  {
    bool visited[vertices_nb];
    ::memset(&visited[0], 0, vertices_nb);

    for (int a = 0; a < vertices_nb; ++a)
      if (!visited[a])
	sub_dfs_it(a, visited);
    std::cout << std::endl;
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

  void dfs_rec()
  {
    bool visited[vertices_nb];
    ::memset(&visited[0], 0, vertices_nb);

    for (int a = 0; a < vertices_nb; ++a)
      if (!visited[a])
	sub_dfs_rec(a, visited);
    std::cout << std::endl;
  }

  void sub_dfs_rec(int elem, bool *visited)
  {
    std::cout << elem << " ";
    visited[elem] = true;
    for (auto i : adj[elem])
      if (!visited[i.first])
	sub_dfs_rec(i.first, visited);
  }

private:
  int vertices_nb;
  std::list<std::pair<int, int> > *adj;
};

int main(void)
{
  // number of vertices given at construction
  Graph g(4);

  /*// an undirected graph example - uncomment the second .push_back() in buildEdge()
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
  g.buildEdge(7, 8, 7);*/

  /*  // a directed graph example - comment the second .push_back() in buildEdge()
  g.buildEdge(0, 1, -1);
  g.buildEdge(0, 2, 4);
  g.buildEdge(1, 2, 3);
  g.buildEdge(1, 3, 2);
  g.buildEdge(1, 4, 2);
  g.buildEdge(3, 1, 1);
  g.buildEdge(3, 2, 5);
  g.buildEdge(4, 3, -4);
  */

  /* // another directed graph example
  g.buildEdge(0, 1, 4);
  g.buildEdge(0, 2, 5);
  g.buildEdge(0, 3, 8);
  g.buildEdge(1, 2, -3);
  g.buildEdge(2, 4, 4);
  g.buildEdge(4, 3, 1);
  g.buildEdge(3, 4, 2);
  */

   // a directed graph with a negative cycle example
  g.buildEdge(0, 2, -2);
  g.buildEdge(1, 0, 4);
  g.buildEdge(1, 2, 3);
  g.buildEdge(2, 3, 2);
  g.buildEdge(3, 1, -1);

  /* // a DAG example
  g.buildEdge(5, 2, 0);
  g.buildEdge(5, 0, 0);
  g.buildEdge(4, 0, 0);
  g.buildEdge(4, 1, 0);
  g.buildEdge(2, 3, 0);
  g.buildEdge(3, 1, 0);
  */

  g.dfs_rec();

  //g.dfs_it();

  g.bfs();

  //g.dijkstra();
  //g.dijkstra(3, 6);

  // on a DAG only
  //g.topological_sort_rec();
  //g.topological_sort_it();

  //g.bellman_ford();

  g.floyd_warshall();

  return 0;
}
