Node* convert(Node* root,Node** head_r)
{
    if(root==NULL)
    {
        return NULL;
    }
    if(root->left==NULL&&root->right==NULL)
    {
        root->right=*head_r;
        if(*head_r!=NULL){
            (*head_r)->left=root;
        }
        *head_r=root;
        return NULL;
    }
    root->right=convert(root->right,head_r);
    root->left=convert(root->left,head_r);
    return root;
}
Node * convertToDLL(Node *root){
    Node* head=NULL;
   root=convert(root,&head);
   return head;
}
