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
    //adj[vertex2].push_back(std::make_pair(vertex1, weight));
  }

  Graph copy_graph()
  {
    Graph g(vertices_nb);

    for (int a = 0; a < vertices_nb; ++a)
      for (std::pair<int, int> edge : adj[a])
	g.buildEdge(a, edge.first, edge.second);

    return g;
  }

  int get_capacity_of_edge(int u, int v)
  {
    for (std::pair<int, int> edge : adj[u])
      if (v == edge.first)
	return edge.second;
    return INT_MAX;
  }

  void set_capacity_of_edge(int u, int v, int capacity)
  {
    for (auto it = std::begin(adj[u]); it != std::end(adj[u]); ++it)
      if (it->first == v)
	{
	  it->second = capacity;
	  return ;
	}
  }

  bool find_path_bfs(int start, int end, int *parent)
  {
    std::queue<int> q;
    bool visited[vertices_nb];

    for (int a = 0; a < vertices_nb; ++a)
      visited[a] = false;

    q.push(start);

    while (!q.empty())
      {
	int u = q.front();
	q.pop();

	visited[u] = true;

	if (u == end)
	  break ;

	for (std::pair<int, int> edge : adj[u])
	  if (!visited[edge.first] && edge.second > 0)
	    {
	      parent[edge.first] = u;
	      q.push(edge.first);
	    }
      }

    return visited[end];
  }

  void ford_fulkerson(int s, int t)
  {
    // no flow at the beginning
    int max_flow = 0;
    // so residual graph is the same as the given graph
    Graph residual_graph = copy_graph();

    int *parent = new int[vertices_nb];

    // while there is a path between s and t
    while (residual_graph.find_path_bfs(s, t, parent))
      {
	// get the maximum residual capacity of the edges
	// on the path found by the bfs
	int path_flow = INT_MAX;
	int u, v;
	for (v = t; v != s; v = parent[v])
	  {
	    u = parent[v];
	    path_flow = std::min(path_flow, residual_graph.get_capacity_of_edge(u, v));
	  }

	// update residual capacities on the path found by bfs
	for (v = t; v != s; v = parent[v])
	  {
	    u = parent[v];
	    int current = residual_graph.get_capacity_of_edge(u, v);
	    int tmp = current - path_flow;
	    residual_graph.set_capacity_of_edge(u, v, tmp);

	    current = residual_graph.get_capacity_of_edge(v, u);
	    // if edge v->u doesn't exist
	    if (current == INT_MAX && tmp > 0)
	      // we create it
	      residual_graph.buildEdge(v, u, path_flow);
	    else if (current != INT_MAX)
	      residual_graph.set_capacity_of_edge(v, u, current + path_flow);
	  }

	max_flow += path_flow;
      }

    std::cout << "maximum flow: " << max_flow << std::endl;

    delete[] parent;
  }

  void is_bipartite()
  {
    bool *set1 = new bool[vertices_nb];
    bool *set2 = new bool[vertices_nb];

    for (int a = 0; a < vertices_nb; ++a)
      {
	set1[a] = false;
	set2[a] = false;
      }

    // BFS
    for (int a = 0; a < vertices_nb; ++a)
      {
	std::queue<int> q;

	if (set1[a] || set2[a]) // already visited
	  continue ;
	set1[a] = true;
	q.push(a);

	while (!q.empty())
	  {
	    int u = q.front();
	    q.pop();

	    for (std::pair<int, int> edges : adj[u])
	      {
		if (!set1[edges.first] && !set2[edges.first]) // if not visited
		  {
		    if (set1[u])
		      set2[edges.first] = true;
		    else
		      set1[edges.first] = true;
		    q.push(edges.first);
		  }
		else if ((set1[edges.first] && set1[u]) || (set2[edges.first] && set2[u]))
		  {
		    std::cout << "Graph is not bipartite!" << std::endl;
		    delete[] set1;
		    delete[] set2;
		    return ;
		  }
	      }
	  }
      }
    std::cout << "Graph is bipartite!" << std::endl;

    delete[] set1;
    delete[] set2;
  }

  Graph transpose_graph()
  {
    Graph g(vertices_nb);

    for (int a = 0; a < vertices_nb; ++a)
      for (std::pair<int, int> edge : adj[a])
	g.buildEdge(edge.first, a, edge.second);

    return g;
  }

  void fill_topolike_order(int elem, std::stack<int> &s, bool *visited)
  {
    visited[elem] = true;
    for (std::pair<int, int> edge : adj[elem])
      if (!visited[edge.first])
	fill_topolike_order(edge.first, s, visited);
    s.push(elem);
  }

  void kosarajuSCC()
  {
    std::stack<int> s;
    bool *visited = new bool[vertices_nb];

    for (int a = 0; a < vertices_nb; ++a)
      visited[a] = false;

    for (int a = 0; a < vertices_nb; ++a)
      if (!visited[a])
	fill_topolike_order(a, s, visited);

    Graph g = transpose_graph();

    for (int a = 0; a < vertices_nb; ++a)
      visited[a] = false;

    std::cout << "Strongly connected components:" << std::endl;
    while (!s.empty())
      {
	int u = s.top();
	s.pop();
	if (!visited[u])
	  {
	    g.sub_dfs_rec(u, visited);
	    std::cout << std::endl;
	  }
      }

    delete[] visited;
  }

  void primMST()
  {
    std::priority_queue<std::pair<int, int>,
			std::vector<std::pair<int, int> >,
			std::greater<std::pair<int, int> > > pq;
    int *dist = new int[vertices_nb];
    int *parent = new int[vertices_nb];
    bool *inMST = new bool[vertices_nb];

    for (int a = 0; a < vertices_nb; ++a)
      {
	dist[a] = INT_MAX;
	parent[a] = -1;
	inMST[a] = false;
      }

    dist[0] = 0;
    pq.push(std::make_pair(dist[0], 0));

    while (!pq.empty())
      {
	int u = pq.top().second;
	pq.pop();

	inMST[u] = true;

	for (std::pair<int, int> e : adj[u])
	  {
	    if (!inMST[e.first] && dist[e.first] > e.second)
	      {
		dist[e.first] = e.second;
		parent[e.first] = u;
		pq.push(std::make_pair(dist[e.first], e.first));
	      }
	  }
      }

    std::cout << "Minimum spanning tree:" << std::endl;
    for (int i = 1; i < vertices_nb; ++i)
      std::cout << parent[i] << " - " << i << std::endl;

    delete[] inMST;
    delete[] dist;
    delete[] parent;
  }

  void floyd_warshall()
  {
    int **dist = new int *[vertices_nb];
    int **parent = new int *[vertices_nb];

    for (int a = 0; a < vertices_nb; ++a)
      {
	dist[a] = new int[vertices_nb];
	parent[a] = new int[vertices_nb];

	for (int b = 0; b < vertices_nb; ++b)
	  {
	    if (a == b)
	      dist[a][b] = 0;
	    else
	      dist[a][b] = INT_MAX;
	    parent[a][b] = -1;
	  }

	for (std::pair<int, int> e : adj[a])
	  {
	    dist[a][e.first] = e.second;
	    parent[a][e.first] = a;
	  }
      }

    for (int k = 0; k < vertices_nb; ++k)
      for (int i = 0; i < vertices_nb; ++i)
	for (int j = 0; j < vertices_nb; ++j)
	  if (dist[i][k] != INT_MAX && dist[k][j] != INT_MAX
	      && dist[i][j] > dist[i][k] + dist[k][j])
	    {
	      dist[i][j] = dist[i][k] + dist[k][j];
	      parent[i][j] = parent[k][j];
	    }

    for (int a = 0; a < vertices_nb; ++a)
      if (dist[a][a] != 0)
	{
	  std::cout << "negative cycle detected!" << std::endl;
	  for (int i = 0; i < vertices_nb; ++i)
	    {
	      delete[] dist[i];
	      delete[] parent[i];
	    }
	  delete[] dist;
	  delete[] parent;
	  return ;
	}

    for (int a = 0; a < vertices_nb; ++a)
      {
	for (int b = 0; b < vertices_nb; ++b)
	  {
	    std::cout << "edge " << a << " - " << b << ", distance " << dist[a][b] << ", path:";

	    int c = b;
	    while (c != -1)
	      {
		std::cout << c << " ";
		c = parent[a][c];
	      }
	    std::cout << std::endl;
	  }
	delete[] dist[a];
	delete[] parent[a];
      }

    delete[] dist;
    delete[] parent;
  }

  void bellman_ford(int start = 0)
  {
    int *parent = new int[vertices_nb];
    int *dist = new int[vertices_nb];

    for (int a = 0; a < vertices_nb; ++a)
      {
	parent[a] = -1;
	dist[a] = INT_MAX;
      }

    dist[start] = 0;

    for (int a = 0; a < vertices_nb - 1; ++a)
      for (int u = 0; u < vertices_nb; ++u)
	for (std::pair<int, int> edge : adj[u])
	  {
	    if (dist[u] != INT_MAX && dist[edge.first] > dist[u] + edge.second)
	      {
		dist[edge.first] = dist[u] + edge.second;
		parent[edge.first] = u;
	      }
	  }
    for (int u = 0; u < vertices_nb; ++u)
      for (std::pair<int, int> edge : adj[u])
	{
	  if (dist[u] != INT_MAX && dist[edge.first] > dist[u] + edge.second)
	    {
	      std::cout << "negative cycle detected!" << std::endl;
	      delete[] dist;
	      delete[] parent;
	      return ;
	    }
	}

    std::cout << "Vertex\tDistance\tPath" << std::endl;
    for (int a = 0; a < vertices_nb; ++a)
      {
	std::cout << a << "\t" << dist[a] << "\t\t";
	int b = a;
	while (b != -1)
	  {
	    std::cout << b << " ";
	    b = parent[b];
	  }
	std::cout << std::endl;
      }

    delete[] parent;
    delete[] dist;
  }

  void dijkstra(int start = 0, int target = -1)
  {
    std::priority_queue<std::pair<int, int>,
			std::vector<std::pair<int, int> >,
			std::greater<std::pair<int, int> > > pq;
    int *parent = new int[vertices_nb];
    int *dist = new int[vertices_nb];

    for (int a = 0; a < vertices_nb; ++a)
      {
	parent[a] = -1;
	dist[a] = INT_MAX;
      }

    dist[start] = 0;
    pq.push(std::make_pair(dist[start], start));

    while (!pq.empty())
      {
	int u = pq.top().second;
	if (u == target)
	  break ;
	pq.pop();

	for (std::pair<int, int> edge : adj[u])
	  {
	    if (dist[edge.first] > dist[u] + edge.second)
	      {
		dist[edge.first] = dist[u] + edge.second;
		parent[edge.first] = u;
		pq.push(std::make_pair(dist[edge.first], edge.first));
	      }
	  }
      }

    std::cout << "Vertex\tDistance\tPath" << std::endl;
    if (target == -1)
      {
	for (int a = 0; a < vertices_nb; ++a)
	  {
	    std::cout << a << "\t" << dist[a] << "\t\t";
	    int i = a;
	    while (i != -1)
	      {
		std::cout << i << " ";
		i = parent[i];
	      }
	    std::cout << std::endl;
	  }
      }
    else
      {
	std::cout << "start: " << start << ", target: " << target << ", path: ";
	while (target != -1)
	  {
	    std::cout << target << " ";
	    target = parent[target];
	  }
	std::cout << std::endl;
      }

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

	    for (std::pair<int, int> e : adj[current])
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

	    for (std::pair<int, int> e : adj[current])
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
    for (std::pair<int, int> edge : adj[elem])
      if (!visited[edge.first])
	sub_dfs_rec(edge.first, visited);
  }

