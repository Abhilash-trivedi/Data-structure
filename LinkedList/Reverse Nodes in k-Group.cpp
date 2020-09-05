/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        //cout<<head->val<<" ";
        ListNode* curr=head,*prev=NULL,*nxt=NULL;
        int count=1;
        while(curr&&count<k)
        {
            curr=curr->next;
            count++;
        }
        if(count<k||curr==NULL)
        {
            return head;
        }
        
        count=0;
        if(curr)
        {
            prev=reverseKGroup(curr->next,k);
            // cout<<prev->val<<endl;
        }
        curr=head;
        while(curr&&count<k)
        {
            nxt=curr->next;
            curr->next=prev;
            prev=curr;
            curr=nxt;
            count++;
        }
       return prev;
      
    }
};
