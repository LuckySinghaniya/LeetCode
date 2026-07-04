class Solution {
public:
    void solve(vector<vector<int>>&ans,vector<int>&temp,int k,int index, int n){
        if(temp.size()==k){
            if(n==0){
            ans.push_back(temp);
            return;
            }
        }
        for(int i=index;i<=9;i++){
            temp.push_back(i);
            solve(ans,temp,k,i+1,n-i);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>>ans;
        vector<int>temp;
        solve(ans,temp,k,1,n);
        return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna