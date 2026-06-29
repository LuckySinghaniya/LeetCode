class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;

        while (head) {
            ListNode* next = head->next;
            head->next = prev;
            prev = head;
            head = next;
        }

        return prev;
    }

    bool isPalindrome(ListNode* head) {
        if (!head || !head->next)
            return true;

        ListNode* slow = head;
        ListNode* fast = head;

        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* second = reverseList(slow->next);

        ListNode* first = head;
        ListNode* temp = second;

        while (temp) {
            if (first->val != temp->val) {
                reverseList(second);   // restore
                return false;
            }
            first = first->next;
            temp = temp->next;
        }

        reverseList(second); // restore

        return true;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna