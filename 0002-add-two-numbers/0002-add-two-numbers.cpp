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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* temp1=l1;
        ListNode* temp2=l2;
        ListNode* head= new ListNode();
        ListNode* curr=head;
        int remender=0;
        while(temp1!=nullptr || temp2!=nullptr){
            int x = (temp1 ? temp1->val : 0);
            int y = (temp2 ? temp2->val : 0);
            int sum = x + y + remender;
            if(sum/10==0){
                if(temp1==l1){
                    head->val=sum;
                }
                else{
                    ListNode* temp = new ListNode(sum);
                    curr->next=temp;
                    curr=temp;
                    remender=0;
                }
            }
            else{
                if(temp1==l1){
                    head->val=sum%10;
                    remender=1;
                }
                else{
                    ListNode* temp = new ListNode(sum%10);
                    curr->next=temp;
                    curr=temp;
                    remender=1;
                }
            }
            if (temp1!=nullptr) temp1=temp1->next;
            if (temp2!=nullptr) temp2=temp2->next;
        }
        if(remender==1){
            ListNode* temp = new ListNode(1);
                curr->next=temp;
                curr=temp;
        }
        return head;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna