int countLeaves(Node* root)
{
    if(root==nullptr)return 0;
  int l=countLeaves(root->left);
  int r=countLeaves(root->right);
  if(l==0&&r==0)
  {
      return 1;
  }
  return l+r;
}
