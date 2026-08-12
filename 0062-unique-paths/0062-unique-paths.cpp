class Solution {
public:
    int solve(int x,int y,int m,int n,vector<vector<int>>&dp){
        if(x==m-1 && y==n-1){
            return 1;
        }
        if(x>m-1 || y>n-1) return 0;
        if(dp[x][y]!=-1) return dp[x][y];
        int a=solve(x+1,y,m,n,dp);
        int b=solve(x,y+1,m,n,dp);
        return dp[x][y]=a+b;
    }
    int uniquePaths(int m, int n) {
        int x=0,y=0;
        vector<vector<int>>dp(m,vector<int>(n,-1));
        return solve(x,y,m,n,dp);
    }
};