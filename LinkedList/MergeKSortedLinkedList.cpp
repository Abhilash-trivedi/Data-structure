class Solution {
public:
    ListNode* merge(ListNode* a,ListNode* b)
    {
        if(a==NULL)return b;
        if(b==NULL)return a;
        ListNode* result;
        if(a->val<b->val)
        {
            result=a;
            result->next=merge(a->next,b);
        }else{
            result=b;
            result->next=merge(a,b->next);
        }
        return result;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        
        int n=lists.size();
        if(n==0)return NULL;
        ListNode* res=lists[0];
        for(int i=1;i<n;i++)
        {
            res=merge(res,lists[i]);
        }
        return res;
    }
};
