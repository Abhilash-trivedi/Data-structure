vector<int> reverseLevelOrder(Node *root)
{
    vector<int>ans;
    queue<Node*>q;
    stack<Node*>s;
    q.push(root);
    while(!q.empty())
    {
        Node* a=q.front();
        if(a->right)
        {
            q.push(a->right);
        }
        if(a->left)
        {
            q.push(a->left);
        }
        
        q.pop();
        s.push(a);
    }
    while(!s.empty())
    {
        ans.push_back(s.top()->data);
        s.pop();
    }
    return ans;
}
