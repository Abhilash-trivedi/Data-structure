void levelOrder(Node* node)
{
  queue<Node*>q;
  q.push(node);
  q.push(NULL);
  while(!q.empty())
  {
      if(q.front())
      {
          cout<<q.front()->data<<" ";
          if(q.front()->left)q.push(q.front()->left);
          if(q.front()->right)q.push(q.front()->right);
          q.pop();
      }else{
          cout<<"$ ";
          q.pop();
          if(!q.empty())
          {
              q.push(NULL);
          }
      }
  }
}


