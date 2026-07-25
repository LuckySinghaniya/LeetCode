class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.size();
        int count=0;
        unordered_map<char,int>mp;
        int l=0,r=0;
        while(r<n){
            if(mp.find(s[r])!=mp.end()){
                l=max(l,mp[s[r]]+1);
            }
            count=max(count,r-l+1);
            mp[s[r]]=r;
            r++;
        }
       return count;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna