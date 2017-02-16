Vertex    *dup_graph(Vertex *u)
{
  std::queue<Vertex *> q;
  std::unordered_map<int, Vertex *> map;

  q.push(u);
  while (!q.empty())
    {
      u = q.front();
      q.pop_front();

      Vertex *x;
      if (map.find(u->label) == std::end(map))
        {
	  x = new Vertex(*u);
	  map[u->label] = x;
	}
      else
        {
	  x = map[u->label];
	}
      if (map.empty())
        {
	  u_copy = x;
	}

      for (Vertex *v : u->edges)
        {
	  if (map.find(v->label) == std::end(map))
            {
	      Vertex *tmp;
	      if (map.find(v->label) == std::end(map))
                {
		  tmp = new Vertex(*v);
		  map[tmp->label] = tmp;
		}
	      else
		{
		  tmp = map[v->label];
		}
	      x->edges.push_back(tmp);
	      q.push(v);
	    }
	}
    }

  return u_copy;
}
