bool isBal(Node* root,int *height)
{
    int lh,rh;
    if(root==NULL)
    {
        *height=0;
        return 1;
    }
    bool l=isBal(root->left,&lh);
    bool r=isBal(root->right,&rh);
    *height=(lh>rh?lh:rh)+1;
    if(abs(lh-rh)>1)
    {
        return 0;
    }
    return l&r;
}
bool isBalanced(Node *root)
{
    int h;
  return isBal(root,&h);
}
