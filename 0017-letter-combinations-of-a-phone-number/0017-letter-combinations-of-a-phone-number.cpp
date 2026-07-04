class Solution {
public:
    void solve(string digits,vector<string>& ans,unordered_map<char,string>& freq, string temp,int index){
        if(temp.size()==digits.size()){
            ans.push_back(temp);
            return;
        }
        for(int i=0;i<freq[digits[index]].size();i++){
            solve(digits,ans,freq,temp+freq[digits[index]][i],index+1);
        }
    }
    vector<string> letterCombinations(string digits) {
        if(digits.size()==0){
            return {};
        }
        unordered_map<char,string>freq{{'2',"abc"},{'3',"def"},{'4',"ghi"},{'5',"jkl"},{'6',"mno"},{'7',"pqrs"},{'8',"tuv"},{'9',"wxyz"}};
        vector<string>ans;
        string temp="";
        solve(digits,ans,freq,temp,0);
        return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna