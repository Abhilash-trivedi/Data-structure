Node* mirro(Node* node)
{
    if(node==NULL)return node;
    Node* temp=mirro(node->right);
    node->right=mirro(node->left);
    node->left=temp;
    return node;
}
