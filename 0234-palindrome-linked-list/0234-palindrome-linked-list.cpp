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
    ListNode* getMid(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head->next;
        
        while (fast != NULL && fast->next != NULL) {
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow;
    }

    ListNode* reverse(ListNode* head) {
        ListNode* curr = head;
        ListNode* prev = NULL;
        ListNode* next = NULL;
        while (curr != NULL) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }

public:
    bool isPalindrome(ListNode* head) {
        if (head == NULL || head->next == NULL) {
            return true;
        }

        
        ListNode* middle = getMid(head);

      
        ListNode* temp = middle->next;
        middle->next = reverse(temp);

        
        ListNode* head1 = head;
        ListNode* head2 = middle->next;

        bool isPalindrome = true;
        while (head2 != NULL) {
            if (head1->val != head2->val) {
                isPalindrome = false;
                break;
            }
            head1 = head1->next;
            head2 = head2->next;
        }

       
        temp = middle->next;
        middle->next = reverse(temp);

        return isPalindrome;
    }
};
 
 /* This is the first approach which uses vector to copy contents of
     a linked list and then apply approach by placing one pointer at
     start and one at end incrementing start and decrementing end
 #include<vector>
class Solution {
    private:
    bool checkPalindrome(vector<int>&arr){
        int n=arr.size();
        int s=0;
        int e=n-1;
        while(s<=e){
            if(arr[s]!=arr[e]){
                return 0;
            }
            s++;
            e--;
        }
        return 1;
    }
    
public:
    bool isPalindrome(ListNode* head) {
       vector<int> arr;
       ListNode* temp=head;
       while(temp!=NULL){
        arr.push_back(temp->val);
        temp=temp->next;
       }
       return checkPalindrome(arr);
    }
}; */