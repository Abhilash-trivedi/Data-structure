Node * inOrderSuccessor(Node *root, Node *x)
{
    Node* p=NULL;
    while(root&&root!=x)
    {
        if(root->data<x->data)
        {
            root=root->right;
        }else{
            p=root;
            root=root->left;
        }
    }
    if(!root)return NULL;
    if(!root->right)return p;
    root=root->right;
    while(root->left)
    {
        root=root->left;
    }
    return root;
}
