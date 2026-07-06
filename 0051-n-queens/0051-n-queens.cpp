class Solution {
public:
    vector<vector<string>>ans;
    bool check(int row,int col,vector<string>& temp,int n){
        int duprow=row,dupcol=col;
        if(temp[row][col]=='Q') return false;
        while(row>=0 && col>=0){
            if(temp[row][col]=='Q') return false;
            row--;
            col--;
        }
        row=duprow;
        col=dupcol;
        while(col>=0){
            if(temp[row][col]=='Q') return false;
            col--;
        }
        row=duprow;
        col=dupcol;
        while(row<n && col>=0){
            if(temp[row][col]=='Q') return false;
            row++;
            col--;
        }
        return true;
    }
    void solve(int n,vector<string>& temp,int col){
        if(col==n){
            ans.push_back(temp);
            return;
        }
        for(int row=0;row<n;row++){
            if(check(row,col,temp,n)){
                temp[row][col]='Q';
                solve(n,temp,col+1);
                temp[row][col]='.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        string dot="";
        for(int i=0;i<n;i++){
            dot+='.';
        }
        vector<string>temp;
        for(int i=0;i<n;i++){
            temp.push_back(dot);
        }
        solve(n,temp,0);
        return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna