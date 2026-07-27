class Solution {
public:
    int numberOfSubstrings(string s) {
        int n=s.size(),count=0,l=0,ans=0;
        vector<int>freq(3);
        for(int i=0;i<n;i++){
            freq[s[i]-'a']++;
            if(freq[s[i]-'a']==1) count++;
            while(count==3){
                ans+=(n-i);
                freq[s[l]-'a']--;
                if(freq[s[l]-'a']==0) count--;
                l++;
            }
        }

        return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna