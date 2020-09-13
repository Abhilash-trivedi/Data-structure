int getMaxWidth(Node* root)
{
  if(root==NULL)
  {
      return 0;
  }
   int c=0;
   queue<Node*>q;
   q.push(root);
   while(!q.empty())
   {
       int sz=q.size();
       c=max(sz,c);
       while(sz--)
       {
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
   return c;
}

