bool check(Node* r1,Node* r2)
{
    if(r1==NULL&&r2==NULL)
    {
        return true;
    }
    if(r1==NULL||r2==NULL)
    {
        return false;
    }
    bool l=check(r1->left,r2->right);
    bool r=check(r1->right,r2->left);
    
    return l&r;
}
bool IsFoldable(Node* root)
{
    if(root==NULL)return true;
    return check(root->left,root->right);
}
