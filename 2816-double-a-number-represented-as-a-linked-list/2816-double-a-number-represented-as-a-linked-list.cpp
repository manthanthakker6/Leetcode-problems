class Solution {
    private:
    void reverseLinkedList(ListNode* & head,ListNode* curr,ListNode* prev){
        if(curr==NULL){
            head=prev;
            return;
        }
        ListNode* forward=curr->next;
        reverseLinkedList(head,forward,curr);
        curr->next=prev;

    }
public:
    ListNode* doubleIt(ListNode* head) {
      ListNode* curr=head;
      ListNode* prev=NULL;
      reverseLinkedList(head,curr,prev);

      //curr will point to the head of reversed linked list

        curr=head;
        int carry=0;
        ListNode* tail = NULL;
        while(curr!=NULL){
            int total=(curr->val*2)+carry;
            curr->val=total%10;
            carry=total/10;
            tail=curr;
            curr=curr->next;
        }
        if(carry>0){
            tail->next= new ListNode(carry);

        }
        curr=head;
        prev=NULL;
        reverseLinkedList(head,curr,prev);
        return head;






    }
};