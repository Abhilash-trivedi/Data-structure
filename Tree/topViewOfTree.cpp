void topView(struct Node *root)
{
    if(root==NULL)return;
    unordered_map<int,int>unp;
    queue<pair<Node*,int>>q;
    q.push(make_pair(root,0));
    vector<pair<int,int>>v;
    while(!q.empty())
    {
        pair<Node*,int>p=q.front();
        q.pop();
        if(unp.find(p.second)==unp.end())
        {
            unp[p.second]=1;
            v.push_back(make_pair(p.second,p.first->data));
        }
        if(p.first->left)
        {
            q.push(make_pair(p.first->left,p.second-1));
        }
        if(p.first->right)
        {
            q.push(make_pair(p.first->right,p.second+1));
        }
    }
    sort(v.begin(),v.end());
    for(auto i:v)
    {
        cout<<i.second<<" ";
    }

}
