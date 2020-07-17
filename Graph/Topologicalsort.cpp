vector<int> topoSort(int V, vector<int> adj[]) {
  vector<int>ans;

  vector<bool>visited(V,0);
  stack<int>s;

  for(int i=0;i<V;i++)
  {
     if(!visited[i])
     {
     s.push(i);
     visited[i]=1;
     while(!s.empty())
     {

         int p=s.top();
         int sz=s.size();
         for(auto i:adj[p])
         {
             if(!visited[i])
             {
                 s.push(i);
                 visited[i]=1;
                 break;
             }
         }
         if(s.size()==sz)
         {
             ans.push_back(p);
             s.pop();
         }
     }
    }
}

for(int i=0;i<ans.size()/2;i++)
{
    swap(ans[i],ans[V-1-i]);
}

return ans;

}
