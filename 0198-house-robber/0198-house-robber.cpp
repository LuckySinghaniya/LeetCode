class Solution {
public:
    int solve(int index,vector<int>& nums,vector<int>&dp){
        int n=nums.size();
        int prev2=0;
        int prev=nums[0];
        for(int i=1;i<n;i++){
            int take=nums[i];
            if(i>1) take+=prev2;
            int nottake=prev;
            int curr=max(take,nottake);
            prev2=prev;
            prev=curr;
        }
        return prev;
        // dp[0]=nums[0];
        // for(int i=1;i<n;i++){
        //     int take=nums[i];
        //     if(i>1) take+=dp[i-2];
        //     int  nottake=0+dp[i-1];
        //     dp[i]=max(take,nottake);
        // }
        // return dp[n-1];
        // if(index==0) return nums[index];
        // if(index<0) return 0;
        // if(dp[index]!=-1) return dp[index];
        // int fs=solve(index-1,nums,dp);
        // int ss=nums[index] + solve(index-2,nums,dp);
        // return dp[index]=max(fs,ss);
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n,-1);
        return solve(n-1,nums,dp);
    }
};