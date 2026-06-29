/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* collision(ListNode *headA, ListNode *headB,int d){
        while(d){
            headA=headA->next;
            d--;
        }
        while(headA!=headB){
            headA=headA->next;
            headB=headB->next;
        }
        return headA;
    }
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int n1=0,n2=0;
        ListNode* temp1=headA;
        ListNode* temp2=headB;
        while(temp1!=nullptr){
            n1++;
            temp1=temp1->next;
        }
        while(temp2!=nullptr){
            n2++;
            temp2=temp2->next;
        }
        int d=abs(n1-n2);
        if(n1>n2){
            return collision(headA,headB,d);
        }
        else{
            return collision(headB,headA,d);
        }
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna