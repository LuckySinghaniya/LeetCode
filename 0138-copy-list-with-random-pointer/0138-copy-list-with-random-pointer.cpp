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

class Solution {
public:
    void copynodes(Node* head){
        Node* temp=head;
        while(temp!=nullptr){
            Node* newnode=new Node(temp->val);
            newnode->next=temp->next;
            temp->next=newnode;
            temp=temp->next->next;
        }
    }
    void connectingrandon(Node* head){
        Node* temp=head;
        while(temp!=nullptr){
            Node* copynode=temp->next;
            if(temp->random) copynode->random=temp->random->next;
            else copynode->random=nullptr;
            temp=temp->next->next;
        }
    }
    Node* connectingnext(Node* head){
        Node* dummy=new Node(-1);
        Node* newhead=dummy;
        Node* temp=head;
        while(temp!=nullptr){
            dummy->next=temp->next;
            temp->next=temp->next->next;
            dummy=dummy->next;
            temp=temp->next;
        }
        return newhead->next;
    }
    Node* copyRandomList(Node* head) {
        copynodes(head);
        connectingrandon(head);
        return connectingnext(head);
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna