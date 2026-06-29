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
    ListNode* middle(ListNode* head){
        ListNode* slow=head;
        ListNode* fast=head->next;
        while(fast!=nullptr && fast->next!=nullptr){
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
    }
    ListNode* Merge(ListNode* lefthead,ListNode* righthead){
        ListNode* dummy=new ListNode(-1);
        ListNode* temp=dummy;
        ListNode* t1=lefthead;
        ListNode* t2=righthead;
        while(t1!=nullptr && t2!= nullptr){
            if(t1->val<t2->val){
                temp->next=t1;
                t1=t1->next;
            }
            else{
                temp->next=t2;
                t2=t2->next;
            }
            temp=temp->next;
        }
        if(t1!=nullptr){
            temp->next=t1;
        }
        if(t2!=nullptr){
            temp->next=t2;
        }
        return dummy->next;
}

ListNode* sortList(ListNode* head) {
    if(head==nullptr || head->next==nullptr) return head;
        ListNode* lefthead=middle(head);
        ListNode* righthead=lefthead->next;
        lefthead->next=nullptr;
        lefthead=head;
        lefthead=sortList(lefthead);
        righthead=sortList(righthead);
        return Merge(lefthead,righthead);
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna