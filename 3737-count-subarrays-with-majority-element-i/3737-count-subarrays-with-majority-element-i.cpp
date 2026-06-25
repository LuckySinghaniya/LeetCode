class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target) {
        int n=nums.size(),count=0,ans=0;;
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                if(nums[j]==target){
                    count++;
                }
                if(count>(j-i+1)/2){
                    ans++;
                }
            }
            count=0;
        }
        return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna