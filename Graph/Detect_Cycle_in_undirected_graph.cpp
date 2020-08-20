bool Cyclic(int node,vector<bool>visited,int parent,vector<int> g[])
{
    visited[node]=1;
    for(auto i:g[node])
    {
        if(!visited[i])
        {
            if(Cyclic(i,visited,node,g))
            {
                return true;
            }
        }else if(visited[i]&&i!=parent)
        {
            return true;
        }
    }
    return false;
}

bool isCyclic(vector<int> g[], int V)
{
  vector<bool>visited(V,0);
  for(int i=0;i<V;i++)
  {
      if(!visited[i])
      {
          if(Cyclic(i,visited,-1,g))
          {
              return true;
          }
      }
  }
  return false;
   
}
