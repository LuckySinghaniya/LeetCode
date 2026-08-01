class Solution {
public:
    bool solve(vector<int>& nums, int sum1, int sum2,
               int turn, int l, int r) {

        if (l > r) {
            return sum1 >= sum2;
        }

        if (turn == 0) {
            return solve(nums, sum1 + nums[l], sum2, 1, l + 1, r) ||
                   solve(nums, sum1 + nums[r], sum2, 1, l, r - 1);
        }

        return solve(nums, sum1, sum2 + nums[l], 0, l + 1, r) &&
               solve(nums, sum1, sum2 + nums[r], 0, l, r - 1);
    }

    bool predictTheWinner(vector<int>& nums) {
        return solve(nums, 0, 0, 0, 0, nums.size() - 1);
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna