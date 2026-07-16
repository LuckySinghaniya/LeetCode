class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        int n=nums.size();
        vector<int>mx(n);
        mx[0]=nums[0];
        for(int i=1;i<n;i++){
            mx[i]=max(mx[i-1],nums[i]);
        }
        vector<int>prefixgcd(n);
        for(int i=0;i<n;i++){
            prefixgcd[i]=gcd(nums[i],mx[i]);
        }
        sort(prefixgcd.begin(),prefixgcd.end());
        long long sum=0;
        int left=0,right=n-1;
        while(left<right){
            sum+=gcd(prefixgcd[left],prefixgcd[right]);
            left++;
            right--;
        }
        return sum;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna