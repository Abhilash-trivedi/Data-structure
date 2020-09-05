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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL||k==0)
        {
            return head;
        }
        ListNode* curr=head,*prev=NULL,*next=NULL;
        int count=1;
        while(curr->next)
        {
            curr=curr->next;
            count++;
        }
        cout<<curr->val<<endl;
        k%=count;
        int count1=1;
        ListNode* temp=curr;
        curr=head;
        k=count-k;
        while(curr&&count1<k)
        {
            curr=curr->next;
            count1++;
        }
       
        temp->next=head;
        head=curr->next;
        curr->next=NULL;
        
        
        return head;
    }
};
