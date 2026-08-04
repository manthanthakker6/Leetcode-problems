/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/
/*
class Solution {
private:
void insertAtTail(Node* &head,Node* &tail,int d){
    Node* newNode = new Node(d);
    if(head==NULL){
        head=newNode;
        tail=newNode;
        return;
    }
    else{
        tail->next=newNode;
        tail=newNode;

    }
}    
public:
    Node* copyRandomList(Node* head) {
        Node* cloneHead=NULL;
        Node* cloneTail=NULL;
        Node* temp=head;

        while(temp!=NULL){
            insertAtTail(cloneHead,cloneTail,temp->val);
            temp=temp->next;
        }
        //Creating a map
        unordered_map<Node*,Node*>oldToNewNode;
        Node* originalNode=head;
        Node* cloneNode=cloneHead;
        while(originalNode!=NULL&& cloneNode!=NULL){
            oldToNewNode[originalNode]=cloneNode;
            originalNode=originalNode->next;
            cloneNode=cloneNode->next;
        } 
        originalNode=head;
        cloneNode=cloneHead;
        while(originalNode!=NULL){
            cloneNode->random=oldToNewNode[originalNode->random];
            originalNode=originalNode->next;
            cloneNode=cloneNode->next;


        }
        return cloneHead;
    }
}; */
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head == NULL) return NULL;

        // Step 1: Insert clone nodes directly after each original node
        Node* curr = head;
        while (curr != NULL) {
            Node* nextNode = curr->next;
            Node* cloneNode = new Node(curr->val);
            curr->next = cloneNode;
            cloneNode->next = nextNode;
            curr = nextNode;
        }

        // Step 2: Copy the random pointers
        curr = head;
        while (curr != NULL) {
            if (curr->random != NULL) {
                curr->next->random = curr->random->next;
            }
            curr = curr->next->next;
        }

        // Step 3: Restore the original list and extract the cloned list
        curr = head;
        Node* cloneHead = head->next;
        Node* cloneCurr = cloneHead;
        
        while (curr != NULL) {
            curr->next = cloneCurr->next;
            curr = curr->next;
            if (curr != NULL) {
                cloneCurr->next = curr->next;
                cloneCurr = cloneCurr->next;
            }
        }

        return cloneHead;
    }
};