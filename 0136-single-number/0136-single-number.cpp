class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int num=0;
        for(int i=0;i<nums.size();i++){
            num=(num^nums[i]);
        }
        return num;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna