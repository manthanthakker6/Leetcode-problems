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
    private:
    ListNode* getMiddle(ListNode* head){
        if(head==NULL){
            return head;
        }
        if(head->next==NULL){
            return head;
        }
         if(head->next->next==NULL){
            return head->next;
        }
        
            ListNode* fast=head->next;
            ListNode* slow=head;
            while(fast!=NULL){
                fast=fast->next;
                if(fast!=NULL){
                    fast=fast->next;
                }
                slow=slow->next;
        
            
        
        }
        return slow;

    }
    /*
    int getLength(ListNode* head){
        int len=0;
        while(head!=NULL){
            head=head->next;
            len++;
        }
        return len;
    }*/
public:
    ListNode* middleNode(ListNode* head) {
        return getMiddle(head);
        /*
       int length= getLength(head);
       int ans=length/2;
       ListNode* temp = head;
       int count=0;
       while(count<ans){
        temp=temp->next;
        count++;
       }
       return temp;


    }*/

    }};