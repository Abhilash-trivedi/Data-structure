Node *sortedInsert(Node* head, int x)
{
   Node* curr=head;
   if(curr==NULL)
   {
       curr=new Node(x);
       head=curr;
       return head;
       
   }else if(curr->data>=x)
   {
      Node* temp= new Node(x);
      while(curr->next!=head)
      {
          curr=curr->next;
      }
      temp->next=head;
      head=temp;
      curr->next=temp;
   }else
   {
       Node* temp= new Node(x);
       while(curr->next->data<=x&&curr->next!=head)
       {
           curr=curr->next;
       }
       temp->next=curr->next;
       
       curr->next=temp;
      
   }
   return head;
}
