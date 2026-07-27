class Solution {
public:
    int solve(vector<int>& nums, int goal){
        if(goal<0) return 0;
        int l=0,r=0,n=nums.size();
        int sum=0,count=0;
        while(r<n){
            sum+=nums[r];
            while(sum>goal){
                sum-=nums[l];
                l++;
            }
            count+=(r-l+1);
            r++;
        }
        return count;
    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int a=solve(nums,goal);
        int b=solve(nums,goal-1);

        
        return a-b;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna