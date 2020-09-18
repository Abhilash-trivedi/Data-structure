void cal(Node *root, int low, int high,vector<int>&ans)
{
    if(root==NULL)
    {
        return;
    }
    if(root->data>low)
    {
        cal(root->left,low,high,ans);
    }
   if(root->data>=low&&root->data<=high) ans.push_back(root->data);
    if(root->data<high)
    {
         cal(root->right,low,high,ans);
    }
}

vector<int> printNearNodes(Node *root, int low, int high)
{
  vector<int>ans;
  cal(root, low,high,ans);
  return ans;
}
