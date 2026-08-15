class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int l=0,count=0,temp=0,n=nums.size(),z=0;
        for(int i=0;i<n;i++){
            if(nums[i]==0) z++;
            temp^=nums[i];
        }
        if(z==n) return 0;
        if(temp==0) return n-1;
        return n;
    }
};