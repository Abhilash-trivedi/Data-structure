vector<int> Kdistance(struct Node *root, int k)
{
  vector<int>ans;
  queue<Node*>q;
  q.push(root);
  int count=-1;
  while(!q.empty())
  {
      int sz=q.size();
      count++;
      while(sz--)
      {
          Node* a=q.front();
          if(count==k)
          {
              ans.push_back(a->data);
          }
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
  }
  return ans;
}
