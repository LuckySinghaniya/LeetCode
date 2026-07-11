class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n=nums.size();
        int sum=0;
        vector<int>presum(n+1);
        presum[n]=0;
        for(int i=n-1;i>=0;i--){
            sum+=nums[i];
            presum[i]=sum;
        }
        sum=0;
        for(int i=0;i<n;i++){
            if(presum[i+1]==sum) return i;
            sum+=nums[i];
        }
        return -1;
    }
};


// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna