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
    void insertAtTail(ListNode* &head, ListNode* &tail, int value) {
        ListNode* temp = new ListNode(value);
        if (head == NULL) {
            head = temp;
            tail = temp;
        } else {
            tail->next = temp;
            tail = temp;
        }
    }

public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* ansHead = NULL;
        ListNode* ansTail = NULL;
        int carry = 0;

        // Single loop to handle all cases (l1 remaining, l2 remaining, or leftover carry)
        while (l1 != NULL || l2 != NULL || carry != 0) {
            int val1 = (l1 != NULL) ? l1->val : 0;
            int val2 = (l2 != NULL) ? l2->val : 0;

            int sum = carry + val1 + val2;
            int digit = sum % 10;
            carry = sum / 10;

            insertAtTail(ansHead, ansTail, digit);

            if (l1 != NULL) l1 = l1->next;
            if (l2 != NULL) l2 = l2->next;
        }

        return ansHead;
    }
};