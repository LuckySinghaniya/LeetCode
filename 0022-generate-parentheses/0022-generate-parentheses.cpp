class Solution {
    public:
    vector<string>ans;
    bool isvalid(string str){
        int x=0;
        for(int i=0;i<str.size();i++){
            if(str[i]=='(') x++;
            else x--;
            if(x<0) return false;
        }
        return x==0;
    }
    void generate(string& curr,int n,int open,int close){
        if(curr.size()==2*n){
            ans.push_back(curr);
            return;
        }
            if(open<n){
                curr.push_back('(');
                open++;
            generate(curr,n,open,close);
            curr.pop_back();
            open--;
            }
            if(close<open){
                curr.push_back(')');
                close++;
            generate(curr,n,open,close);
            curr.pop_back();
            close--;
            }
            
}

    vector<string> generateParenthesis(int n) {
        string curr="";
        int open=0,close=0;
        generate(curr,n,open,close);
        return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna