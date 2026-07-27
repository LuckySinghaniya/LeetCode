class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        if(nums.size()==2){
            return (nums[0]-1)*(nums[1]-1);
        }
        return max((nums[0]-1)*(nums[1]-1),(nums[n-1]-1)*(nums[n-2]-1));
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna