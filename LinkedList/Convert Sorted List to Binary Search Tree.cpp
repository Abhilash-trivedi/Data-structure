class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head)
    {
        if(head==NULL)
        {
            return NULL;
        }
        
        if(head->next == nullptr) 
        {
            return new TreeNode(head->val);
        }
        
        ListNode* slow=head,*fast=head,*tmp;
        while(fast&&fast->next)
        {
            tmp=slow;
            slow=slow->next;
            fast=fast->next->next;
            
        }
        tmp->next=NULL;
        TreeNode *root = new TreeNode(slow->val);
        root->left=sortedListToBST(head);
        root->right=sortedListToBST(slow->next);
        return root;
    }
    
};
