class Solution {
public:
    int solve(string &s,string &t,int index,int j,vector<vector<int>>&dp){
        if(j==t.size()) return 1;
        if(index==s.size()) return 0;
        if(dp[index][j]!=-1) return dp[index][j];
        int nottake=solve(s,t,index+1,j,dp);
        int take=0;
        if(s[index]==t[j]) take=solve(s,t,index+1,j+1,dp);
        return dp[index][j]=take+nottake;
    }
    int numDistinct(string s, string t) {
        int n=s.size();
        int m=t.size();
        int count=0;
        vector<vector<int>>dp(n,vector<int>(m+1,-1));
        return solve(s,t,0,0,dp);
    }
};
