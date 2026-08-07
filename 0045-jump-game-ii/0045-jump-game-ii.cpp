class Solution {
public:
    int jump(vector<int>& nums) {
        int n=nums.size();
        int l=0,r=0,count=0,jumps=0;
        while(r<n-1){
            int farthest=0;
            for(int i=l;i<=r;i++){
                farthest=max(farthest,i+nums[i]);
            }
            l=r;
            r=farthest;
            jumps++;
        }
        return jumps;

    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna