class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char,int>mp;
        int l=0,r=0,count=0,maxfreq=0,n=s.size();
        while(r<n){
            mp[s[r]]++;
            maxfreq=max(maxfreq,mp[s[r]]);
            int num=(r-l+1)-maxfreq;
            if(num<=k){
                count=max(count,r-l+1);
            }
            else{
                mp[s[l]]--;
                if(mp[s[l]]==0) mp.erase(s[l]);
                l++;
            }
            r++;
        }
        return count;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna