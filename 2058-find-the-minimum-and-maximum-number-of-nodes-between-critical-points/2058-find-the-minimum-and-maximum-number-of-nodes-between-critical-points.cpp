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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
    vector<int>ans(2);
    ans[0]=-1,ans[1]=-1;
    if(head->next==nullptr || head->next->next==nullptr) return ans;
    int minimum=INT_MAX,first=-1,last=-1,curr=-1;
    int i=1;
    ListNode* temp=head->next;
    int value=head->val;
    while(temp->next!=nullptr){
        i++;
        if(value>temp->val && temp->val<temp->next->val || value<temp->val && temp->val>temp->next->val){
            if(first==-1){
                first=i;
                curr=i;
            }
            else{
                last=i;
                minimum=min(minimum,i-curr);
                curr=i;
            }
        }
        value=temp->val;
        temp=temp->next;
    }
    if(first==-1 || last==-1) return{-1,-1}; 
    ans[0]=minimum;
    ans[1]=last-first;
    return ans;
    }
};