class Solution {
public:
    bool solve(vector<vector<char>>& grid,int i,int j,int ans,vector<vector<vector<int>>> &dp){
        if(i>=grid.size() || j>=grid[0].size()) return false;
        if(grid[i][j]=='(') ans++;
        else ans--;
        if(ans<0) return false;
        if(i==grid.size()-1 && j==grid[0].size()-1) return ans==0;
        if(dp[i][j][ans]!=-1) return dp[i][j][ans];
        return dp[i][j][ans]=solve(grid,i+1,j,ans,dp) || solve(grid,i,j+1,ans,dp);
        
    }
    bool hasValidPath(vector<vector<char>>& grid) {
        int m=grid.size(),n=grid[0].size();
        if((m+n-1)%2!=0) return false;
           vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(m+n+1, -1)));
           return solve(grid,0,0,0,dp);
    }
};