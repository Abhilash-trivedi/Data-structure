void convert(Node *head, TreeNode *&root) {
    
  root=new TreeNode(head->data);
  head=head->next;
  queue<TreeNode*>q;
  q.push(root);
 
  while(head)
  {
      TreeNode* tmp=q.front();
      q.pop();
      
      tmp->left=new TreeNode(head->data);
      
      q.push(tmp->left);
      head=head->next;
      if(head)
      {
          tmp->right=new TreeNode(head->data);
          head=head->next;
          q.push(tmp->right);
      }
      
  }
}
