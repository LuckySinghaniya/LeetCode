class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n=nums.size();
        int maxele=*max_element(nums.begin(),nums.end());
        int t=1;
        while(t<=maxele){
            t<<=1;
        }
        vector<bool>s1(t,false);
        vector<bool>s2(t,false);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                s1[nums[i]^nums[j]]=true;
            }
        }
        for(int i=0;i<t;i++){
            for(int j=0;j<n;j++){
                if(s1[i]){
                    s2[i^nums[j]]=true;;
                }
            }
        }
        int count=0;
        for(int i=0;i<t;i++){
            if(s2[i]){
                count++;
            }
        }
        return count;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna