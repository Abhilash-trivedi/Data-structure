void Kia(Node* root,int k,int &c,int& ans)
{
    if(root==NULL||c>=k)
    {
        return;
    }
    
    Kia(root->right,k,c,ans);
    
    c++;
    if(c==k)
    {
        ans=root->data;
    }
    Kia(root->left,k,c,ans);
    
    return;
}
int kthLargest(Node *root, int K)
{
    int c=0,ans=-1;
    Kia(root,K,c,ans);
    return ans;
}
