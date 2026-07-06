class Solution {
public:
    int n,m;
    vector<vector<int>>direction{{1,0},{0,1},{-1,0},{0,-1}};
    bool find(int i,int j,vector<vector<char>>& board,string& word,int index){
        if(index==word.size()) return true;
        if(i<0 || i>=n || j<0 || j>=m||board[i][j]=='$') return false;
        if(board[i][j]!=word[index]) return false;

        char temp=board[i][j];
        board[i][j]='$';
        for(auto &d:direction){
            int i_=i+d[0];
            int j_=j+d[1];
            if(find(i_,j_,board,word,index+1)){
                board[i][j]=temp;
             return true;   
            } 
        }
        board[i][j]=temp;
        return false;

    }
    bool exist(vector<vector<char>>& board, string word) {
        n=board.size();
        m=board[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]==word[0] && find(i,j,board,word,0)){
                    return true;
                }
            }
        }
        return false;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna