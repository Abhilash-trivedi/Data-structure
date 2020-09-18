int maxLevelSum(Node* root) {
   if(!root)return 0;
   queue<Node*>q;
   q.push(root);
   int mx=INT_MIN;
   while(!q.empty())
   {
       int n=q.size();
       int sum=0;
       while(n--)
       {
            Node* a=q.front();
            q.pop();
            sum+=a->data;
            if(a->left)
            {
                q.push(a->left);
            }
            if(a->right)
            {
                q.push(a->right);
            }
       }
       mx=max(mx,sum);
   }
   return mx;
}
