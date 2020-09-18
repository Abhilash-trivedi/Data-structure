int countNonLeafNodes(Node* root)
{
    queue<Node*>q;
    q.push(root);
    int count=0;
    while(!q.empty())
    {
        Node* a=q.front();
        q.pop();
        if(a!=NULL&&(a->left||a->right))
        {
            count++;
            if(a->left)
            {
                q.push(a->left);
            }
            if(a->right)
            {
                q.push(a->right);
            }
        }
    }
    return count;
}
