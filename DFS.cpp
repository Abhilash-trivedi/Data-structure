vector <int> dfs(vector<int> g[], int N)
{
    int visited[N];
    memset(visited,0,sizeof(visited));
    stack<int>s;
    s.push(0);
    visited[0]=true;
    vector<int>v;
    v.push_back(0);
    while(!s.empty())
    {
        int p=s.top();

        int n=s.size();
        for(auto i:g[p])
        {
            if(!visited[i])
            {
               s.push(i);

               visited[i]=1;
               v.push_back(i);
                break;
            }
        }
        if(n==s.size())
        {s.pop();}

    }
    return v;


}
