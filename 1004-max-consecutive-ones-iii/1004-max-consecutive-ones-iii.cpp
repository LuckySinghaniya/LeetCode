class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int l=0,r=0,count=0,zeros=0,index=-1;
        while(r<nums.size()){
            if(nums[r]==0) zeros++;
            if(zeros>k){
                if(nums[l]==0) zeros--;
                l++;
            } 
            if(zeros<=k){
                count=max(count,r-l+1);
            }
            r++;
        }
        return count;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna