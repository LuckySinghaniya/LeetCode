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
    ListNode* reverseList(ListNode* head) {
        if(head==nullptr || head->next==nullptr) return head;
        ListNode* back=nullptr;
        ListNode* curr=head;
        ListNode* front=head->next;
        while(curr!=nullptr){
            if(curr==head){
                back=curr;
                curr=curr->next;
                back->next=nullptr;
                front=front->next;
            }
            else{
                curr->next=back;
                back=curr;
                curr=front;
                head=back;
                if(front!=nullptr) front=front->next;
            }
        }
        return head;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna