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
// class Solution {
// public:
//     ListNode* removeNthFromEnd(ListNode* head, int n) {
//         if(head==nullptr || head->next==nullptr) return nullptr;
//         ListNode* temp=head;
//         int count=0;
//         while(temp!=nullptr){
//             count++;
//             temp=temp->next;
//         }
//         count-=n;
//         if(count==0){
//             head=head->next;
//             return head;
//         }
//         temp=head;
//         while(count>1){
//             temp=temp->next;
//             count--;
//         }
//         temp->next=temp->next->next;
//         return head;
//     }
// };

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* fast=head;
        ListNode* slow=head;
        for(int i=0;i<n;i++){
            fast=fast->next;
        }
        if(fast==nullptr){
            head=head->next;
            return head;
        }
        while(fast->next!=nullptr){
            slow=slow->next;
            fast=fast->next;
        }
        ListNode* nodedelete=slow->next;
        slow->next=slow->next->next;
        delete nodedelete;
        return head;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna