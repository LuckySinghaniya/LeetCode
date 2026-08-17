class Solution {
public:
    bool solve(int index,int sum,int target,vector<int>&nums,vector<vector<int>>&dp){
        if(sum==target) return true;
        if(index<0 || sum>target) return false;
        if(dp[index][sum]!=-1) return dp[index][sum];
        int a=solve(index-1,sum+nums[index],target,nums,dp);
        int b=solve(index-1,sum,target,nums,dp);
        return dp[index][sum]=a||b;
    }
    bool canPartition(vector<int>& nums) {
        int sum=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            sum+=nums[i];
        }
        if(sum%2==1) return false;
        int target=sum/2;
        vector<vector<int>>dp(n,vector<int>(target+1,-1));
        return solve(n-1,0,target,nums,dp);
    }
};