private:
  int vertices_nb;
  std::list<std::pair<int, int> > *adj;
};

int main(void)
{
  // number of vertices given at construction
  Graph g(6);

  /* // an undirected graph - uncomment the second .push_back() in buildEdge()
  g.buildEdge(0, 1, 4);
  g.buildEdge(0, 7, 8);
  g.buildEdge(1, 2, 8);
  g.buildEdge(1, 7, 11);
  g.buildEdge(2, 3, 7);
  g.buildEdge(2, 8, 2);
  g.buildEdge(2, 5, 4);
  g.buildEdge(3, 4, 9);
  g.buildEdge(3, 5, 14);
  g.buildEdge(4, 5, 10);
  g.buildEdge(5, 6, 2);
  g.buildEdge(6, 7, 1);
  g.buildEdge(6, 8, 6);
  g.buildEdge(7, 8, 7);
  */

  // a directed graph used for the maximum flow problem
  g.buildEdge(0, 1, 16);
  g.buildEdge(0, 2, 13);
  g.buildEdge(1, 2, 10);
  g.buildEdge(1, 3, 12);
  g.buildEdge(2, 1, 4);
  g.buildEdge(2, 4, 14);
  g.buildEdge(3, 2, 9);
  g.buildEdge(3, 5, 20);
  g.buildEdge(4, 3, 7);
  g.buildEdge(4, 5, 4);

  /* // an undirected, connected and bipartite graph
  g.buildEdge(0, 1, 0);
  g.buildEdge(0, 3, 0);
  g.buildEdge(0, 7, 0);
  g.buildEdge(1, 6, 0);
  g.buildEdge(1, 2, 0);
  g.buildEdge(2, 5, 0);
  g.buildEdge(2, 3, 0);
  g.buildEdge(3, 4, 0);
  g.buildEdge(4, 5, 0);
  g.buildEdge(4, 7, 0);
  g.buildEdge(5, 6, 0);
  g.buildEdge(6, 7, 0);
  */

  /* // an undirected, connected, not bipartite graph
  g.buildEdge(0, 1, 0);
  g.buildEdge(1, 2, 0);
  g.buildEdge(2, 3, 0);
  g.buildEdge(3, 4, 0);
  g.buildEdge(4, 2, 0);
  */

  /* // a directed graph - comment the second .push_back() in buildEdge()
  g.buildEdge(0, 1, -1);
  g.buildEdge(0, 2, 4);
  g.buildEdge(1, 2, 3);
  g.buildEdge(1, 3, 2);
  g.buildEdge(1, 4, 2);
  g.buildEdge(3, 1, 1);
  g.buildEdge(3, 2, 5);
  g.buildEdge(4, 3, -3);
  */

  /* // another directed graph
  g.buildEdge(1, 0, 4);
  g.buildEdge(0, 2, 5);
  g.buildEdge(2, 1, 8);
  g.buildEdge(0, 3, -3);
  g.buildEdge(3, 4, 4);
  */

  /* // a directed graph with a negative cycle
  g.buildEdge(0, 2, -2);
  g.buildEdge(1, 0, 4);
  g.buildEdge(1, 2, 3);
  g.buildEdge(2, 3, 2);
  g.buildEdge(3, 1, -1);
  */

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

  //g.floyd_warshall();

  //g.primMST();

  // on a directed graph only
  //g.kosarajuSCC();

  // g.is_bipartite();

  g.ford_fulkerson(0, 5);

  return 0;
}
