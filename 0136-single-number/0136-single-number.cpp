class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int num=0;
        for(int i=1;i<nums.size();i++){
            nums[i]=nums[i]^nums[i-1];
        }
        return nums[nums.size()-1];
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna