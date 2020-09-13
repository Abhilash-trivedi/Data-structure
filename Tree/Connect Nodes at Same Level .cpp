void connect(Node *p)
{
   queue<Node*>q;
   q.push(p);
   q.push(NULL);
   while(!q.empty())
   {
       Node* a=q.front();
       if(a->left)
       {
           q.push(a->left);
       }
       if(a->right)
       {
           q.push(a->right);
       }
       q.pop();
       a->nextRight=q.front();
       if(q.front()==NULL)
       {
           q.pop();
           if(!q.empty())
           {
               q.push(NULL);
           }
       }
   }
}

