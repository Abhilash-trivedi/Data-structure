class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if(head==NULL||head->next==NULL||m==n)
        {
            return head;
        }
        int count=1;
        ListNode* p1=head;
        while(count<(m-1)&&p1)
        {
            count++;
            p1=p1->next;
        }
        ListNode* temp=p1;
        ListNode* temp1=p1->next;
        if(m==1)
        {
            temp1=temp;
        }
        
        while(count<n&&p1)
        {
            count++;
            p1=p1->next;
        }
        ListNode* temp2=p1->next;
        ListNode* curr=temp1,*prev=temp2,*next=NULL;
        while(curr!=temp2)
        {
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        
        if(m==1)
        {
           return prev;
            
        }
        temp->next=prev;
        return head;
    }
};
