class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return true;
        int final=n-1;
        for(int i=n-2;i>=0;i--){
            if((final-i)-nums[i]<=0){
                final=i;
            }
            if(i==0 && final-i-nums[i]<=0) return true;
        }
        return false;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna