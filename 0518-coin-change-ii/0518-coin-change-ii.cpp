class Solution {
public:
    int solve(int index,vector<int>& coins,int sum,int amount, vector<vector<int>>&dp){
        if(sum==amount) return 1;
        if(index<0 || sum>amount) return 0;
        if(dp[index][sum]!=-1) return dp[index][sum];
        int a=solve(index,coins,sum+coins[index],amount,dp);
        int b=solve(index-1,coins,sum,amount,dp);
        return dp[index][sum]=a+b;
    }
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,-1));
        return solve(n-1,coins,0,amount,dp);
    }
};