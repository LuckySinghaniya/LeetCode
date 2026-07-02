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
    void generate(string& curr,int n){
        if(curr.size()==2*n){
            if(isvalid(curr)){
                ans.push_back(curr);
            }
            return;
        }
            curr.push_back('(');
            generate(curr,n);
            curr.pop_back();
            curr.push_back(')');
            generate(curr,n);
            curr.pop_back();
}

    vector<string> generateParenthesis(int n) {
        string curr="";
        generate(curr,n);
        return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna