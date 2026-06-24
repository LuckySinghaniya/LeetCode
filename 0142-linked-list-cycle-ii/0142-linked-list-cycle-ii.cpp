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
    ListNode *detectCycle(ListNode *head) {
        unordered_map<ListNode* , ListNode*>mp;
        int count=1;
        ListNode* temp=head;
        while(temp!=nullptr){
            if(mp.find(temp)!=mp.end()){
                return mp[temp];
            }
            else{
                mp[temp]=temp;
                temp=temp->next;
            }
        }
        return nullptr;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna