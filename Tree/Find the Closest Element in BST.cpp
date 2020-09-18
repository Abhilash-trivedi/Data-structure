void midd(Node* root,int k,int& mi,int& node)
{
    if(!root)
    {
        return;
    }
    if(mi>abs(root->data-k))
    {
        mi=abs(root->data-k);
        node=root->data;
    }
    
    if(k<root->data)
    {
        midd(root->left,k,mi,node);
    }else
    {
        midd(root->right,k,mi,node);
    }
}

int minDiff(Node *root, int k)
{
    int mi=INT_MAX,node=-1;
   midd(root,k,mi,node);
   return node;
}
