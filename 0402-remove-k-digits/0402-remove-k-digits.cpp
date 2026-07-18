class Solution {
public:
    string removeKdigits(string num, int k) {
        if(k==num.size()) return "0";
        stack<int>st;
        int n=num.size();
        for(int i=0;i<n;i++){
            while(!st.empty() && st.top()>(num[i]-'0') && k>0){
                st.pop();
                k--;
            }
            st.push(num[i]-'0');
        }
        while(k>0){
            st.pop();
            k--;
        }
        string ans="";
        while(!st.empty()){
            char c=(st.top()+'0');
            ans+=c;
            st.pop();
        }
        reverse(ans.begin(), ans.end());

int i = 0;
while (i < ans.size() && ans[i] == '0')
    i++;

ans = ans.substr(i);

if (ans.empty())
    return "0";

return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna