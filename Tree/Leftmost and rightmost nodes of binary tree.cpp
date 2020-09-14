void printCorner(Node *root)
{

    if(root==NULL)return;
    queue<Node*>q;
    q.push(root);
    while(!q.empty())
    {
        int n=q.size();
        bool f=0;
        while(n--)
        {
            if(f==0||n==0)
            {
                cout<<q.front()->data<<" ";
                f=1;
            }
            if(q.front()->left)
            {
                q.push(q.front()->left);
            }
            if(q.front()->right)
            {
                q.push(q.front()->right);
            }
            q.pop();
            
        }
    }

}
