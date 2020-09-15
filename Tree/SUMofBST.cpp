long int sumBT(Node* root)
{
    queue<Node*>q;
    q.push(root);
    long sum=0;
    while(!q.empty())
    {
        Node* a=q.front();
        sum+=(a->key);
        if(a->left)
        {
            q.push(a->left);
        }
        if(a->right)
        {
            q.push(a->right);
        }
        q.pop();
    }
    return sum;
}
